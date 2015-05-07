//C04: cppcheck.cpp
//Configures  .h & .cpp files  to confirm to style
//standard.Tests existing files for conformance.
#include <fstream>
#include <sstream>
#include <cstddef>

using namespace std;

bool startsWith(const string& base, const string& key)
{
	return (base.compare(0, key.size(), key) == 0);
}

void cppCheck(const string& filename)
{
	enum bufs{ BASE, HEADER, IMPLEMENT,HLINE1,GUARD1,GUARD2,GUARD3,CPPLINE1,INCLUDE,BUFNUM};
	string part[BUFNUM];
	part[BASE] = filename;
	// Find any '.' in the string
	size_t loc = part[BASE].find('.');
	if(loc != string::npos)
		part[BASE].erase(loc); //Strip extension
	// force to uppercase
	for(size_t i = 0;i<part[BASE].size();++i)
		part[BASE][i] = toupper(part[BASE][i]);
	// Create file names and internal lines
	part[HEADER] = part[BASE] + ".h";
	part[IMPLEMENT] = part[BASE] + ".cpp";
	part[HLINE1] = "//" ":" + part[HEADER];
	part[GUARD1] = "#ifndef " + part[HEADER] + "_H";
	part[GUARD2] = "#define " + part[HEADER] + "_H";
	part[GUARD3] = "#endif //" + part[HEADER] + "_H";
	part[CPPLINE1] = string("//")+":" + part[IMPLEMENT];
	part[INCLUDE] = "#include \"" + part[HEADER] + "\"";
	//firsts try to open existing files
	ifstream existh(part[HEADER].c_str()),
		existcpp(part[IMPLEMENT].c_str());
	if( !existh )
	{
		// Does't exist :Create it 
		ofstream newheader(part[HEADER].c_str());
		newheader<<part[HLINE1]<<endl;
		newheader<<part[GUARD1]<<endl;
		newheader<<part[GUARD2]<<endl;
		newheader<< part[GUARD3]<< endl;
	}
	else
	{
		stringstream hfile;// write and read
		ostringstream newheader; // write
		hfile<<existh.rdbuf();
		// Check that first	three lines conform 
		bool changed = false;
		string s;
		hfile.seekg(0);
		getline(hfile, s);
		bool lineUsed = false;
		// That call good() is for microsoft(later too)
		for(int line = HLINE1; hfile.good() && line <= GUARD2; ++line)
		{
			if( startsWith(s, part[line]) )
			{
				newheader<< s<<endl;
				lineUsed = true;
				if( getline(hfile, s) )
					lineUsed = false;
			}
			else
			{
				newheader<< part[line]<< endl;
				changed = true;
				lineUsed = false;
			}
		}

		//copy rest file
		if( !lineUsed )
		{
			newheader<< s <<endl;

			newheader<< hfile.rdbuf();
			//check for guard3
			string head = hfile.str();
			if( head.find(part[GUARD3]) == string::npos )
			{
				newheader<< part[GUARD3] << endl;
				changed = true;
			}

			// if there were changes ,overwrite file
			if(changed)
			{
				existh.close();
				ofstream newH(part[HEADER].c_str());
				newH<<"//@//\n" // change marker
					<<newheader.str();
			}
		}
	}// already exist verify it
		
	if( !existcpp )
	{
		ofstream newcpp( part[IMPLEMENT].c_str() );
		newcpp<< part[CPPLINE1]<< endl
			<<part[INCLUDE] <<endl;
	}// create cpp file
	else
	{
		stringstream cppfile;
		ostringstream newcpp;
		cppfile << existcpp.rdbuf();
		//Check that first two lines conform:
		bool changed = false;
		string s;
		cppfile.seekg(0);
		getline(cppfile, s);
		bool lineUsed = false;
		for (int line = 0;cppfile.good() && line < INCLUDE; ++line)
		{
			if ( startsWith(s, part[line]) )
			{
				newcpp << s <<endl;
				lineUsed = true;
				if( getline(cppfile, s) )
					lineUsed = false;
			}
			else
			{
				newcpp << part[line] << endl;
				changed = true;
				lineUsed = false;
			}
		}

		// copy rest of file 
		if(lineUsed)
			newcpp<< s <<endl;
		newcpp << cppfile.rdbuf();
		//if there were changes .overwrite file
		if( changed )
		{
			existcpp.close();
			ofstream newCPP( part[IMPLEMENT].c_str() );
			newCPP <<"//@//\n" // change marker
				<< newcpp.str();
		}
	}
}

int main(int argc, char* argv[])
{
	if( argc >1 )
	{
		cppCheck(argv[1]);
	}
	else
	{
		cppCheck("cppCheckTest.h");
	}
}///:~
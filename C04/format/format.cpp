#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define D(x) T << #x <<endl;x


// 测试分值
int main()
{
	//string name("fout");
	//ofstream fout( name.c_str() );
	//string sss("xuebingbing");
	//fout<<sss;
	//fout.close();

	//ofstream fout2("fout2");
	//fout2<<"xuebingbing";
	//fout2.close();
	//
	//return 0;

	ofstream T("format.out");
	D(int i = 47;)
	D(double f = 2300114.414159;)
	const char* s = "Is there any more?";
	D(T.setf(ios_base::unitbuf);)
	D(T.setf(ios_base::showbase);)
	D(T.setf(ios_base::uppercase | ios_base::showpos);)
	D(T << i << endl;)
	D(T.setf(ios_base::hex, ios_base::basefield);)
	D(T << i << endl;)
	D(T.setf(ios_base::oct, ios_base::basefield);)
	D(T << i << endl;)
	D(T.unsetf(ios_base::showbase);)
	D(T.setf(ios_base::dec, ios_base::basefield);)
	D(T.setf(ios::left, ios_base::adjustfield);)
	D(T.fill('0');)
	D(T<<"fill char:" << T.fill() <<endl; )
	D(T.width(10);)
	T << i << endl;
	D(T.setf(ios_base::right, ios_base::adjustfield);)
	D(T.width(10);)
	T << i << endl;
	D(T << i << endl;)// without width(10)

	D(T.unsetf(ios_base::showpos);)
	D(T.setf(ios_base::showpoint);)
	D(T<<"prec = "<< T.precision()<<endl;)
	D(T.setf(ios_base::scientific, ios_base::floatfield);)
	D(T<< endl << f<< endl;)
	D(T.unsetf(ios_base::uppercase);)
	D(T<< endl << f << endl;)
	D(T.setf(ios_base::fixed, ios::floatfield);)
	D(T<<f<<endl;)
	D(T.precision(20);)
	D(T<<"prec = "<<T.precision()<<endl;)
	D(T<<endl<<f<<endl;)
	D(T.setf(ios_base::scientific, ios_base::floatfield);)
	D(T<< endl << f << endl;)
	D(T.setf(ios_base::fixed, ios_base::floatfield);)
	D(T<< f<< endl;)

	D(T.width(10);)
	T<<s<<endl;
	D(T.width(40);)
	T<<s<<endl;
	D(T.setf(ios_base::left, ios_base::adjustfield);)
	D(T.width(40);)
	T<<s<<endl;

}

Creating a new branch is qucik and simple.
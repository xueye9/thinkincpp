#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

using namespace std;

char up(const char& c)
{
	 return toupper(c);
}

int main()
{
	string s = "the lazy fox jump the over river and then gone.";
	string res;
	res.resize(s.size());
	transform(s.begin(), s.end(), res.begin(), up);

	cout << "origin:" << s << endl;
	cout << "result:" << res << endl;

	int i = 0;
	cin >> i;
}

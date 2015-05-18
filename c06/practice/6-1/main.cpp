#include "gclock.h"
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	typedef list<clock_t> cls;
	typedef list<clock_t>::const_iterator clsit;
	cls ls(10);
	generate_n(ls.begin(), 10, clockGen());
	clsit it = ls.begin();
	++it; ++it; ++it;
	ls.erase(it);
	copy(ls.begin(), ls.end(), ostream_iterator<clock_t>(cout, "\n"));

	int i = 0;
	cin>>i;
}
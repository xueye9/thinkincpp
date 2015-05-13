//: C06 copyints4.cpp
// Uses a standard a funtion object and adaptor.

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
	int a[] = {10, 20, 30};
	const size_t SZ = sizeof(a) / sizeof(a[0]);
	remove_copy_if(a, a+SZ, ostream_iterator<int>(cout, "\n"), bind2nd( greater<int>(), 15));
}///:~
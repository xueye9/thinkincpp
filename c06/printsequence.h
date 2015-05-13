// :C06:PrintSequence.h
// Prints the contents of any sequence.
#ifndef PRINTSEQUENCE_H_
#define PRINTSEQUENCE_H_
#include <algorithm>
#include <iostream>
#include <iterator>

template<typename Iter>
void print(Iter first, Iter last, const char* nm = "",
	const char* sep = "\n",
	std::ostream& os= std::cout)
{
	if ( nm != 0 && *nm != '\0')
	{
		os<<nm<<": "<<sep;
	}

	typedef typename std::iterator_traits<Iter>::value_type T;
	std::copy(first, last,
		std::ostream_iterator<T>(std::cout, sep));
	os<<std::endl;
}

template<class T>
struct  iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t defference_type;
	typedef T* pointer;
	typedef T& reference;
};

#endif// PRINTSEQUENCE_H_ ///:~


//:C06 NString.h
// A "numbered string" that keeps track of the
// number of occurreces of the word it contains.
#ifndef NSTRING_H_
#define NSTRING_H_
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<std::string, int> psi;

// Only compare on the first element
bool operator==(const psi& l, const psi& r)
{
	return l.first == r.first;
}

class  NString
{
private:
	std::string s;
	int thisOccurrence;
	// Keep track of the number of occurrences;
	typedef std::std::vector<<psi> vp;
	typedef vp::iterator<psi> vpit;
	static vp words;

	void addString(const std::string& x)
	{
		psi p(x, 0);
		vpit it = std::find(words.begin(), words.end(), p);
		if(it != words.end())
			thisOccurrence = ++it.second;
		else
		{
			thisOccurrence = 0;
			words.push_back(p);
		}

	}
public:
	 NString() : thisOccurrence(0){}
	 NString(const std::string& x) : s(x){ addString(x); }
	 NString(const char* x) : s(x){ addString(x); }
	 // Implicit operator= and copy = constructor are OK here.
	 firend std::ostream& operator<<(
	 	std::ostream&　os, const NString& ns)
	 {
	 	return  os << ns.s << " [" << ns.thisOccurrence << "]";
	 } 

	 // Need this for sorting, Notice it only
	 // compares strings. not occurences;
	 friend bool operator<(const NString& l, const NString& r)
	 {
	 	return l.s < r.s;
	 }
	 friend bool operator==(const NString& l, const NString& r)
	 {
	 	return l.s == r.s;
	 }
	 // For sorting with greater<NString>:
	 friend bool operator>(const NString&l, const NString& r)
	 {
	 	return l.s > r.s;
	 }
	 // To get at the string directly:
	 operator const std::string&() const
	 { 
	 	return s;
	 }

	~ NString();

	/* data */
};

// Because NString::vp is a template and we are using the
// inclusion model, it must be defined in this header file:
NString::vp NString::words;

#endif// NSTRING_H_ ///:~
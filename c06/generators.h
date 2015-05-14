//: C06:Generator.h
// Different ways to fill sequences.
#ifndef GENERATORS_H_
#define GENERATORS_H_
#include <set>

// A generator that can skip over numbers;
class SkipGen
{
public:
	SkipGen(int s=0, int skip = 1):
	i(s), skp(skip){}
	int operator()()
	{
		int r = i;
		i += skp;
		return r;
	}

private:	
	int i;
	int skp;
};

// Generate unique random numbers form 0 to mod;
class URandGen
{
public:
	URandGen(int lim) : limit(lim){}
	int operator()()
	{
		while(true)
		{
			int i = int(std::rand()) % limit;
			if ( used.find(i) == used.end() )
			{
				used.insert(i);
				return i;
			}
		}
	}

private:
	std::set<int> used;
	int limit;
};

// Produces random characters
class CharGen
{
	static const char* source;
	static const int len;
public:
	char operator()()
	{
		return source[std::rand() % len];
	}
};

#endif//GENERATORS_H_ ///:~
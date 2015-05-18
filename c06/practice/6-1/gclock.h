#ifndef GCLOCK_H__
#define GCLOCK_H__

#include <ctime>

class clockGen
{
public:
	clockGen();
	~clockGen();

	clock_t operator()();
	
private:
	static int m_counter;
};

#endif // GCLOCK_H__
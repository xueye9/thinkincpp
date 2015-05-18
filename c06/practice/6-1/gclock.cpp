#include "gclock.h"

int clockGen::m_counter = 0;


clockGen::clockGen()
{

}

clockGen::~clockGen()
{

}

clock_t clockGen::operator()()
{
	clock_t now;
	now = clock();
	now += m_counter;
	++m_counter;
	return now;
}

// :C06Generators.cpp{0}
#include "generators.h"
const char* CharGen::source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";
const int CharGen::len = std::strlen(source);
///:~
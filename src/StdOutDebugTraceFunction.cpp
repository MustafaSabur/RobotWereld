#include "StdOutDebugTraceFunction.hpp"
#include <iostream>

void StdOutDebugTraceFunction::trace( const std::string& aText)
{
	std::cout << aText << std::endl;
}


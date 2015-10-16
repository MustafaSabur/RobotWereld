#ifndef MATH_HPP_
#define MATH_HPP_

#include "Config.hpp"

const double PI = 3.141592654;
const double ALMOST_ZERO = 0.000000000000001;

class Math
{
	public:
		static float toRadians( float aDegrees);
		static float toDegrees( float aRadian);

};
//	class Math

#endif // MATH_HPP_

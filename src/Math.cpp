#include "Math.hpp"

/**
 *
 */
/* static */float Math::toRadians( float aDegrees)
{
	return aDegrees * PI / 180.0;
}
/**
 *
 */
/* static */float Math::toDegrees( float aRadian)
{
	return aRadian * 180.0 / PI;
}

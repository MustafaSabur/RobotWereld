#include "Vector.hpp"
#include <cmath>
#include <sstream>
#include "Math.hpp"

/**
 *
 */
float Vector::getMagnitude()
{
	return std::sqrt( x * x + y * y);
}
/**
 *
 */
void Vector::normalise()
{
	float magnitude = getMagnitude();

	if (magnitude <= ALMOST_ZERO)
		magnitude = 1;
	x /= magnitude;
	y /= magnitude;

	if (std::fabs( x) < ALMOST_ZERO)
		x = 0.0;
	if (std::fabs( y) < ALMOST_ZERO)
		y = 0.0;

}
/**
 *
 */
Vector Vector::getNormalised()
{
	Vector vector( *this);
	vector.normalise();
	return vector;
}
/**
 *
 */
void Vector::reverse()
{
	x = -x;
	y = -y;
}
/**
 *
 */
Vector& Vector::operator+=( const Vector& aVector)
{
	x += aVector.x;
	y += aVector.y;

	return *this;
}
/**
 *
 */
Vector& Vector::operator-=( const Vector& aVector)
{
	x -= aVector.x;
	y -= aVector.y;

	return *this;
}
/**
 *
 */
Vector& Vector::operator*=( float aScalar)
{
	x *= aScalar;
	y *= aScalar;

	return *this;
}
/**
 *
 */
Vector& Vector::operator/=( float aScalar)
{
	x /= aScalar;
	y /= aScalar;

	return *this;
}
/**
 *
 */
Vector Vector::operator-()
{
	return Vector( -x, -y);
}
/**
 *
 */
std::string Vector::asString() const
{
	std::ostringstream os;

	os << "(" << x << "," << y << ")";

	return os.str();
}
/**
 *
 */
std::string Vector::asDebugString() const
{
	return asString();
}
/**
 *
 */
Vector operator+(	const Vector& lhs,
					const Vector& rhs)
{
	return Vector( lhs.x + rhs.x, lhs.y + rhs.y);
}
/**
 *
 */
Vector operator-(	const Vector& lhs,
					const Vector& rhs)
{
	return Vector( lhs.x - rhs.x, lhs.y - rhs.y);
}
/**
 *
 */
float operator*(	const Vector& lhs,
					const Vector& rhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}
/**
 *
 */
Vector operator*( 	float s,
					const Vector& rhs)
{
	return rhs * s;
}
/**
 *
 */
Vector operator*(	const Vector& lhs,
					float s)
{
	return Vector( lhs.x * s, lhs.y * s);
}
/**
 *
 */
Vector operator/(	const Vector& lhs,
					float s)
{
	return Vector( lhs.x / s, lhs.y / s);
}

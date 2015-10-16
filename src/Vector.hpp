#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "Config.hpp"
#include "Widgets.hpp"

class Vector
{
	public:
		/**
		 *
		 */
		Vector() :
						x( 0.0),
						y( 0.0)
		{
		}
		/**
		 *
		 */
		Vector( float anX,
				float anY) :
						x( anX),
						y( anY)
		{
		}
		/**
		 *
		 */
		Vector( const Point& aPoint1,
				const Point& aPoint2) :
						x( aPoint1.x - aPoint2.x),
						y( aPoint1.y - aPoint2.y)
		{
		}
		/**
		 *
		 */
		virtual ~Vector()
		{
		}
		/**
		 *
		 */
		float getMagnitude();
		/**
		 *
		 */
		void normalise();
		/**
		 *
		 */
		Vector getNormalised();
		/**
		 *
		 */
		void reverse();
		/**
		 *
		 */
		Vector& operator+=( const Vector& aVector);
		/**
		 *
		 */
		Vector& operator-=( const Vector& aVector);
		/**
		 *
		 */
		Vector& operator*=( float aScalar);
		/**
		 *
		 */
		Vector& operator/=( float aScalar);
		/**
		 *
		 */
		Vector operator-();

		/**
		 * @name Debug functions
		 */
		//@{
		/**
		 * Returns a 1-line description of the object
		 */
		virtual std::string asString() const;
		/**
		 * Returns a description of the object with all data of the object usable for debugging
		 */
		virtual std::string asDebugString() const;
		//@}

		// No need for accessors and mutators?
		float x;
		float y;
};
// class Vector

// Some global operators
Vector operator+(	const Vector& lhs,
					const Vector& rhs);
Vector operator-(	const Vector& lhs,
					const Vector& rhs);
float operator*(	const Vector& lhs,
					const Vector& rhs);

Vector operator*( 	float s,
					const Vector& rhs);
Vector operator*(	const Vector& lhs,
					float s);

Vector operator/(	const Vector& lhs,
					float s);

#endif // VECTOR_HPP_

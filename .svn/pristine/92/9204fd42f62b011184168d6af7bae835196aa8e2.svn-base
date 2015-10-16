#ifndef WALLSHAPE_HPP_
#define WALLSHAPE_HPP_

#include "Config.hpp"
#include "LineShape.hpp"
#include "Wall.hpp"

/**
 *
 */
class WallShape : public LineShape
{
	public:
		/**
		 *
		 */
		WallShape( 	WallPtr aWall,
					RectangleShapePtr aRectangleShape1,
					RectangleShapePtr aRectangleShape2);
		/**
		 *
		 */
		virtual ~WallShape();
		/**
		 * @name Type safe accessors and mutators
		 */
		//@{
		/**
		 * Type safe accessor
		 */
		WallPtr getWall() const;
		/**
		 * Type safe mutator
		 */
		void setWall( WallPtr aWall);
		//@}

		/**
		 *
		 */
		virtual void setSelectedAt( const Point& aPoint = DefaultPosition,
									bool aSelected = true);
		/**
		 * Return NULL if the point is inside an end point
		 */
		RectangleShapePtr hasEndPointAt( const Point& aPoint);
		/**
		 *
		 */
		bool hasEndPoint( RectangleShapePtr aRectangleShape);
		/**
		 *
		 */
		void updateEndPoint( RectangleShapePtr aRectangleShape);
		/**
		 * @name Pure virtual abstract Shape functions
		 */
		//@{
		/**
		 *
		 */
		virtual void draw( wxDC& dc);
		/**
		 *
		 * @param aPoint
		 * @return True if the point is in the shape
		 */
		virtual bool occupies( const Point& aPoint) const;
		//@}
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
	private:
};

#endif // WALLSHAPE_HPP_

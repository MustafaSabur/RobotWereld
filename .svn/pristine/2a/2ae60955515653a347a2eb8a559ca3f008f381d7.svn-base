#ifndef WAYPOINT_HPP_
#define WAYPOINT_HPP_

#include "Config.hpp"
#include "Widgets.hpp"
#include "ModelObject.hpp"
#include "Notifier.hpp"

class WayPoint;
typedef std::shared_ptr<WayPoint> WayPointPtr;

class WayPoint : 	public ModelObject
{
	public:
		/**
		 *
		 */
		WayPoint( const std::string& aName);
		/**
		 *
		 */
		WayPoint(	const std::string& aName,
					const Point& aPosition);
		/**
		 *
		 */
		virtual ~WayPoint();
		/**
		 *
		 */
		std::string getName() const
		{
			return name;
		}
		/**
		 *
		 */
		void setName( const std::string& aName);
		/**
		 *
		 */
		Size getSize() const;
		/**
		 *
		 */
		void setSize(	const Size& aSize,
						bool aNotifyObservers = true);
		/**
		 *
		 */
		Point getPosition() const
		{
			return position;
		}
		/**
		 *
		 */
		void setPosition(	const Point& aPosition,
							bool aNotifyObservers = true);
		/**
		 *
		 */
		Region getRegion() const;
		/**
		 *
		 */
		bool intersects( const Region& aRegion) const;
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
	protected:

	private:
		std::string name;

		Size size;Point position;

};

#endif // WAYPOINT_HPP_

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "Config.hpp"

#include "Widgets.hpp"
#include "AbstractAgent.hpp"
#include "Notifier.hpp"
#include "Observer.hpp"
#include "LaserDistanceSensor.hpp"
#include "SteeringActuator.hpp"
#include "Vector.hpp"
#include "AStar.hpp"
#include "Widgets.hpp"

#include <vector>
#include "Thread.hpp"

namespace MessageASIO
{
	class Message;
}
;

class Robot;
typedef std::shared_ptr<Robot> RobotPtr;

class Goal;
typedef std::shared_ptr<Goal> GoalPtr;

class Robot :	public AbstractAgent,
				public Observer,
				public std::enable_shared_from_this<Robot>
{
	public:
		/**
		 *
		 */
		Robot( const std::string& aName);
		/**
		 *
		 */
		Robot(	const std::string& aName,
				const Point& aPosition);
		/**
		 *
		 */
		virtual ~Robot();
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
		Vector getFront() const;
		/**
		 *
		 */
		void setFront(	const Vector& aVector,
						bool aNotifyObservers = true);
		/**
		 *
		 */
		float getSpeed() const;
		/**
		 *
		 */
		void setSpeed( float aNewSpeed);
		/**
		 *
		 */
		virtual void startActing();
		/**
		 *
		 */
		virtual void stopActing();
		/**
		 *
		 */
		Region getRegion() const;
		/**
		 *
		 */
		bool intersects( const Region& aRegion) const;
		/**
		 *
		 */
		Point getFrontLeft() const;
		/**
		 *
		 */
		Point getFrontRight() const;
		/**
		 *
		 */
		Point getBackLeft() const;
		/**
		 *
		 */
		Point getBackRight() const;
		/**
		 * @name Observer functions
		 */
		//@{
		/**
		 * A Notifier will call this function if this Observer will handle the notifications of that
		 * Notifier. It is the responsibility of the Observer to filter any events it is interested in.
		 *
		 */
		virtual void handleNotification();
		//@}
		/**
		 *
		 */
		const AStar& getAStar() const
		{
			return astar;
		}
		/**
		 *
		 */
		const std::vector< Vertex >& getPath() const
		{
			return path;
		}
		/**
		 *
		 */
		void startCommunicating();
		/**
		 *
		 */
		void stopCommunicating();
		/**
		 * If a request is handled, any response *must* be set in the Message argument!
		 */
		virtual void handleRequest( MessageASIO::Message& aMessage);
		/**
		 *
		 */
		virtual void handleResponse( MessageASIO::Message& aMessage);
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
		/**
		 *
		 */
		void drive();
		/**
		 *
		 */
		void calculateRoute(GoalPtr aGoal);
		/**
		 *
		 */
		bool arrived(GoalPtr aGoal);
		/**
		 *
		 */
		bool collision();
	private:
		std::string name;

		Size size;
		Point position;

		Vector front;
		float speed;

		AStar astar;
		std::vector< Vertex > path;

		bool stop;
		bool communicating;

		std::thread robotThread;
		mutable std::recursive_mutex robotMutex;
};

#endif // ROBOT_HPP_

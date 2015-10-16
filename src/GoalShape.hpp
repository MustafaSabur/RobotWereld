#ifndef GOALSHAPE_HPP_
#define GOALSHAPE_HPP_

#include "Config.hpp"
#include "WayPointShape.hpp"
#include "WayPoint.hpp"
#include "Goal.hpp"

/**
 *
 */
class GoalShape : public WayPointShape
{
	public:
		/**
		 *
		 */
		GoalShape( GoalPtr aGoal);
		/**
		 *
		 */
		virtual ~GoalShape();
		/**
		 * @name Type safe accessors and mutators
		 */
		//@{
		/**
		 * Type safe accessor
		 */
		GoalPtr getGoal() const;
		/**
		 * Type safe mutator
		 */
		void setGoal( GoalPtr aGoal);
		//@}
		/**
		 *
		 */
		virtual std::string getNormalColour() const
		{
			return "GREEN";
		}
		/**
		 *
		 */
		virtual std::string getSelectionColour() const
		{
			return "BLUE";
		}
		/**
		 *
		 */
		virtual std::string getActivationColour() const
		{
			return "BLACK";
		}
		;
		/**
		 * @name Observer functions
		 */
		//@{
		/**
		 * A Notifier will call this function if this Observer will handle the notifications of that
		 * Notifier. It is the responsibility of the Observer to filter any events it is interested in.
		 */
		virtual void handleNotification();
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

};

#endif // GOAL_HPP_

#ifndef ABSTRACTAGENT_HPP_
#define ABSTRACTAGENT_HPP_

#include "Config.hpp"

#include <memory>
#include <vector>
#include "ModelObject.hpp"
#include "Queue.hpp"

class AbstractSensor;
class AbstractStimulus;
class AbstractActuator;
class AbstractPercept;

class AbstractAgent : public ModelObject
{
	public:
		/**
		 *
		 */
		AbstractAgent();
		/**
		 *
		 */
		virtual ~AbstractAgent();
		/**
		 *
		 */
		virtual void attachSensor( 	std::shared_ptr< AbstractSensor > aSensor,
									bool attachSensorToAgent = false);
		/**
		 *
		 */
		virtual void attachActuator( 	std::shared_ptr< AbstractActuator > anActuator,
										bool attachActuatorToAgent = false);
		/**
		 *
		 */
		virtual void addPercept( std::shared_ptr< AbstractPercept > anAbstractPercept);
		/**
		 *
		 */
		virtual void startActing() = 0;
		/**
		 *
		 */
		virtual void stopActing() = 0;
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
		std::vector< std::shared_ptr< AbstractSensor > > sensors;
		std::vector< std::shared_ptr< AbstractActuator > > actuators;
		Queue< std::shared_ptr< AbstractPercept > > perceptQueue;

	private:
};

#endif // ABSTRACTAGENT_HPP_

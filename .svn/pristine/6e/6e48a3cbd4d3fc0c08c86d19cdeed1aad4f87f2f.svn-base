#ifndef ABSTRACTSENSOR_HPP_
#define ABSTRACTSENSOR_HPP_

#include "Config.hpp"

#include <memory>

#include "Thread.hpp"

class AbstractAgent;

class AbstractStimulus
{
	public:
		/**
		 *
		 */
		virtual ~AbstractStimulus()
		{
		}
};
// class AbstractStimulus

class AbstractPercept
{
	public:
		/**
		 *
		 */
		virtual ~AbstractPercept()
		{
		}
};
//	class AbstractPercept

class AbstractSensor
{
	public:
		/**
		 *
		 */
		AbstractSensor();
		/**
		 *
		 */
		AbstractSensor( AbstractAgent* anAgent);
		/**
		 *
		 */
		virtual ~AbstractSensor();
		/**
		 * A sensor reads 10 stimuli/second (it sleeps for 100 ms) by default
		 */
		virtual void setOn( unsigned long aSleepTime = 100);
		/**
		 *
		 */
		virtual void setOff();
		/**
		 *
		 */
		virtual std::shared_ptr< AbstractStimulus > getStimulus() = 0;
		/**
		 *
		 */
		virtual std::shared_ptr< AbstractPercept > getPerceptFor( std::shared_ptr< AbstractStimulus > anAbstractPercepts) = 0;
		/**
		 *
		 */
		virtual void sendPercept( std::shared_ptr< AbstractPercept > anAbstractPercept);
		/**
		 *
		 */
		virtual void run( unsigned long aSleepTime);
		/**
		 *
		 */
		virtual void attachAgent( AbstractAgent* anAgent);
		/**
		 *
		 */
		virtual void detachAgent();
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
		AbstractAgent* agent;
		bool running;
		std::thread sensorThread;
		mutable std::recursive_mutex sensorMutex;

	private:
};
//	class AbstractSensor

#endif // ABSTRACTSENSOR_HPP_

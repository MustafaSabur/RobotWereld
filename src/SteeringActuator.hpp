#ifndef STEERINGACTUATOR_HPP_
#define STEERINGACTUATOR_HPP_

#include "Config.hpp"

#include "AbstractActuator.hpp"

class SteeringActuator : public AbstractActuator
{
	public:
		/**
		 *
		 */
		SteeringActuator();
		/**
		 *
		 */
		virtual ~SteeringActuator();
		/**
		 *
		 */
		virtual void handleCommand( AbstractCommand& anAbstractCommand);
};

#endif // STEERINGACTUATOR_HPP_

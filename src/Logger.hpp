#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "Config.hpp"

#include <string>

/**
 *
 */
class Logger
{
	public:
		/**
		 *
		 * @param aMessage
		 */
		static void log( const std::string& aMessage);
		/**
		 *
		 * @param aDisable
		 */
		static void setDisable( bool aDisable = true);
		/**
		 *
		 */
		static bool disable;
};

#endif /* LOGGER_HPP_ */

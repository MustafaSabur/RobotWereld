#ifndef COMMUNICATIONSERVICE_HPP_
#define COMMUNICATIONSERVICE_HPP_

#include "Config.hpp"

#include <boost/asio.hpp>
#include "Thread.hpp"

class Robot;

/*
 *
 */
class CommunicationService
{
	public:
		/**
		 *
		 */
		static CommunicationService& getCommunicationService();
		/**
		 *
		 */
		boost::asio::io_service& getIOService();
		/**
		 *
		 */
		void runRobotServer( 	Robot* aRobot,
								short aPort = 12345);
	private:
		/**
		 *
		 */
		CommunicationService();
		/**
		 *
		 */
		virtual ~CommunicationService();
		/**
		 *
		 */
		void runRobotServerWorker( 	Robot* aRobot,
									short aPort);
		/**
		 *
		 */
		std::thread robotCommunicationThread;
		/**
		 *
		 */
		boost::asio::io_service io_service;
};
// class CommunicationService

#endif // COMMUNICATIONSERVICE_HPP_

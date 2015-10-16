#include "CommunicationService.hpp"
#include "Server.hpp"
#include <iostream>

/**
 *
 */
/* static */CommunicationService& CommunicationService::getCommunicationService()
{
	static CommunicationService communicationService;
	return communicationService;
}
/**
 *
 */
boost::asio::io_service& CommunicationService::getIOService()
{
	return io_service;
}
/**
 *
 */
void CommunicationService::runRobotServer( 	Robot* aRobot,
											short aPort /* = 12345*/)
{
	std::thread newRobotCommunicationThread( [this,aRobot,aPort]
	{	runRobotServerWorker(aRobot,aPort);});
	robotCommunicationThread.swap( newRobotCommunicationThread);
}
/**
 *
 */
CommunicationService::CommunicationService()
{
}
/**
 *
 */
CommunicationService::~CommunicationService()
{
}
/**
 *
 */
void CommunicationService::runRobotServerWorker( 	Robot* aRobot,
													short aPort)
{
	try
	{
		// Create the server object. This must be alive while the program runs
		MessageASIO::Server server( getIOService(), aPort, aRobot);

		// Run the service until further notice
		getIOService().run();
	}

	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
	}

}


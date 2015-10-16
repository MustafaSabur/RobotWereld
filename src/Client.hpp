#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "Config.hpp"
#include <string>
#include "Message.hpp"
#include "Session.hpp"
#include "Robot.hpp"

namespace MessageASIO
{
	class Client
	{
		public:
			/**
			 *
			 */
			Client( boost::asio::io_service& an_io_service,
					const std::string& aHost,
					const std::string& aPort,
					RobotPtr aRobot) :
							io_service( an_io_service),
							host( aHost),
							port( aPort),
							robot( aRobot)
			{
			}
			/**
			 *
			 */
			~Client()
			{
			}
			/**
			 *
			 */
			void dispatchMessage( Message& aMessage)
			{
				// Create the session that will handle the next outgoing connection
				MessageASIO::ClientSession* session = new MessageASIO::ClientSession( aMessage, io_service, robot);

				// Build up the remote address to which we will connect
				boost::asio::ip::tcp::resolver resolver( io_service);
				boost::asio::ip::tcp::resolver::query query( boost::asio::ip::tcp::v4(), host, port);
				boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve( query);
				boost::asio::ip::tcp::endpoint endpoint = *endpoint_iterator;

				// Let the session handle any outgoing messages
				session->getSocket().async_connect( endpoint, boost::bind( &Client::handleConnect, this, session, boost::asio::placeholders::error));
			}
			/**
			 *
			 */
			void handleConnect( MessageASIO::ClientSession* aSession,
								const boost::system::error_code& error)
			{
				if (!error)
				{
					aSession->start();
				} else
				{
					delete aSession;
					throw std::runtime_error( __PRETTY_FUNCTION__ + std::string( ": ") + error.message());
				}
			}

		private:
			boost::asio::io_service& io_service;
			std::string host;
			std::string port;
			RobotPtr robot;
	};
} // namespace MessageASIO

#endif // CLIENT_HPP_

#ifndef SESSION_HPP_
#define SESSION_HPP_

#include "Config.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "Message.hpp"
#include "CommunicationService.hpp"
#include "Robot.hpp"

namespace MessageASIO
{
	/**
	 * A session is an encapsulation of a request/answer transaction sequence.
	 */
	class Session
	{
		public:
			Session( boost::asio::io_service& io_service) :
							socket( io_service)
			{
			}

			virtual ~Session()
			{
			}

			/**
			 * Handle the fact that the message is read. This function is called by the framework
			 * after the message (header + body) is read. Normally this is the only function
			 * that a Server/ClientSession has to implement.
			 */
			virtual void handleMessageRead( Message& aMessage) = 0;

			/**
			 * Handle the fact that the message is written. This function is called by the framework
			 * after the message (header + body) is written. Normally this is the only function
			 * that a Server/ClientSession has to implement.
			 */
			virtual void handleMessageWritten( Message& aMessage) = 0;

			// The following functions should be protected or private
			// but the friend template syntax is not very friendly....

			/**
			 * readMessage will read the message in 2 a-sync reads, 1 for the header and 1 for the body.
			 * After each read a callback will be called that should handle the stuff just read.
			 * After reading the full message handleMessageRead will be called
			 * whose responsibility it is to handle the message as a whole.
			 *
			 * @see handle_header_read
			 * @see handle_body_read
			 * @see handleMessageRead
			 */
			void readMessage()
			{
				Message aMessage;
				headerBuffer.resize( aMessage.getHeader().getHeaderLength());
				boost::asio::async_read( getSocket(), boost::asio::buffer( headerBuffer), boost::bind( &Session::handleHeaderRead, this, aMessage, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
			}

			/**
			 * This function is called after the header bytes are read.
			 */
			void handleHeaderRead( 	Message& aMessage,
									const boost::system::error_code& error,
									size_t UNUSEDPARAM(bytes_transferred))
			{
				if (!error)
				{
					aMessage.setHeader( std::string( headerBuffer.begin(), headerBuffer.end()));
					bodyBuffer.resize( aMessage.getHeader().getMessageLength());
					boost::asio::async_read( getSocket(), boost::asio::buffer( bodyBuffer), boost::bind( &Session::handleBodyRead, this, aMessage, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
				} else
				{
					delete this;
					throw std::runtime_error( __PRETTY_FUNCTION__ + std::string( ": ") + error.message());
				}
			}

			/**
			 * This function as called after the body bytes are read.
			 * Any error handling (throwing an exception ;-)) is done in this function and
			 * than the function with the same name but without the error is called.
			 */
			void handleBodyRead( 	Message& aMessage,
									const boost::system::error_code& error,
									size_t bytes_transferred)
			{
				if (!error)
				{
					aMessage.setBody( std::string( bodyBuffer.begin(), bodyBuffer.end()));
					handleMessageRead( aMessage, error, bytes_transferred);
				} else
				{
					delete this;
					// Throwing a exception goes wrong if a "stop" message is send it the (limited)
					// context of this example. If any "strange" things happen, enable the next line. A "end of file"
					// exception will happen on "normal" termination of the message exchange...

					//throw std::runtime_error(__PRETTY_FUNCTION__ + std::string(": ") + error.message());
				}
			}

			/**
			 * This function is called after both the header and body bytes are read.
			 */
			void handleMessageRead( Message& aMessage,
									const boost::system::error_code& error,
									size_t UNUSEDPARAM(bytes_transferred))
			{
				if (!error)
				{
					handleMessageRead( aMessage);
				} else
				{
					delete this;
					throw std::runtime_error( __PRETTY_FUNCTION__ + std::string( ": ") + error.message());
				}
			}

			/**
			 * writeMessage will write the message in 2 a-sync writes, 1 for the header and 1 for the body.
			 * After each write a callback will be called that should handle the stuff just read.
			 * After writing the full message handleMessageWritten will be called.
			 *
			 * @see handle_header_written
			 * @see handle_body_written
			 * @see handleMessageWritten
			 */
			void writeMessage( Message& aMessage)
			{
				boost::asio::async_write( getSocket(), boost::asio::buffer( aMessage.getHeader().toString(), aMessage.getHeader().getHeaderLength()), boost::bind( &Session::handleHeaderWritten, this, aMessage, boost::asio::placeholders::error));
			}

			/**
			 * This function is called after the header bytes are written.
			 */
			void handleHeaderWritten( 	Message& aMessage,
										const boost::system::error_code& error)
			{
				if (!error)
				{
					boost::asio::async_write( getSocket(), boost::asio::buffer( aMessage.getBody(), aMessage.length()), boost::bind( &Session::handleBodyWritten, this, aMessage, boost::asio::placeholders::error));
				} else
				{
					delete this;
					throw std::runtime_error( __PRETTY_FUNCTION__ + std::string( ": ") + error.message());
				}
			}

			/**
			 * This function is called after the body bytes are written.
			 */
			void handleBodyWritten( Message& aMessage,
									const boost::system::error_code& error)
			{
				if (!error)
				{
					handleMessageWritten( aMessage, error);
				} else
				{
					delete this;
					throw std::runtime_error( __PRETTY_FUNCTION__ + std::string( ": ") + error.message());
				}
			}

			/**
			 * This function is called after both the header and body bytes are written.
			 * Any error handling (throwing an exception ;-)) is done in this function and
			 * than the function with the same name but without the error is called.
			 */

			void handleMessageWritten( 	Message& aMessage,
										const boost::system::error_code& error)
			{
				if (!error)
				{
					handleMessageWritten( aMessage);
				} else
				{
					delete this;
					throw std::runtime_error( __PRETTY_FUNCTION__ + std::string( ": ") + error.message());
				}
			}

			boost::asio::ip::tcp::socket& getSocket()
			{
				return socket;
			}

		protected:
			boost::asio::ip::tcp::socket socket;
			std::vector< char > headerBuffer;
			std::vector< char > bodyBuffer;
	};
	// class Session

	class ServerSession : virtual public Session
	{
		public:
			ServerSession( 	boost::asio::io_service& io_service,
							Robot* aRobot) :
							Session( io_service),
							robot( aRobot)
			{
			}

			~ServerSession()
			{
			}

			virtual void start()
			{
				readMessage();
			}
			/**
			 * @see Session::handleMessageRead( Message& aMessage)
			 */
			virtual void handleMessageRead( Message& aMessage)
			{
				// This is the place where any request message from a client should
				// be handled
				robot->handleRequest( aMessage);

				// We now just echo the message. In real life we would write our own
				// response to the request.
				writeMessage( aMessage);

				// This is part of the original application. If one wants a stop message
				// just leave this here. Otherwise think something up yourself.
				if (aMessage.getBody() == "stop")
				{
					CommunicationService::getCommunicationService().getIOService().stop();
				}
			}
			/**
			 * @see Session::handleMessageWritten( Message& aMessage)
			 */
			virtual void handleMessageWritten( Message& UNUSEDPARAM(aMessage))
			{
				// This function
				delete this;
			}

		private:
			Robot* robot;

	};
	// class ServerSession

	class ClientSession : virtual public Session
	{
		public:
			ClientSession( 	Message aMessage,
							boost::asio::io_service& io_service,
							RobotPtr aRobot) :
							Session( io_service),
							message( aMessage),
							robot( aRobot)
			{
			}

			~ClientSession()
			{
			}

			virtual void start()
			{
				writeMessage( message);
			}

			/**
			 * @see Session::handleMessageRead( Message& aMessage)
			 */
			virtual void handleMessageRead( Message& aMessage)
			{
				// This is the place where any reply message from the server should
				// be handled
				robot->handleResponse( aMessage);

				delete this;
			}

			/**
			 * @see Session::handleMessageWritten( Message& aMessage)
			 */
			virtual void handleMessageWritten( Message& UNUSEDPARAM(aMessage))
			{
				// This *must* be the last function that is called after
				// sending a message because it will read the response...
				readMessage();
			}

		private:
			Message message;
			RobotPtr robot;
	};
//	class ClientSession

}// namespace MessageASIO

#endif // SESSION_HPP_

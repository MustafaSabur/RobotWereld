#ifndef MESSAGE_HPP__
#define MESSAGE_HPP__

#include "Config.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace MessageASIO
{
	struct Message
	{
			typedef std::string MessageBody;

			struct MessageHeader
			{
					MessageHeader() :
									messageType( 0),
									messageLength( 0)
					{
					}

					MessageHeader( 	char aMessageType,
									unsigned long aMessageLength) :
									messageType( aMessageType),
									messageLength( aMessageLength)
					{
					}

					MessageHeader( const std::string& aMessageHeaderBuffer) :
									messageType( 0),
									messageLength( 0)
					{
						fromString( aMessageHeaderBuffer);
					}

					std::string toString() const
					{
						std::ostringstream os;
						os << magicNumber1 << magicNumber2 << magicNumber3 << magicNumber4 << majorVersion << minorVersion << messageType << std::setw( 4) << messageLength;
						return os.str();
					}

					void fromString( const std::string& aString)
					{
						std::istringstream is( aString);
						char magic[4];
						char major;
						char minor;
						is >> magic[0] >> magic[1] >> magic[2] >> magic[3] >> major >> minor >> messageType >> std::setw( 4) >> messageLength;
					}

					unsigned long getHeaderLength() const
					{
						static size_t l = toString().length();
						return (unsigned long)l;
					}

					char getMessageType() const
					{
						return messageType;
					}

					unsigned long getMessageLength() const
					{
						return messageLength;
					}

					std::string asString() const
					{
						std::ostringstream os;
						os << magicNumber1 << magicNumber2 << magicNumber3 << magicNumber4 << " " << (int)majorVersion << " " << (int)minorVersion << " " << (int)messageType << " " << messageLength;
						return os.str();
					}

					static const char magicNumber1 = 'A';
					static const char magicNumber2 = 'S';
					static const char magicNumber3 = 'I';
					static const char magicNumber4 = 'O';
					static const char majorVersion = 1;
					static const char minorVersion = 0;
					char messageType;
					unsigned long messageLength;
			};

			Message() :
							messageType( 0)
			{
			}

			Message( char aMessageType) :
							messageType( aMessageType)
			{
			}

			Message( 	char aMessageType,
						const std::string& aMessage) :
							messageType( aMessageType),
							message( aMessage)
			{
			}

			Message( const Message& aMessage) :
							messageType( aMessage.messageType),
							message( aMessage.message)
			{
			}

			virtual ~Message()
			{
			}

			MessageHeader getHeader() const
			{
				return MessageHeader( messageType, message.length());
			}

			void setHeader( const MessageHeader& aHeader)
			{
				setMessageType( aHeader.messageType);
				message.resize( aHeader.messageLength);
			}

			char getMessageType() const
			{
				return messageType;
			}

			void setMessageType( char aMessageType)
			{
				messageType = aMessageType;
			}

			MessageBody getBody() const
			{
				return message;
			}

			void setBody( const std::string& aBody)
			{
				message = aBody;
			}

			unsigned long length() const
			{
				return message.length();
			}

			std::string asString() const
			{
				std::ostringstream os;
				os << getHeader().asString() << ":\t" << message;
				return os.str();
			}

			char messageType;
			MessageBody message;
	};

} // namespace MessageASIO

#endif // MESSAGE_HPP__

#pragma once

#include <string>
#include <exception>

namespace qjson
{
	namespace exception
	{
		class Exception : public std::exception
		{
		public:
			Exception( std::string message )
				: std::exception( message.c_str() )
			{
			}
		};
	}
}
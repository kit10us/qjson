#pragma once

#include <qjson/exception/Exception.h>

namespace qjson
{
	namespace exception
	{
		class InvalidCast : public Exception
		{
		public:
			InvalidCast( std::string & message )
				: Exception( message )
			{
			}
		};
	}
}
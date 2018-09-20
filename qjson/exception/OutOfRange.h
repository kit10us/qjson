#pragma once

#include <qjson/exception/Exception.h>

namespace qjson
{
	namespace exception
	{
		class OutOfRange : public Exception
		{
		public:
			OutOfRange( std::string & message )
				: Exception( message )
			{
			}
		};
	}
}
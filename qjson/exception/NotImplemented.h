#pragma once

#include <qjson/exception/Exception.h>

namespace qjson
{
	namespace exception
	{
		class NotImplemented : public Exception
		{
		public:
			NotImplemented()
				: Exception( "" )
			{
			}
		};
	}
}
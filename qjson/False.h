#pragma once
#include <qjson/Value.h>

namespace qjson
{
	class False : public Value
	{
	public:
		False();
		False( std::string & text );
		virtual ~False() {}

		bool GetValue() const;
		std::string ToString() const;
		std::string ToJSONString() const;

		Value::shared_ptr Clone() const override;
	};
}

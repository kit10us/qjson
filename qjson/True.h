#pragma once
#include <qjson/Value.h>

namespace qjson
{
	class True : public Value
	{
	public:
		True();
		True( std::string & text );
		virtual ~True() {}

		bool GetValue() const;
		std::string ToString() const;
		std::string ToJSONString() const;

		Value::shared_ptr Clone() const override;
	};
}

#pragma once
#include <qjson/Value.h>

/// See http://json.org/ for implementation details.
namespace qjson
{
	class Null : public Value
	{
	public:
		Null();
		Null(std::string & text);
		virtual ~Null() {}

		int* GetValue() const;
		std::string ToString() const;
		std::string ToJSONString() const;
		bool IsNullOrEmpty() const;

		Value::shared_ptr Clone() const override;
	};
}

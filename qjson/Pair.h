#pragma once
#include <qjson/Value.h>

namespace qjson
{
	class Pair
	{
	public:

		/// <summary>
		/// Creates a pair from text. Text will be modified with the remaining text.
		/// </summary>
		Pair(std::string & text);

		Pair( const Pair & pair );

		Pair( std::string name, Value::const_ptr value );
		Pair( std::string name, const Value & value );
		Pair( std::string name, std::string value );
		Pair( std::string name, const char * value );
		Pair( std::string name, int value );
		Pair( std::string name, double value );
		Pair( std::string name, bool value );

		virtual ~Pair() {}

		std::string GetName() const;
		Value::const_ptr GetValue() const;

		std::string ToString() const;
		std::string ToJSONString() const;

	private:
		std::string m_name;
		Value::shared_ptr m_value;
	};
}

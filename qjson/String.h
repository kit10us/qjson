#pragma once
#include <qjson/Value.h>

namespace qjson
{
	class String : public Value
	{
	public:
		String();

		/// <summary>
		/// Creates a string from text, assuming the text begins with ". Will modifiy the text, just leaving the left over bits.
		/// </summary>
		String( std::string & text );

		String( const std::string & text );

		virtual ~String() {}

		std::string GetValue() const;
		std::string ToString() const;
		std::string ToJSONString() const;

		Value::shared_ptr Clone() const override;
	private:
		std::string m_value;
	};
}

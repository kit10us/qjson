#pragma once
#include <qjson/Value.h>

namespace qjson
{
	class Number : public Value
	{
	public:
		/// <summary>
		/// Creates a number from text. Will modifiy the text, just leaving the left over bits.
		/// </summary>
		Number();
		Number(std::string & text);
		Number(double value);
		virtual ~Number() {}

		double GetValue() const;
		std::string ToString() const;
		std::string ToJSONString() const;
		double ToDouble() const;

		Value::shared_ptr Clone() const override;

	private:
		double m_value;
	};
}

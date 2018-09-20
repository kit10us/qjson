#pragma once
#include <string>
#include <memory>
			  
/// See http://json.org/ for implementation details.
namespace qjson
{
	enum class ValueType
	{
		String, 
		Number, 
		Object, 
		Array, 
		True, 
		False, 
		Null
	};

	std::string ToString( const ValueType type );
	ValueType FromString( std::string type );

	class Value
	{
	public:
		typedef std::shared_ptr< Value > shared_ptr;
		typedef std::shared_ptr< const Value > const_ptr;

		static bool BeginsWith( std::string a, std::string b );
		
		/// <summary>
		/// This function will return a value from text, removing it and associated white-space, modifying the original string.
		/// </summary>
		static std::shared_ptr< Value > MakeValue( std::string & text );

		/// <summary>
		/// This function will remove formatting white-space, modifying the original string.
		/// </summary>
		static void ConsumeWhiteSpaces( std::string & text );

	public:
		Value( const ValueType type );
		Value() {}
		virtual ~Value() {}


		ValueType GetType() const;
		void SetType( const ValueType type );

		virtual std::string ToJSONString() const;
		virtual std::string ToString() const;
		virtual bool ToBool() const;
		virtual double ToDouble() const;

		/// <summary>
		/// Enables generic testing if there is no value; null being literally no value, and array having no contents.
		/// </summary>
		virtual bool IsNullOrEmpty() const;

		virtual Value::shared_ptr Clone() const = 0;

	private:
		ValueType m_type;
	};
}

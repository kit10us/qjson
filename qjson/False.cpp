#include <qjson/False.h>
#include <qjson/exception/Exception.h>

using namespace qjson;

False::False()
	: Value( ValueType::False )
{
}

False::False( std::string & text )
	: Value( ValueType::False )
{
	ConsumeWhiteSpaces( text );

	if ( BeginsWith( text, "false" ) == false )
	{
		throw exception::Exception( "JSON False not well formed!" );
	}
	text.erase( 0, 5 );
}

bool False::GetValue() const
{
	return false;
}

std::string False::ToString() const
{
	return "false";
}

std::string False::ToJSONString() const
{
	return ToString();
}

Value::shared_ptr False::Clone() const
{
	return std::make_shared< False >();
}

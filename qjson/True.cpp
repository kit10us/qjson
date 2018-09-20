#include <qjson/True.h>
#include <qjson/exception/Exception.h>

using namespace qjson;

True::True()
	: Value( ValueType::True )
{
}

True::True( std::string & text )
	: Value( ValueType::True )
{
	ConsumeWhiteSpaces( text );

	if ( BeginsWith( text, "true" ) == false )
	{
		throw exception::Exception( "JSON True not well formed!" );
	}
	text.erase( 0, 4 );
}

bool True::GetValue() const
{
	return true;
}

std::string True::ToString() const
{
	return "true";
}

std::string True::ToJSONString() const
{
	return ToString();
}

Value::shared_ptr True::Clone() const
{
	return std::make_shared< True >();
}

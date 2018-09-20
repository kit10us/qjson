#include <qjson/Null.h>
#include <qjson/exception/Exception.h>

using namespace qjson;

Null::Null()
	: Value( ValueType::Null )
{
}

Null::Null( std::string & text )
	: Value( ValueType::Null )
{
	ConsumeWhiteSpaces( text );

	if ( BeginsWith( text, "null" ) == false )
	{
		throw exception::Exception( "JSON Null not well formed!" );
	}
	text.erase( 0, 4 );
}

int* Null::GetValue() const
{
	return nullptr;
}

std::string Null::ToString() const
{
	return "null";
}

std::string Null::ToJSONString() const
{
	return ToString();
}

bool Null::IsNullOrEmpty() const
{
	return true;
}

Value::shared_ptr Null::Clone() const
{
	return std::make_shared< Null >();
}



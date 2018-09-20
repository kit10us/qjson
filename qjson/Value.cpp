#include <qjson/Value.h>
#include <qjson/exception/NotImplemented.h>
#include <qjson/exception/InvalidCast.h>
#include <qjson/exception/Exception.h>
#include <qjson/String.h>
#include <qjson/Number.h>
#include <qjson/Object.h>
#include <qjson/Array.h>
#include <qjson/True.h>
#include <qjson/False.h>
#include <qjson/Null.h>

using namespace qjson;

std::string qjson::ToString( const ValueType type )
{
	switch( type )
	{
	case ValueType::String: return "String";
	case ValueType::Number: return "Number";
	case ValueType::Object: return "Object";
	case ValueType::Array: return "Array";
	case ValueType::True: return "True";
	case ValueType::False: return "False";
	case ValueType::Null: return "Null";
	default:
		throw 1;
	}
}

ValueType qjson::FromString( std::string type )
{
	if( _stricmp( "String", type.c_str() ) == 0 )
	{
		return ValueType::String;
	}
	else if( _stricmp( "Number", type.c_str() ) == 0 )
	{
		return ValueType::Number;
	}
	else if( _stricmp( "Object", type.c_str() ) == 0 )
	{
		return ValueType::Object;
	}
	else if( _stricmp( "Array", type.c_str() ) == 0 )
	{
		return ValueType::Array;
	}
	else if( _stricmp( "True", type.c_str() ) == 0 )
	{
		return ValueType::True;
	}
	else if( _stricmp( "False", type.c_str() ) == 0 )
	{
		return ValueType::False;
	}
	else if( _stricmp( "Null", type.c_str() ) == 0 )
	{
		return ValueType::Null;
	}
	else
	{
		throw 1;
	}
}

bool Value::BeginsWith( std::string a, std::string b )
{
	if( b.length() > a.length() )
	{
		return false;
	}

	for( size_t i = 0; i < b.length(); ++i )
	{
		if( b[i] != a[i] )
		{
			return false;
		}
	}
	return true;
}

void Value::ConsumeWhiteSpaces( std::string & text )
{
	while( text.length() > 0 && (text[0] == '\t' || text[0] == ' ' || text[0] == '\n' || text[0] == '\r') )
	{
		text.erase( 0, 1 );
	}
}
  
std::shared_ptr< Value > Value::MakeValue( std::string & text )
{
	ConsumeWhiteSpaces( text );

	std::shared_ptr< Value > value;

	// We can tell by the first character what the type will be...
	char c = text[ 0 ];
	if ( c == '"' )
	{
		value.reset( new String( text ) );
	}
	else if ( c == '{' )
	{
		value.reset( new Object( text ) );
	}
	else if ( c == '[' )
	{
		value.reset( new Array( text ) );
	}
	else if ( c == 't' )
	{
		value.reset( new True( text ) );
	}
	else if ( c == 'f' )
	{
		value.reset( new False( text ) );
	}
	else if ( c == 'n' )
	{
		value.reset( new Null( text ) );
	}
	else if ( c == '-' || ( text[ 0 ] >= '0' && text[0 ] <= '9' ) )
	{
		value.reset( new Number( text ) );
	}
	else
	{
		throw exception::Exception( "JSON Pair not well formed (" + text + "!" );
	}

	ConsumeWhiteSpaces( text );

	return value;
}

Value::Value( ValueType type )
	: m_type( type )
{
}

ValueType Value::GetType() const
{
	return m_type;
}

void Value::SetType( const ValueType type )
{
	m_type = type;
}

std::string Value::ToJSONString() const
{
	throw exception::NotImplemented();
}

std::string Value::ToString() const
{
	throw exception::InvalidCast("Attempted to cast " + qjson::ToString( m_type ) + " to a string!");
}

bool Value::ToBool() const
{
	throw exception::InvalidCast( "Attempted to cast " + qjson::ToString( m_type ) + " to a bool!" );
}

double Value::ToDouble() const
{
	throw exception::InvalidCast( "Attempted to cast " + qjson::ToString( m_type ) + " to a double!" );
}

/// <summary>
/// Enables generic testing if there is no value; null being literally no value, and array having no contents.
/// </summary>
bool Value::IsNullOrEmpty() const
{
	return false;
}

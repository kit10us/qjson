#include <qjson/Object.h>
#include <qjson/Null.h>
#include <algorithm>
#include <qjson/exception/Exception.h>
#include <qjson/exception/InvalidCast.h>
#include <cassert>


using namespace qjson;

Object::Object()
	: Value( ValueType::Object )
{
}

Object::Object( const Object & in )
	: Value( ValueType::Object )
	, m_members( in.m_members )
{
}

Object::Object( std::string & text )
	: Value( ValueType::Object )
{
	ConsumeWhiteSpaces( text );

	if ( text[ 0 ] != '{' )
	{
		throw exception::Exception( "JSON Object needs to beging with '{'!" );
	}

	text.erase( 0, 1 );

	ConsumeWhiteSpaces( text );

	// Parse pairs...
	while ( text.length() > 0 && text[ 0 ] != '}' )
	{
		m_members.push_back( Pair({ text }) );
		ConsumeWhiteSpaces( text );
		if ( text[ 0 ] == ',' )
		{
			text.erase( 0, 1 );
		}
	};

	if ( text[ 0 ] != '}' )
	{
		throw exception::Exception( "JSON Object needs to end with '}'!" );
	}

	text.erase( 0, 1 );
}


Object::Object( const std::list< Pair > & members )
	: Value( ValueType::Object )
{
	for( auto member : members )
	{
		m_members.push_back( Pair( member ) );
	}
}

Object::Object( const Pair & firstMember )
	: Value( ValueType::Object )
{
	m_members = std::list< Pair >{ firstMember };
}

Object::Object( std::string name, Value::shared_ptr value )
	: Value( ValueType::Object )
	, m_members( { Pair( name, value ) } )
{
}

Object::Object( std::string name, const Value & value )
	: Value( ValueType::Object )
	, m_members( { Pair( name, value ) } )
{
}

Object::Object( std::initializer_list< Pair > intList )
{
	for( auto pair : intList )
	{
		Add( pair );
	}
}

Object::Object( const Value & value )
	: Object( dynamic_cast< const Object & >(value).m_members )
{
}

Object::~Object()
{
}

Pair Object::Add( Pair p )
{
	m_members.push_back( p );
	return p;
}

Pair Object::Add( std::string name, Value::shared_ptr value )
{
	Pair pair( name, value.get() == nullptr ? Value::shared_ptr( new Null ) : value );
	return Add( pair );
}

const Pair & Object::operator[]( size_t index ) const
{
	int i = 0;
	for( auto & p : m_members )
	{
		if( i == index )
		{
			return p;
		}
		i++;
	}
	throw std::overflow_error( "Object index out of bounds!" );
}

bool Object::Has( std::string name ) const
{
	auto p = std::find_if( m_members.begin(), m_members.end(), [ name ]( const auto s ) { return s.GetName() == name; } );
	return  p != m_members.end();
}

const Value & Object::operator[]( std::string name ) const
{
	auto p = std::find_if( m_members.begin(), m_members.end(), [name]( const auto s ) { return s.GetName() == name; } );
	return * p->GetValue();
}

size_t Object::Count() const
{
	size_t count = 0;
	for( auto a : m_members )
	{
		count++;
	}
	return count;
}

std::string Object::ToString() const
{
	std::string output = "{";
	for( auto x : m_members )
	{
		if ( output.length() > 1 ) output += ",";
		output += x.ToString();
	}
	output += "}";
	return output;
}

std::string Object::ToJSONString() const
{
	return ToString();
}

Value::shared_ptr Object::Clone() const
{
	return std::make_shared< Object >( m_members );
}

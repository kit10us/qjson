#include <qjson/Array.h>
#include <qjson/exception/Exception.h>

using namespace qjson;

Array::Array()
	: Value( ValueType::Array )
{
}

Array::Array( const Array & arrayIn )
	: Value( ValueType::Array )
{
	for( auto element : arrayIn.m_elements )
	{
		m_elements.push_back( element->Clone() );
	}
}

Array::Array( const Value & firstValue )
	: Value( ValueType::Array )
{
	m_elements.push_back( firstValue.Clone() );
}

Array::Array( const std::list< Value::shared_ptr > & values )
	: Value( ValueType::Array )
{
	for( auto value : values )
	{
		m_elements.push_back( value->Clone() );
	}
}

Array::Array( const std::vector< Value::shared_ptr > & values )
	: Value( ValueType::Array )
{
	for( auto value : values )
	{
		m_elements.push_back( value->Clone() );
	}
}

Array::Array( std::string & text )
	: Value( ValueType::Array )
{
	if ( text.length() == 0 || text[ 0 ] != '[' )
	{
		throw exception::Exception( "JSON Array needs to beging with '['!" );
	}

	text.erase( 0, 1 );

	// Parse values...
	while ( text.length() > 0 && text[ 0 ] != ']' )
	{
		m_elements.push_back( Value::MakeValue( text ) );
		if ( text[ 0 ] == ',' )
		{
			text.erase( 0, 1 );
		}
	};

	if ( text[ 0 ] != ']' )
	{
		throw exception::Exception( "JSON Array needs to end with ']'!" );
	}
	text.erase( 0, 1 );
}

size_t Array::Count() const
{
	return m_elements.size();
}

std::string Array::ToString() const
{
	std::string output = "[";
	for( auto x : m_elements )
	{
		if ( output.length() > 1 ) output += ",";
		output += x->ToJSONString();
	} 
	output += "]";
	return output;
}

void Array::Add( const Value & value )
{
	m_elements.push_back( value.Clone() );
}

const Value & Array::operator[]( int index ) const
{
	return *m_elements[ index ];
}

std::string Array::ToJSONString() const
{
	return ToString();
}

bool Array::IsNullOrEmpty() const
{
	return m_elements.empty();
}

Value::shared_ptr Array::Clone() const
{
	return std::make_shared< Array >( this->m_elements );
}

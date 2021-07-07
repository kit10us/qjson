/*
 * QJson Library
 * https://github.com/kit10us/QJson
 * Copyright (c) 2002, Kit10 Studios LLC
 *
 * This file is part of QJson Library (a.k.a. QJson)
 *
 * QJson is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QJson is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QJson.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <qjson/Pair.h>
#include <qjson/exception/Exception.h>
#include <qjson/String.h>
#include <qjson/Number.h>
#include <qjson/True.h>
#include <qjson/False.h>
#include <qjson/Null.h>

using namespace qjson;

/// <summary>
/// Creates a pair from text. Text will be modified with the remaining text.
/// </summary>
Pair::Pair( std::string & text )
{
	m_name = String( text ).ToString();

	Value::ConsumeWhiteSpaces( text );

	if ( text[ 0 ] != ':' )
	{
		throw exception::Exception( "JSON Pair missing':'!" );
	}
	text.erase( 0, 1 );

	Value::ConsumeWhiteSpaces( text );

	m_value = Value::MakeValue( text );
}

Pair::Pair( const Pair & pair )
	: Pair( pair.GetName(), pair.GetValue() )
{
}

Pair::Pair( std::string name, Value::const_ptr value )
	: m_name( name )
	, m_value( value.get() == nullptr ? std::make_shared< Null >() : value->Clone() )
{
}

Pair::Pair( std::string name, const Value & value )
	: m_name( name )
	, m_value( value.Clone() )
{
}

Pair::Pair( std::string name, std::string value )
	: m_name( name )
	, m_value( std::make_shared< String >( value) )
{
}

Pair::Pair( std::string name, const char * value )
	: m_name( name )
	, m_value( std::make_shared< String >( std::string( value ) ) )
{
}

Pair::Pair( std::string name, double value )
	: m_name( name )
	, m_value( std::make_shared< Number >( value ) )
{
}

Pair::Pair( std::string name, int value )
	: m_name( name )
	, m_value( std::make_shared< Number >( value ) )
{
}

Pair::Pair( std::string name, bool value )
	: m_name( name )
{
	if( value == true )
	{
		m_value = std::make_shared< True >();
	}
	else
	{
		m_value = std::make_shared< False >();
	}
}

std::string Pair::GetName() const
{
	return m_name;
}

Value::const_ptr Pair::GetValue() const
{
	return m_value;
}

std::string Pair::ToString() const
{
	return "\"" + m_name + "\":" + m_value->ToJSONString();
}

std::string Pair::ToJSONString() const
{
	return ToString();
}

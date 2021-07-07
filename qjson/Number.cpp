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

#include <qjson/Number.h>
#include <qjson/exception/Exception.h>

using namespace qjson;

Number::Number()
	: Value( ValueType::Number )
{
}

Number::Number( std::string & text )
	: Value( ValueType::Number )
{
	ConsumeWhiteSpaces( text );

	size_t i = 0;
	for ( i = 0; i < text.length() && ( ( text[ i ] >= '0' && text[ i ] <= '9' ) || text[ i ] == '-' || text[ i ] == '+' || text[ i ] == 'e' || text[ i ] == 'E' || text[ i ] == '.' ); ++i )
	{
	}

	std::string temp(text.begin(), text.begin() + i);
	m_value = std::stod( temp );
	text.erase( 0, i );
}

Number::Number( double value )
	: Value( ValueType::Number )
{
	m_value = value;
}

double Number::GetValue() const
{
	return m_value;
}

std::string Number::ToString() const
{
	std::string out = std::to_string( m_value );
	if( out.find( ',' ) == out.length() )
	{
		return out;
	}

	size_t i = out.length() - 1;
	while( i > 0 && ( out[i] == '.' || out[i] == '0' ) )
	{
		if( out[i--] == '.' ) break;
	}
	out.erase( i + 1 );
	return out;
}

std::string Number::ToJSONString() const
{
	return ToString();
}

double Number::ToDouble() const
{
	return m_value;
}

Value::shared_ptr Number::Clone() const
{
	return std::make_shared< Number >( m_value );
}

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

#include <qjson/String.h>
#include <qjson/exception/Exception.h>

using namespace qjson;

std::string Replace( const std::string in, const std::string from, const std::string to )
{
	std::string out( in );
	size_t index = 0;
	while( true ) {
		index = out.find( from, index );
		if( index == std::string::npos ) break;

		out.replace( index, 3, to );

		index += to.length();
	}
	return out;
}


String::String()
	: Value( ValueType::String )
{
}

String::String( const std::string & text )
	: Value( ValueType::String )
{
	std::string tempText = text;
	*this = String( tempText );
}

String::String( std::string & text )
	: Value( ValueType::String )
{
	ConsumeWhiteSpaces( text );

	if( text[0] == '"' )
	{
		// Find the closing quote...
		size_t i = 1; // Skip first quote.
		bool inQuote = true;
		bool isEscaped = false; // allows us to skip the next characer, as it was escaped with \.
		while( inQuote && i < text.length() )
		{
			if( isEscaped == true )
			{
				isEscaped = false;
			}
			else
			{
				char c = text[i];
				if( c == '\\' )
				{
					isEscaped = true;
				}
				else if( c == '"' )
				{
					inQuote = false;
				}
			}
			++i;
		}

		if( i > 2 )
		{
			std::string temp( text.begin() + 1, text.begin() + i - 1 );
			m_value = temp;
		}
		else
		{
			m_value = "";
		}
		text.erase( 0, i );

		if( inQuote == true )
		{
			throw exception::Exception( "JSON String missing end quote (\")!" );
		}
	}
	else
	{
		m_value = text;
	}
}

std::string String::GetValue() const
{
	return m_value;
}

std::string String::ToString() const
{
	return m_value;
}

std::string String::ToJSONString() const
{
	return "\"" + ( m_value.empty() ? "" : ( Replace( Replace( Replace( Replace( ToString(), "\\", "\\\\" ), "\"", "\\\"" ), "\n", "\\n" ), "\r", "\\r" ) ) ) + "\"";
}

Value::shared_ptr String::Clone() const
{
	return std::make_shared< String >( m_value );
}


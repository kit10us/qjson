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



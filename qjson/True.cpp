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

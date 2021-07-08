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

#pragma once
#include <qjson/Value.h>

 /// See http://json.org/ for implementation details.
namespace qjson
{
	class Pair
	{
	public:

		/// <summary>
		/// Creates a pair from text. Text will be modified with the remaining text.
		/// </summary>
		Pair(std::string & text);

		Pair( const Pair & pair );

		Pair( std::string name, Value::const_ptr value );
		Pair( std::string name, const Value & value );
		Pair( std::string name, std::string value );
		Pair( std::string name, const char * value );
		Pair( std::string name, int value );
		Pair( std::string name, double value );
		Pair( std::string name, bool value );
		Pair(std::string name, nullptr_t);

		virtual ~Pair() {}

		std::string GetName() const;
		Value::const_ptr GetValue() const;

		std::string ToString() const;
		std::string ToJSONString() const;

	private:
		std::string m_name;
		Value::shared_ptr m_value;
	};
}

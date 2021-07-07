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
#include <string>
#include <memory>
			  
/// See http://json.org/ for implementation details.
namespace qjson
{
	enum class ValueType
	{
		String, 
		Number, 
		Object, 
		Array, 
		True, 
		False, 
		Null
	};

	std::string ToString( const ValueType type );
	ValueType FromString( std::string type );

	class Value
	{
	public:
		typedef std::shared_ptr< Value > shared_ptr;
		typedef std::shared_ptr< const Value > const_ptr;

		static bool BeginsWith( std::string a, std::string b );
		
		/// <summary>
		/// This function will return a value from text, removing it and associated white-space, modifying the original string.
		/// </summary>
		static std::shared_ptr< Value > MakeValue( std::string & text );

		/// <summary>
		/// This function will remove formatting white-space, modifying the original string.
		/// </summary>
		static void ConsumeWhiteSpaces( std::string & text );

	public:
		Value( const ValueType type );
		Value() {}
		virtual ~Value() {}


		ValueType GetType() const;
		void SetType( const ValueType type );

		virtual std::string ToJSONString() const;
		virtual std::string ToString() const;
		virtual bool ToBool() const;
		virtual double ToDouble() const;

		/// <summary>
		/// Enables generic testing if there is no value; null being literally no value, and array having no contents.
		/// </summary>
		virtual bool IsNullOrEmpty() const;

		virtual Value::shared_ptr Clone() const = 0;

	private:
		ValueType m_type;
	};
}

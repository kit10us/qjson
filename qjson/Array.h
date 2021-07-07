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
#include <list>
#include <vector>

/// See http://json.org/ for implementation details.
namespace qjson
{
	class Array : public Value
	{
	public:
		Array();
		Array( const Array & arrayIn );
		Array( const Value & firstValue );
		Array( const std::list< Value::shared_ptr > & values );
		Array( const std::vector< Value::shared_ptr > & values );
		Array( std::string & text );
		virtual ~Array() {}

		void Add( const Value & value );

		const Value & operator[]( int index ) const;

		size_t Count() const;

		std::string ToString() const;
		std::string ToJSONString() const;

		bool IsNullOrEmpty() const;

		Value::shared_ptr Clone() const override;

		class iterator
		{
		public:
			iterator( Array & array, size_t index )
				: m_array( array ), m_index( index )
			{
			}

			iterator & operator++()
			{
				m_index++;
				return *this;
			}

			bool operator!=( const iterator & itr ) const
			{
				return m_index != itr.m_index;
			}

			const Value & operator*()
			{
				return m_array[ (int)m_index ];
			}

		private:
			Array & m_array;
			size_t m_index;
		};

		iterator begin() {
			return iterator( *this, 0 );
		}
		iterator end() {
			return iterator( *this, Count() );
		}

	private:
		std::vector< Value::shared_ptr > m_elements;
	};
}

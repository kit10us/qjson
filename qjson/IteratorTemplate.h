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

 /// See http://json.org/ for implementation details.
namespace qjson
{
	template< class T >
	class IteratorTemplate
	{
	public:
		IteratorTemplate( T & thing, size_t index )
			: m_thing( thing ), m_index( index )
		{
		}

		IteratorTemplate & operator++()
		{
			m_index++;
			return *this;
		}

		bool operator!=( const IteratorTemplate<T> & itr ) const
		{
			return m_index != itr.m_index;
		}

		const Pair & operator*() const
		{
			return m_thing[m_index];
		}

	private:
		T & m_thing;
		size_t m_index;
	};

	template< class T >
	class ConstIteratorTemplate
	{
	public:
		ConstIteratorTemplate( const T & thing, size_t index )
			: m_thing( thing ), m_index( index )
		{
		}

		ConstIteratorTemplate & operator++()
		{
			m_index++;
			return *this;
		}

		bool operator!=( const ConstIteratorTemplate<T> & itr ) const
		{
			return m_index != itr.m_index;
		}

		const Pair & operator*() const
		{
			return m_thing[m_index];
		}

	private:
		const T & m_thing;
		size_t m_index;
	};
}
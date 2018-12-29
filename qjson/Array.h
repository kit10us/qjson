#pragma once
#include <qjson/Value.h>
#include <list>
#include <vector>

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

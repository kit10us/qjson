#pragma once 

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
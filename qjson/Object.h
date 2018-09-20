#pragma once
#include <qjson/Value.h>
#include <qjson/Pair.h>
#include <qjson/IteratorTemplate.h>
#include <list>

namespace qjson
{
	class Object : public Value
	{
	public:
		struct NameValuePair
		{
			std::string name;
			std::string value;
		};

		Object();
		Object( const Object & in );
		
		/// <summary>
		/// Consumption constructor will attempt to consume as much of the text as possible, only leaving the remaining text.
		/// </summary>
		Object( std::string & text );
		
		Object(const std::list< Pair > & members);
		Object(const Pair & firstMember);
		Object( std::string name, Value::shared_ptr value);
		Object( std::string name, const Value & value );
		Object( std::initializer_list< Pair > intList );
		
		/// Cast assuming Value is an Object );
		Object( const Value & value );

		virtual ~Object();

		Pair Add(Pair p);
		
		Pair Add(std::string name, Value::shared_ptr value);

		/// <summary>
		/// Access object pairs via index.
		/// </summary>
		const Pair & operator[]( size_t index ) const;

		bool Has( std::string name ) const;

		/// <summary>
		/// Access a pair's value by name.
		/// </summary>
		const Value & operator[](std::string name) const;

		size_t Count() const;

		std::string ToString() const;
		std::string ToJSONString() const;

		Value::shared_ptr Clone() const override;

		class iterator : public qjson::IteratorTemplate< Object > 
		{ 
		public: 
			iterator( Object & object, size_t index ) 
				: IteratorTemplate< Object >( object, index ) 
			{} 
		};

		iterator begin() {
			return iterator( *this, 0 );
		}
		iterator end() {
			return iterator( *this, Count() );
		}

		class const_iterator : public qjson::ConstIteratorTemplate< Object >
		{
		public:
			const_iterator( const Object & object, size_t index )
				: ConstIteratorTemplate< Object >( object, index )
			{}
		};

		const_iterator begin() const {
			return const_iterator( *this, 0 );
		}
		const_iterator end() const {
			return const_iterator( *this, Count() );
		}
	
	private:
		std::list< Pair > m_members;
	};
}

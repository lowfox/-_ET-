#pragma once
#include <cstdint>
#include <algorithm>
#include <string.h>
namespace ZhanU
{
	namespace Utility
	{
		template <class Char>
		size_t StringLength(const Char* string)
		{
			constexpr int32_t STRING_NULL = 0x00000000;

			size_t length = 0;

			for (; ::memcmp(&string[length], &STRING_NULL, sizeof(Char)) != 0; length += sizeof(Char));

			return length > 0 ? length / sizeof(Char) : 0;
		}
	}

	template <class Char>
	class StringIterator
	{
	private:

		Char* m_char;

	public:

		StringIterator(Char* ptr) :m_char(ptr) {}

		Char& operator*()
		{
			return (*m_char);
		}

		StringIterator& operator++()
		{
			m_char++;
			return *this;
		}

		bool operator!= (const StringIterator<Char>& right)
		{
			return m_char != right.m_char;
		}
	};

	template <class Char>
	class Basic_string
	{
	public:

		using iterator = StringIterator<Char>;

	private:

		size_t m_size;

		size_t m_capacity;

		Char* m_string;

	public:

		Basic_string() :m_size(0), m_capacity(15), m_string(new Char[16])
		{
			::memset(m_string, 0, sizeof(Char) * (15 + 1));
		}

		Basic_string(const Char* string) :m_size(Utility::StringLength(string)), m_capacity(Utility::StringLength(string)),m_string(new Char[Utility::StringLength(string) + 1])
		{
			::memcpy(m_string, string, sizeof(Char) * (Utility::StringLength(string) + 1));
		}

		~Basic_string()
		{
			if (m_size != 0) { delete[] m_string };
		}

		size_t size()const
		{
			return m_size;
		}

		size_t capacity()const
		{
			return m_capacity;
		}

		size_t length()const
		{
			return size();
		}

		bool empty()const
		{
			return size() == 0;
		}

		iterator begin()
		{
			return { m_string };
		}

		iterator end()
		{
			return { &m_string[size()] };
		}

		Basic_string<Char>& operator=(const Basic_string<Char>& right)
		{
			copy(right);
			return  *this;
		}

		Basic_string<Char>& operator+=(const Basic_string<Char>& right)
		{
			size_t newLength = size() + right.size();

			if (newLength > capacity())
			{
				Char* buf = new Char[newLength + 1];

				::memcpy(buf, m_string, size() * sizeof(Char));
				::memcpy(buf + size(), right.c_str(), (right.size() + 1) * sizeof(Char));

				delete[] m_string;
				m_string = buf;
				m_capacity = newLength;
			}
			else
			{
				::memcpy(m_string + size(), right.c_str(), (right.size() + 1) * sizeof(Char));
			}

			m_size = newLength;

			return *this;
		}

		bool operator==(const Basic_string<Char>& right)const
		{
			if (size() != right.size())
			{
				return false;
			}

			return ::memcmp(m_string, right.c_str(), sizeof(Char) * size()) == 0;
		}

		bool operator!=(const Basic_string<Char>& right)const
		{
			if (size() != right.size())
			{
				return true;
			}

			return ::memcmp(m_string, right.c_str(), sizeof(Char) * size()) != 0;
		}

		bool operator<(const Basic_string<Char>& right)const
		{
			size_t length = std::min(size(), right.size());

			return ::memcmp(c_str(), right.c_str(), sizeof(Char) * length) < 0;
		}

		bool operator>(const Basic_string<Char>& right)const
		{
			size_t length = std::min(size(), right.size());

			return ::memcmp(c_str(), right.c_str(), sizeof(Char) * length) > 0;
		}

		void copy(const Basic_string<Char>& src)
		{
			if (m_size != 0) { delete[] m_string };
			m_string = new Char[src.capacity() + 1];
			m_size = src.size();
			m_capacity = src.capacity();
			::memcpy(m_string, src.c_str(), (src.size() + 1) * sizeof(Char));
		}

		Char* c_str()
		{
			return m_string;
		}

		const Char* c_str()const
		{
			return m_string;
		}
	};

	using String = Basic_string<char>;
}

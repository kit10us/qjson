﻿/*
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
	class Number : public Value
	{
	public:
		/// <summary>
		/// Creates a number from text. Will modifiy the text, just leaving the left over bits.
		/// </summary>
		Number();
		Number(std::string & text);
		Number(double value);
		virtual ~Number() {}

		double GetValue() const;
		std::string ToString() const;
		std::string ToJSONString() const;
		double ToDouble() const;

		Value::shared_ptr Clone() const override;

	private:
		double m_value;
	};
}

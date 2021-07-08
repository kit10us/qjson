#include "pch.h"
#include <qjson/QJson.h>

TEST(ValueTypes, NullType) {
	qjson::Null _null;
	EXPECT_EQ(_null.GetType(), qjson::ValueType::Null);
	EXPECT_EQ(_null.GetValue(), nullptr);
	EXPECT_EQ(_null.ToString(), "null");
	EXPECT_EQ(_null.ToJSONString(), "null");
	EXPECT_EQ(_null.IsNullOrEmpty(), true);
}

TEST(ValueTypes, TrueType) {
	qjson::True _true;
	EXPECT_EQ(_true.GetType(), qjson::ValueType::True);
	EXPECT_EQ(_true.GetValue(), true);
	EXPECT_EQ(_true.ToString(), "true");
	EXPECT_EQ(_true.ToJSONString(), "true");
	EXPECT_EQ(_true.IsNullOrEmpty(), false);
}

TEST(ValueTypes, FalseType) {
	qjson::False _false;
	EXPECT_EQ(_false.GetType(), qjson::ValueType::False);
	EXPECT_EQ(_false.GetValue(), false);
	EXPECT_EQ(_false.ToString(), "false");
	EXPECT_EQ(_false.ToJSONString(), "false");
	EXPECT_EQ(_false.IsNullOrEmpty(), false);
}

TEST(ValueTypes, NumberType) {
	qjson::Number _number{ 12 };
	EXPECT_EQ(_number.GetType(), qjson::ValueType::Number);
	EXPECT_EQ(_number.GetValue(), 12);
	EXPECT_EQ(_number.ToString(), "12");
	EXPECT_EQ(_number.ToJSONString(), "12");
	EXPECT_EQ(_number.IsNullOrEmpty(), false);
}

TEST(ValueTypes, StringType) {
	qjson::String _string{ "Hello, world!" };
	EXPECT_EQ(_string.GetType(), qjson::ValueType::String);
	EXPECT_EQ(_string.GetValue(), "Hello, world!");
	EXPECT_EQ(_string.ToString(), "Hello, world!");
	EXPECT_EQ(_string.ToJSONString(), "\"Hello, world!\"");
	EXPECT_EQ(_string.IsNullOrEmpty(), false);
}

TEST(ValueTypes, PairType) {
	qjson::Pair _pair_null{ "null", nullptr };
	EXPECT_EQ(_pair_null.GetName(), "null");
	EXPECT_EQ(_pair_null.GetValue()->GetType(), qjson::ValueType::Null);

	qjson::Pair _pair_true{ "true", true };
	EXPECT_EQ(_pair_true.GetName(), "true");
	EXPECT_EQ(_pair_true.GetValue()->GetType(), qjson::ValueType::True);

	qjson::Pair _pair_false{ "false", false };
	EXPECT_EQ(_pair_false.GetName(), "false");
	EXPECT_EQ(_pair_false.GetValue()->GetType(), qjson::ValueType::False);

	qjson::Pair _pair_number{ "number", 12 };
	EXPECT_EQ(_pair_number.GetName(), "number");
	EXPECT_EQ(_pair_number.GetValue()->GetType(), qjson::ValueType::Number);

	qjson::Pair _pair_string{ "string", "Hello, world!" };
	EXPECT_EQ(_pair_string.GetName(), "string");
	EXPECT_EQ(_pair_string.GetValue()->GetType(), qjson::ValueType::String);
}

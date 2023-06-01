#include "pch.h"
#include "../Baseball/baseball.cpp"

TEST(TestCaseName, TestName)
{
	const auto* baseball = new Baseball();
	EXPECT_NE(baseball, nullptr);
}

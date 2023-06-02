#include "pch.h"
#include "../Baseball/baseball.cpp"

TEST(BaseballGame, InvalidArgument)
{
	const Baseball baseball{"123"};
	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("121"), std::invalid_argument);
}

TEST(BaseballGame, PerfectMatch)
{
	const Baseball baseball{"123"};
	const auto result = baseball.guess("123");

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST(BaseballGame, MissMatch)
{
	const Baseball baseball{ "123" };
	const auto result = baseball.guess("321");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}
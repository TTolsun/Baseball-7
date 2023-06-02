#include <stdexcept>
#include <string>

class Baseball
{
public:
	struct Result
	{
		bool solved{};
		int strikes{};
		int balls{};
	};

	explicit Baseball(std::string question) : mQuestion(std::move(question))
	{
	}

	Result guess(const std::string& guessNumber) const
	{
		assertInvalidArgument(guessNumber);

		if (guessNumber == mQuestion)
			return {true, 3, 0};
		return {false, strikeCount(guessNumber), ballCount(guessNumber)};
	}

private:
	static bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	static bool isIncludeChar(const std::string& guessNumber)
	{
		for (const auto& ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			return false;
		}
		return true;
	}

	static void assertInvalidArgument(const std::string& guessNumber)
	{
		if (guessNumber.empty())
			throw std::invalid_argument("값을 넣어야 함");
		if (guessNumber.length() != 3)
			throw std::invalid_argument("자리수 오류");
		for (const auto& ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw std::invalid_argument("숫자로만 구성되어 있지 않음");
		}
		if (isDuplicatedNumber(guessNumber))
			throw std::invalid_argument("중복된 숫자 금지");
	}

	int strikeCount(const std::string& guessNumber) const
	{
		int strikeCnt{};
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == mQuestion[i])
				strikeCnt++;
		}
		return strikeCnt;
	}

	int ballCount(const std::string& guessNumber) const
	{
		int ballCnt{};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				if (mQuestion[i] == guessNumber[j])
					ballCnt++;
			}
		}
		return ballCnt - strikeCount(guessNumber);
	}

	const std::string mQuestion{};
};

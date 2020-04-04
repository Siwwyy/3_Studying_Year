#include <iostream>
#include <cstdint>
#include <vector>



int main(int argc, char* argv[])
{
	std::vector<std::pair<int32_t, bool>> Data{};
	std::vector<int32_t> Prime_Numbers{};
	int32_t N{ 2000000 };
	for (size_t i = 2; i <= N; ++i)
	{
		Data.emplace_back(std::make_pair(static_cast<int32_t>(i),false));
	}

	for (size_t i = 0; i < sqrt(N); ++i)
	{
		if (Data[i].second == false)
		{
			Data[i].second = true;
			Prime_Numbers.emplace_back(Data[i].first);
			for (size_t j = i; j < Data.size(); ++j)
			{
				if (Data[j].first % Data[i].first == 0)
				{
					Data[j].second = true;
				}
			}
		}
	}

	for (size_t i = 0; i < Data.size(); ++i)
	{
		if (Data[i].second == false)
		{
			Data[i].second = true;
			Prime_Numbers.emplace_back(Data[i].first);
		}
	}

	size_t counter{};
	for (size_t i = 0; i < Prime_Numbers.size(); ++i)
	{
		if (Prime_Numbers[i] >= 1000000)
		{
			++counter;
		}
	}

	std::cout << "\n" << "Amount of primes: " << counter << '\n';

	std::cin.get();
	return EXIT_SUCCESS;
}
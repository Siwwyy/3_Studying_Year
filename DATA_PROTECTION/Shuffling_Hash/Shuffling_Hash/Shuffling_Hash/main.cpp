#include <iostream>
#include <cstdint>
#include <vector>
#include <random>
#include <string>

constexpr char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


const long long DJB(const std::string& text);
const long long Adler32(const std::string& text);
const std::string Get_Text(const size_t size);		//returning text with specified size, text generated from alphabet given above
void Generator(const size_t N, const size_t D, const long long(*ptr_fun)(const std::string&));	//Generator of N times, D size of text and pointer to function DJB or Adler32


template<typename T, std::size_t N>
constexpr std::size_t Array_Size(T(&)[N]) noexcept;	//used for length of alphabet

int main(int argc, char* argv[])
{

	size_t D{ 8 };
	const size_t N{ 100000 };

	//ADLER32
	//D = 8
	D = 8;
	std::cout << "Adler 32, D=" << D << ", N=" << N << '\n';
	Generator(D, N, Adler32);

	//D = 100
	D = 100;
	std::cout << "Adler 32, D=" << D << ", N=" << N << '\n';
	Generator(D, N, Adler32);

	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	//DJB
	//D = 8
	D = 8;
	std::cout << "DJB, D=" << D << ", N=" << N << '\n';
	Generator(D, N, DJB);

	//D = 100
	D = 100;
	std::cout << "DJB, D=" << D << ", N=" << N << '\n';
	Generator(D, N, DJB);

	std::cin.get();
	return EXIT_SUCCESS;
}




const long long DJB(const std::string& text)
{
	long long starting_value{ 5381 };
	long long final_hash{ starting_value };

	for (size_t i = 0; i < text.size(); ++i)
	{
		final_hash = final_hash * 32 + final_hash + static_cast<long long>(text[i]);
	}
	return final_hash;
}

const long long Adler32(const std::string& text)
{
	long long A{ 1 };
	long long B{ 0 };
	long long P{ 65521 };

	for (size_t i = 0; i < text.size(); ++i)
	{
		A = (A + static_cast<long long>(text[i])) % P;
		B = (B + A) % P;
	}
	return ((B * 65536) + A);
}

const std::string Get_Text(const size_t size)
{
	std::string text{};
	size_t alphabet_size = Array_Size(alphabet);

	std::random_device rand;

	std::default_random_engine rand_engine(rand());
	std::uniform_int_distribution<int> dist(0, alphabet_size - 2);
	for (size_t i = 0; i < size; ++i)
	{
		text += alphabet[dist(rand_engine)];
	}

	return text;
}

void Generator(const size_t D, const size_t N, const long long(*ptr_fun)(const std::string&))
{
	size_t collision_counter{};
	bool took_collision = false;

	std::string text_collision{};
	std::string text_collision2{};
	long long control_sum_collision{};

	for (size_t i = 0; i < N; ++i)
	{
		const std::string text = Get_Text(D);
		const long long lhs{ ptr_fun(text) };
		const std::string text2 = Get_Text(D);
		const long long rhs{ ptr_fun(text2) };

		if (lhs == rhs)
		{
			if (took_collision == false)
			{
				text_collision = text;
				text_collision2 = text2;
				control_sum_collision = lhs;

				took_collision = true;
			}
			++collision_counter;
		}
	}

	std::cout << "Amount of collisons: " << collision_counter << '\n';
	if (took_collision == true)
	{
		std::cout << text_collision << "  |  " << text_collision2 << "  |  " << control_sum_collision << '\n';
	}

	std::cout << '\n';
	std::cout << '\n';
}

template<typename T, std::size_t N>
constexpr std::size_t Array_Size(T(&)[N]) noexcept
{
	return N;
}
#include <iostream>
#include <cstdint>
#include <vector>
#include <random>
#include <string>

constexpr char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


const uint64_t DJB(const std::string& text);
const uint64_t Adler32(const std::string& text);
const std::string Get_Text(const size_t size);		//returning text with specified size, text generated from alphabet given above
const std::vector<std::string> Generator(const size_t D, const size_t N);	//Generator of N times, D size of text
const std::vector<uint64_t> Generate_Hash(const uint64_t(*ptr_fun)(const std::string&), const std::vector<std::string>& text_array);	//Generator of text vector (currently size = 100 000) and length of each string 8 or 100
void Find_Duplicates(const std::vector<std::string>& text_array, const std::vector<uint64_t>& hash_array);	//finding duplicates of hash


template<typename T, std::size_t N>
constexpr std::size_t Array_Size(T(&)[N]) noexcept;	//used for length of alphabet

int main(int argc, char* argv[])
{

	size_t D{ 8 };
	const size_t N{ 100000 };

	//For D = 8
	std::vector<std::string> Text_8 = Generator(D, N);
	D = 100;
	std::vector<std::string> Text_100 = Generator(D, N);

	std::vector<uint64_t> Hash_8_Adler = Generate_Hash(Adler32, Text_8);
	std::vector<uint64_t> Hash_100_Adler = Generate_Hash(Adler32, Text_100);

	std::vector<uint64_t> Hash_8_DJB = Generate_Hash(DJB, Text_8);
	std::vector<uint64_t> Hash_100_DJB = Generate_Hash(DJB, Text_100);


	std::cout << "Adler 32, D=8" << ", N=" << N << '\n';
	Find_Duplicates(Text_8, Hash_8_Adler);

	std::cout << '\n';

	std::cout << "Adler 32, D=100" << ", N=" << N << '\n';
	Find_Duplicates(Text_100, Hash_100_Adler);

	std::cout << '\n';


	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////


	std::cout << "DJB, D=8" << ", N=" << N << '\n';
	Find_Duplicates(Text_8, Hash_8_DJB);

	std::cout << '\n';

	std::cout << "DJB, D=100" << ", N=" << N << '\n';
	Find_Duplicates(Text_100, Hash_100_DJB);

	std::cin.get();
	return EXIT_SUCCESS;
}




const uint64_t DJB(const std::string& text)
{
	uint64_t hash{ 5381 };

	for (size_t i = 0; i < text.size(); ++i)
	{
		hash = (hash * 32) + hash + static_cast<uint64_t>(text[i]);
	}
	return hash;
}

const uint64_t Adler32(const std::string& text)
{
	uint64_t A{ 1 };
	uint64_t B{ 0 };
	uint64_t P{ 65521 };

	for (size_t i = 0; i < text.size(); ++i)
	{
		A = (A + static_cast<uint64_t>(text[i])) % P;
		B = (B + A) % P;
	}
	return ((B * 65536) + A);
}

const std::string Get_Text(const size_t size)
{
	std::string text{};
	size_t alphabet_size = Array_Size(Alphabet);

	std::random_device rand;

	std::default_random_engine rand_engine(rand());
	std::uniform_int_distribution<size_t> dist(0, alphabet_size - 2);
	for (size_t i = 0; i < size; ++i)
	{
		text += Alphabet[dist(rand_engine)];
	}

	return text;
}

const std::vector<std::string> Generator(const size_t D, const size_t N)
{
	size_t collision_counter{};
	bool had_collision = false;
	std::vector<std::string> text_array{};

	for (size_t i = 0; i < N; ++i)
	{
		text_array.emplace_back(Get_Text(D));
	}
	return text_array;
}

const std::vector<uint64_t> Generate_Hash(const uint64_t(*ptr_fun)(const std::string&), const std::vector<std::string>& text_array)
{
	std::vector<uint64_t> hash_array{};
	for (size_t i = 0; i < text_array.size(); ++i)
	{
		hash_array.emplace_back(ptr_fun(text_array[i]));
	}
	return hash_array;
}

void Find_Duplicates(const std::vector<std::string>& text_array, const std::vector<uint64_t>& hash_array)
{
	bool had_collision{};
	size_t collision_counter{};
	std::string text_collision{};
	std::string text_collision2{};
	uint64_t control_sum_collision{};

	for (size_t i = 0; i < hash_array.size(); ++i)
	{
		for (size_t j = i + 1; j < hash_array.size(); ++j)
		{
			if (hash_array[i] == hash_array[j])
			{
				if (had_collision == false)
				{
					text_collision = text_array[i];
					text_collision2 = text_array[j];
					control_sum_collision = hash_array[i];

					had_collision = true;
				}
				++collision_counter;
			}
		}
	}

	std::cout << "Amount of collisons: " << collision_counter << '\n';
	if (had_collision == true)
	{
		std::cout << text_collision << "  |  " << text_collision2 << "  |  " << control_sum_collision << '\n';
	}
}

template<typename T, std::size_t N>
constexpr std::size_t Array_Size(T(&)[N]) noexcept
{
	return N;
}
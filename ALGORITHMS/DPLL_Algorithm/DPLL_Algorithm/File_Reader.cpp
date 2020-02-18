#include "File_Reader.hpp"

SAT_File_Reader::File_Reader::File_Reader():
	File(),
	amout_of_literals(),
	file_path("file.in"),
	file_in()
{
	file_in.open(this->file_path.c_str(), std::ios_base::in);

	if (file_in.good() == false)
	{
		std::cerr << "[ FILE UNABLE TO OPEN ] \n";
		this->file_in.close();
	}
}

SAT_File_Reader::File_Reader::File_Reader(const char * const file_path) :
	File(),
	amout_of_literals(),
	file_path(file_path),
	file_in()
{
	file_in.open(this->file_path.c_str(), std::ios_base::in);

	if (file_in.good() == false)
	{
		std::cerr << "[ FILE UNABLE TO OPEN ] \n";
		this->file_in.close();
	}
}

SAT_File_Reader::File_Reader::File_Reader(const File_Reader& Object):
	File(Object.File),
	amout_of_literals(Object.amout_of_literals),
	file_path(Object.file_path),
	file_in()
{

}

void SAT_File_Reader::File_Reader::Read()
{
	int32_t variable{};
	size_t number_of_lines{};
	char c{};
	std::string f{};

	file_in >> c; //c
	file_in >> f; //cnf
	file_in >> amout_of_literals;
	file_in >> number_of_lines;

	//std::cout << c << ' ' << f << ' ';
	//std::cout << variables_range << ' ' << number_of_lines << '\n';

	//File.emplace_back(variables_range);
	//File.emplace_back(number_of_lines);

	for (size_t i = 0; i < number_of_lines; ++i)
	{
		std::vector<int64_t> temp_vector{};
		while (file_in >> variable && variable != 0)
		{
			temp_vector.emplace_back(variable);
			variable = 0;
		}
		temp_vector.emplace_back(0);
		File.emplace_back(temp_vector);
	}

	//for (typename std::vector<int>::const_iterator vec_iterator = this->File.begin(); vec_iterator != this->File.end(); ++vec_iterator)
	//{
	//	std::cout << *vec_iterator << ' ';
	//	if (*vec_iterator == 0)
	//	{
	//		std::cout << '\n';
	//	}
	//}
}

void SAT_File_Reader::File_Reader::Print() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::vector<int64_t>>::const_iterator vec_iterator = this->File.begin(); vec_iterator != this->File.end(); ++vec_iterator)
	{
		for (typename std::vector<int64_t>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			std::cout << *vec_iterator_second << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "|================================|" << '\n';
}

void SAT_File_Reader::File_Reader::Set_File_Path(const char* const file_path)
{
	this->file_path.clear();
	this->file_path = file_path;
}

const std::string SAT_File_Reader::File_Reader::Get_File_Path() const
{
	return std::string(this->file_path);
}

const int64_t SAT_File_Reader::File_Reader::Get_Amout_Of_Literals() const
{
	return int64_t(this->amout_of_literals);
}

const std::vector<std::vector<int64_t>> SAT_File_Reader::File_Reader::Get_File() const
{
	return std::vector<std::vector<int64_t>>(this->File);
}

SAT_File_Reader::File_Reader& SAT_File_Reader::File_Reader::operator=(const File_Reader& Object)
{
	if (this != std::addressof(Object))
	{
		this->File.clear();
		this->file_path.clear();
		this->File = Object.File;
		this->file_path = Object.file_path;
	}
	return *this;
}

SAT_File_Reader::File_Reader::~File_Reader()
{
	this->File.clear();
	this->amout_of_literals = 0;
	this->file_path.clear();
	this->file_in.close();
}
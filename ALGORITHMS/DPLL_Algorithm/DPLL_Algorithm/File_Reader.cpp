#include "File_Reader.hpp"

SAT_File_Reader::File_Reader::File_Reader():
	File(),
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
	file_path(Object.file_path),
	file_in()
{

}

void SAT_File_Reader::File_Reader::Read()
{
	int32_t variables_range{};
	int32_t variable{};
	size_t number_of_lines{};
	char c{};
	std::string f{};

	file_in >> c; //c
	file_in >> f; //cnf
	file_in >> variables_range; 
	file_in >> number_of_lines;

	//std::cout << c << ' ' << f << ' ';
	//std::cout << variables_range << ' ' << number_of_lines << '\n';

	//File.emplace_back(variables_range);
	//File.emplace_back(number_of_lines);

	for (size_t i = 0; i < number_of_lines; ++i)
	{
		while (file_in >> variable && variable != 0)
		{
			File.emplace_back(variable);
			variable = 0;
		}
		File.emplace_back(0);
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

void SAT_File_Reader::File_Reader::Set_File_Path(const char* const file_path)
{
	this->file_path.clear();
	this->file_path = file_path;
}

const std::string SAT_File_Reader::File_Reader::Get_File_Path() const
{
	return std::string(this->file_path);
}

const std::vector<int> SAT_File_Reader::File_Reader::Get_File() const
{
	return std::vector<int>(this->File);
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
	this->file_path.clear();
	this->file_in.close();
}
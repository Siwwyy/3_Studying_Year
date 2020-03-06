#include "File_Reader.hpp"

SAT_File_Reader::File_Reader::File_Reader():
	File(),
	Literals(),
	amount_of_literals(),
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
	Literals(),
	amount_of_literals(),
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
	Literals(Object.Literals),
	amount_of_literals(Object.amount_of_literals),
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
	file_in >> amount_of_literals;
	file_in >> number_of_lines;

	//std::cout << c << ' ' << f << ' ';
	//std::cout << variables_range << ' ' << number_of_lines << '\n';

	//File.emplace_back(variables_range);
	//File.emplace_back(number_of_lines);
	//Literals.resize(amount_of_literals+1);
	for (size_t i = 0; i < amount_of_literals+1; ++i)
	{
		SAT::Literal Obj((static_cast<int64_t>(i + 1)));
		//Literals[i].get().Set_Value(static_cast<int64_t>(i));
		Literals.emplace_back(Obj);//.operator SAT::Literal& () = SAT::Literal(static_cast<int64_t>(i));
		//Literals.emplace_back(Obj);
	}
	for (size_t i = 0; i < number_of_lines; ++i)
	{
		while (file_in >> variable)
		{
			//File.emplace_back(variable);
			if (variable < 0)
			{
				//File.emplace_back(std::make_pair(Literals[static_cast<size_t>(((-1)*variable))], true));
			}
			else
			{
				//File.emplace_back(std::make_pair(Literals[static_cast<size_t>(variable)], false));
			}
			variable = {};
		}
	}

	//for (typename std::vector<int>::const_iterator vec_iterator = this->File.begin(); vec_iterator != this->File.end(); ++vec_iterator)
	//{
	//	std::cout << *vec_iterator << ' ';
	//	if (*vec_iterator == 0)
	//	{
	//		std::cout << '\n';
	//	}
	//}
	//File[0].first.get().Set_Value(1000);
}

void SAT_File_Reader::File_Reader::Print() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::pair<std::reference_wrapper<SAT::Literal>, bool>>::const_iterator vec_iterator = this->File.begin(); vec_iterator != this->File.end(); ++vec_iterator)
	{
		if (vec_iterator->first.get().Get_Value() == 0)
		{
			//std::cout << vec_iterator->first.get().Get_Value() << ' ' << vec_iterator->second << '\n';
			std::cout << vec_iterator->first.get().Get_Value() << '\n';
		}
		else
		{
			//std::cout << vec_iterator->first.get().Get_Value() << ' ' << vec_iterator->second << ' ';
			if (vec_iterator->second == true)
			{
				std::cout << '-' << vec_iterator->first.get().Get_Value() << ' ';
			}
			else
			{
				std::cout << vec_iterator->first.get().Get_Value() << ' ';
			}
		}
	}
	//std::cout << &File[0].first.get() << '\n';
	std::cout << "|================================|" << '\n';
}

void SAT_File_Reader::File_Reader::Print_Literals() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector< std::reference_wrapper<SAT::Literal>>::const_iterator vec_iterator = this->Literals.begin(); vec_iterator != this->Literals.end(); ++vec_iterator)
	{
		std::cout << vec_iterator->get().Get_Value() << ' ';
	}
	std::cout << "\n|================================|" << '\n';
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
	return int64_t(this->amount_of_literals);
}

const std::vector<std::pair<std::reference_wrapper<SAT::Literal>, bool>> SAT_File_Reader::File_Reader::Get_File() const
{
	return this->File;
}

const std::vector< std::reference_wrapper<SAT::Literal>>& SAT_File_Reader::File_Reader::Get_Literals() const
{
	return this->Literals;
}

SAT_File_Reader::File_Reader& SAT_File_Reader::File_Reader::operator=(const File_Reader& Object)
{
	if (this != std::addressof(Object))
	{
		this->File.clear();
		this->Literals.clear();
		this->file_path.clear();
		this->File = Object.File;
		this->file_path = Object.file_path;
		this->amount_of_literals = Object.amount_of_literals;
	}
	return *this;
}

SAT_File_Reader::File_Reader::~File_Reader()
{
	this->File.clear();
	this->Literals.clear();
	this->amount_of_literals = 0;
	this->file_path.clear();
	this->file_in.close();
}
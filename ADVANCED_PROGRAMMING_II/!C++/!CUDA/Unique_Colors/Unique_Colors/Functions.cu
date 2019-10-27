#include "Functions.cuh"

void Read_File(const _STD string& file_path)
{
	std::fstream file_in;
	file_in.open(file_path, std::ios_base::in);
	_STD string line{};
	__int32 a{ 1 };
	//Pixel Temporary_Pixel{};
	std::string extension{};					//extension (p1,p2,p3 etc)
	__int32 width{};							//width
	__int32 height{};							//height
	__int32 color_range{};						//color range
	//static size_t i = 0;
	if (file_in.good() == false)
	{
		exit(0);
	}
	else
	{
		while (file_in.eof() == false)
		{
			if (a < 5)
			{
				_STD getline(file_in, line);
				if (a == 1)
				{
					extension = line;
				}
				else if (a == 3)
				{
					_STD string line_second = "";
					int counter = 0;
					for (size_t i = 0; i < line.size(); i++)
					{
						if (line[i] == ' ')
						{
							width = stoi(line_second);
							line_second = "";
						}
						else
						{
							line_second += line[i];
						}
						counter++;
					}
					height = stoi(line_second);
					//global_size = static_cast<size_t>(width * height);
					//Host_Array = (Pixel*)malloc(global_size * sizeof(Pixel));
				}
				else if (a == 4)
				{
					color_range = (stoi(line));
				}
			}
			else if (a >= 5)
			{
				int color = 0;
				file_in >> color;
				//Temporary_Pixel.Set_R(color);
				color = 0;
				file_in >> color;
				//Temporary_Pixel.Set_G(color);
				color = 0;
				file_in >> color;
				//Temporary_Pixel.Set_B(color);
				//Temporary_Pixel.Set_Color_Range(color_range);
				color = 0;
				//Host_Array[i++] = Temporary_Pixel;
			}
			line = "";
			a++;
		}
	}
	_STD cout << "--------------------------" << NEW_LINE;
	_STD cout << "  Information" << NEW_LINE;
	_STD cout << "  Loaded format: " << extension << NEW_LINE;
	_STD cout << "  Width: " << width << NEW_LINE;
	_STD cout << "  Height: " << height << NEW_LINE;
	_STD cout << "  Color Range: " << color_range << NEW_LINE;
	_STD cout << "------------------------" << NEW_LINE;
	//_STD cout << "  Array size: " << static_cast<size_t>(Pixel_array.size()) << NEW_LINE;
	//_STD cout << "  Array size: " << static_cast<size_t>((global_size)) << NEW_LINE;
	_STD cout << "------------------------" << NEW_LINE;

	file_in.close();
}
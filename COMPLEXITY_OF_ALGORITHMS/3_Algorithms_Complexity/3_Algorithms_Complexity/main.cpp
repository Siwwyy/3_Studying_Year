#include "Testing_Engine.hpp"
#include "Prims.hpp"
#include "Djikstra.hpp"
#include "Kruskal.hpp"

int main(int argc, char* argv[])
{
	//Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test("testowy1.in");
	//Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test({"testowy1.in","file.in","file_example1.in","testowy2.in"});
	Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test({ "example.out","example2.out","example3.out","example4.out", "example5.out" });
	//My_Test.Push_Function(inserter_PRIMS);
	//My_Test.Push_Function(inserter_KRUSKAL);
	My_Test.Push_Function(inserter_DJIKSTRA);
	//My_Test.Push_Names("Prims");
	//My_Test.Push_Names("Kruskal");
	My_Test.Push_Names("Djikstra");
	//My_Test.Show_Pointer_To_Functions();
	//My_Test.Show_File_Content();
	//system("pause");
	//My_Test.Test(0);
	//My_Test.Test(1);
	My_Test.Test(0);

	system("pause");
	return EXIT_SUCCESS;
}


//Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test("file.in");
//Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test("wejscie.txt");
//Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test("file_example1.in");
//Testing::Testing_Engine<void(*)(const _STD vector<__int32> & file_content)> My_Test("d_tomaszczyk.in");
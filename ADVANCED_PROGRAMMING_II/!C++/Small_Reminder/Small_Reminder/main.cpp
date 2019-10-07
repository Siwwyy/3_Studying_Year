#include <iostream>
#include <windows.h>
#include <string>

#define NEW_LINE '\n'


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	char array[] = "My Char";
	const char* ptr = "HELLO";

	/*cout << array << NEW_LINE;
	size_t i{};
	while (array[i] != '\0')
	{
		cout << array[i];
		++i;
	}
	cout << NEW_LINE;*/
	/*cout << ptr << NEW_LINE;
	printf("%s\n", ptr);*/
	char* str1 = (char*)"string Literal";
	const char* str2 = "string Literal";
	char source[] = "Sample string";

	cout << str1 << NEW_LINE;
	system("pause");
	return 0;
}
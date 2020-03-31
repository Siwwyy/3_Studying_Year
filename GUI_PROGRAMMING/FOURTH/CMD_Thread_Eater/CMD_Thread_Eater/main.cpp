#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include <windows.h>
#include <functional>
#include <chrono>
#include <mutex>

#include "Defines.hpp"

std::mutex cout_mutex{};
std::mutex _str_mutex{};

void Print(const std::string& _str);
void Eater(std::string& _str);
void Filler(std::string& _str);

int main(int argc, char* argv[])
{
	std::string _str{ "dddd" };
	//std::thread t1(Filler, std::move(_str));
	//std::thread t2(Filler, std::move(_str));
	//std::thread t3(Filler, std::move(_str));
	//std::thread t4(Filler, std::move(_str));


	//std::thread t5(Eater, std::move(_str));

	std::thread Print_Thread(Print, std::move(_str));

	//while (true)
	//{
	//	/*	std::cout << "ddd" << NEW_LINE;
	//		std::this_thread::sleep_for(std::chrono::milliseconds(500));*/
	//	Print(_str);
	//}


	WAIT_KEY
	return EXIT_SUCCESS;
}

void Print(const std::string& _str)
{
	while (true)
	{
		std::lock_guard<std::mutex> cout_locker(cout_mutex);
		std::lock_guard<std::mutex> _str_locker(_str_mutex);
		std::cout << _str << NEW_LINE;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void Eater(std::string& _str)
{

}

void Filler(std::string& _str)
{

}
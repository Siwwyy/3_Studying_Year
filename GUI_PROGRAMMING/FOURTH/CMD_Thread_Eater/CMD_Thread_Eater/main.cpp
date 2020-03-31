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
	std::string _str{ "d" };
	//std::thread t1(Filler, std::move(_str));
	//std::thread t2(Filler, std::move(_str));
	//std::thread t3(Filler, std::move(_str));
	//std::thread t4(Filler, std::move(_str));


	//std::thread t5(Eater, std::move(_str));

	std::thread Print_Thread(Print, std::ref(_str));
	std::thread Filler_Thread1(Filler, std::ref(_str));
	std::thread Filler_Thread2(Filler, std::ref(_str));
	std::thread Filler_Thread3(Filler, std::ref(_str));
	std::thread Filler_Thread4(Filler, std::ref(_str));

	std::thread Eater_Thread(Eater, std::ref(_str));

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
		system("cls");
		_str_mutex.lock();
		std::cout << _str << NEW_LINE;
		_str_mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void Eater(std::string& _str)
{
	while (true)
	{
		int wait_time{};
		_str_mutex.lock();
		if (_str.empty() == false)
		{
			_str.erase((_str.end() - 1));
			wait_time = 100;
		}
		else
		{
			wait_time = 2000;
		}
		_str_mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
	}
}

void Filler(std::string& _str)
{
	while (true)
	{
		_str_mutex.lock();
		_str += "d";
		_str_mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
#include "_FACTORY.h"

using namespace std;

int main()
{
	//_FACTORY f;
	//f.setExterlnalInfo("500 200 100");   //informacje o czestotliwosci itp (wewnetrzne parametry) zobacz: Parser do lancucha znakow
	//f.setOutput(_FACTORY::BEEP);			//rodzaj morsa
	//f.Convert("Ala ma kota");			//co ma wybipac itp
	//f.setOutput(_FACTORY::BLINK);			//rodzaj morsa
	//f.Convert("Ala ma kota");			//co ma wybipac itp
	//f.setOutput(_FACTORY::CONSOLE);			//rodzaj morsa
	//f.Convert("Ala ma kota");			//co ma wybipac itp
	//f.setOutput(_FACTORY::DISK);			//rodzaj morsa
	//f.Convert(" a pies");			//co ma wybipac itp (tutaj rodzaj pliku)
	//f.Convert(123);			//rodzaj morsa
	//f.Convert(1.23);			//rodzaj morsa								//rodzaj mors

	_MORSE_BASE* bs = new _MORSE_BEEP("beep");
	_MORSE_BASE* bs1 = new _MORSE_BEEP("beep");
	bs = bs1;

	std::cin.get();
	return 0;
}

/*
	do 04.01.2019 do 23:59:59;

	Jeden interfejs dla 4 obiektow !
	glosnikowy
	lampkowy
	konsolowy
	dyskowy (plik.txt)


	blink beep console disc

	morse <-------
				|<-blink
				|<-beep
				|<-console
				|<-disc

	TARGET - > poprawna implementacja relacjami, konstrukcja fajna klas 

	zrob tez mp3 grajace na kalwiaturze i przycieniane itp
*/


	////MIGANIE LAMPKI

	//#define _WIN32_WINNT 0x403
	//#include <windows.h>

	//void capslockBlink();

	//int main()
	//{
	//	for(int i = 0 ; i < 10000; ++i)
	//	{
	//		capslockBlink();
	//	}
	//	return 0;
	//}

	//void capslockBlink()
	//{
	//	INPUT in[2];
	//	in[0].type = INPUT_KEYBOARD;
	//	in[0].ki.wVk = VK_CAPITAL;
	//	in[0].ki.wScan = 0;
	//	in[0].ki.time = 0;
	//	in[0].ki.dwFlags = 0;
	//	in[0].ki.dwExtraInfo = 0;
	//	in[1] = in[0];
	//	in[1].ki.dwFlags = KEYEVENTF_KEYUP;
	//	SendInput(2, in, sizeof(INPUT));
	//}

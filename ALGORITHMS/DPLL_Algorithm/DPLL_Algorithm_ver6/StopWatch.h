// STOPWATCH_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						   *** Koniec: 10/01/2019 ***
 *							  Klasa ma za zadanie:
 *	Policzyc nam w nanosekundach czas wykonywania naszej funkcji itp.
 *	11/01/2019 -> Dodane: Wybor trzech jednostek czasu do wyswietlania wyniku (nano,mili,sekunda)
 */
#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#pragma once

	#ifdef STOPWATCH_OFF
		//#define INFO	std::cout << "#define STOPWATCH_ON must be declared to turn on the STOPWATCH" << std::endl;
	#elif defined (STOPWATCH_ON)
		//#ifdef STOPWATCH_ON
 
		#include <iostream>
		#include <chrono>
		
		class StopWatch
		{
		private:
			/*
				ZMIENNE PRIVATE
			*/
			std::chrono::high_resolution_clock::time_point m_start;			//"zmienna" ktora bedzie trzymac czas startowy		(czesc struktury steady_clock, przestrzeni nazw chrono)
			std::chrono::high_resolution_clock::time_point m_stop;			//"zmienna" ktora bedzie trzymac czas koncowy		(czesc struktury steady_clock, przestrzeni nazw chrono)
			//////////////////////////////////////////////////////////////////////////////
			/*
				KONSTRUKTORY PRIVATE
			*/
			StopWatch(const StopWatch & Object) = delete;			//konstruktor kopiujacy (usuniety)
			//////////////////////////////////////////////////////////////////////////////
			/*
				OPERATORY PRIVATE
			*/
			//Jednoargumentowe
			StopWatch & operator=(const StopWatch & Object) = delete;			//operator przypisania (usuniety)
			//////////////////////////////////////////////////////////////////////////////
		protected:

		public:
			enum TIME_UNIT		//enumerator wyboru
			{
				SECOND = 0,
				MILLISECOND = 1,
				NANOSECOND = 2
			};
			/*
				KONSTRUKTORY
			*/
			StopWatch();			//konstruktor bezparametrowy
			//////////////////////////////////////////////////////////////////////////////
			/*
				FUNKCJE PUBLIC
			*/
			void START();											//funkcja typu void startujaca nasz zegar
			void STOP();											//funkcja typu void zatrzymujaca nasz zegar i wyswietlajaca wynik
			void STOP(enum StopWatch::TIME_UNIT CHOICE);			//funkcja typu void zatrzymujaca nasz zegar i wyswietlajaca wynik (dodany enumerator wyboru typy w jakiej jednostce czasu chcemy wynik)
			/*
				OPERATORY PUBLIC
			*/
			//Jednoargumentowe
			friend std::ostream & operator<<(std::ostream & lhs, const StopWatch& rhs);			//operator strumienia wyjscia
			//////////////////////////////////////////////////////////////////////////////
			/*	
				DESTRUKTOR
			*/
			~StopWatch();				//destruktor
			//////////////////////////////////////////////////////////////////////////////
		};

		static StopWatch MyObj;

		#define START_STOPWATCH MyObj.START();
		#define STOP_STOPWATCH  MyObj.STOP();
		//#define STOP_STOPWATCH_CHOICE(x)  MyObj.START(StopWatch::x);

		//#endif /* STOPWATCH_ON */
	#endif /* STOPWATCH_OFF / STOPWATCH_ON */

#endif /* STOPWATCH_H_ */
//#include <iostream>
//#include <string>
//#include <windows.h>
#include "fl/Headers.h"

//#define NEW_LINE '\n'

int main()
{
	using _STD endl;
	using _STD cin;
	using _STD cout;
	//using _STD cout;


	using namespace fl;

	Engine* engine = new Engine;
	engine->setName("Car steering");
	engine->setDescription("");

	InputVariable* obstacle = new InputVariable;
	obstacle->setName("obstacle");
	obstacle->setDescription("");
	obstacle->setEnabled(true);
	obstacle->setRange(0.000, 1.000);
	obstacle->setLockValueInRange(false);
	obstacle->addTerm(new Ramp("left", 1.000, 0.000));
	obstacle->addTerm(new Ramp("right", 0.000, 1.000));
	engine->addInputVariable(obstacle);

	



	//Before u are staring the engine, check status
	std::string status{};
	if (not engine->isReady(&status))
	{
		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
	}
	else
	{

	}

	system("pause");
	return 0;
}
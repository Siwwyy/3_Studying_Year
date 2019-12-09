////#include <iostream>
////#include <string>
////#include <windows.h>
//#include "fl/Headers.h"
//
////#define NEW_LINE '\n'
//
//int main()
//{
//	using _STD endl;
//	using _STD cin;
//	using _STD cout;
//	//using _STD cout;
//
//
//	using namespace fl;
//
//	Engine* engine = new Engine;
//	engine->setName("Car steering");
//	engine->setDescription("");
//
//	InputVariable* obstacle = new InputVariable;
//	obstacle->setName("obstacle");
//	obstacle->setDescription("");
//	obstacle->setEnabled(true);
//	obstacle->setRange(0.000, 90.000);
//	obstacle->setLockValueInRange(false);
//	obstacle->addTerm(new Ramp("1", 0.000, 10.000));
//	obstacle->addTerm(new Ramp("2", 11.000, 20.000));
//	obstacle->addTerm(new Ramp("3", 21.000, 30.000));
//	obstacle->addTerm(new Ramp("4", 31.000, 40.000));
//	obstacle->addTerm(new Ramp("5", 41.000, 50.000));
//	obstacle->addTerm(new Ramp("6", 51.000, 60.000));
//	obstacle->addTerm(new Ramp("7", 61.000, 70.000));
//	obstacle->addTerm(new Ramp("8", 71.000, 80.000));
//	obstacle->addTerm(new Ramp("9", 81.000, 90.000));
//	engine->addInputVariable(obstacle);
//
//	InputVariable* speed = new InputVariable;
//	speed->setName("speed");
//	speed->setDescription("");
//	speed->setEnabled(true);
//	speed->setRange(0.000, 90.000);
//	speed->setLockValueInRange(false);
//	speed->addTerm(new Ramp("1", 0.000, 10.000));
//	speed->addTerm(new Ramp("2", 11.000, 20.000));
//	speed->addTerm(new Ramp("3", 21.000, 30.000));
//	speed->addTerm(new Ramp("4", 31.000, 40.000));
//	speed->addTerm(new Ramp("5", 41.000, 50.000));
//	speed->addTerm(new Ramp("6", 51.000, 60.000));
//	speed->addTerm(new Ramp("7", 61.000, 70.000));
//	speed->addTerm(new Ramp("8", 71.000, 80.000));
//	speed->addTerm(new Ramp("9", 81.000, 90.000));
//	engine->addInputVariable(speed);
//
//
//	OutputVariable* distance = new OutputVariable;
//	distance->setName("distance");
//	distance->setDescription("");
//	distance->setEnabled(true);
//	distance->setRange(0.000, 90.000);
//	distance->setLockValueInRange(false);
//	distance->setAggregation(new Maximum);
//	distance->setDefuzzifier(new Centroid());
//	distance->setDefaultValue(0.0);
//	distance->setLockPreviousValue(false);
//	distance->addTerm(new Ramp("1", 0.000, 10.000));
//	distance->addTerm(new Ramp("2", 11.000, 20.000));
//	distance->addTerm(new Ramp("3", 21.000, 30.000));
//	distance->addTerm(new Ramp("4", 31.000, 40.000));
//	distance->addTerm(new Ramp("5", 41.000, 50.000));
//	distance->addTerm(new Ramp("6", 51.000, 60.000));
//	distance->addTerm(new Ramp("7", 61.000, 70.000));
//	distance->addTerm(new Ramp("8", 71.000, 80.000));
//	distance->addTerm(new Ramp("9", 81.000, 90.000));
//	engine->addOutputVariable(distance);
//	
//	RuleBlock* rules = new RuleBlock;
//	rules->setName("rules");
//	rules->setDescription("");
//	rules->setEnabled(true);
//	rules->setConjunction(new Minimum());
//	rules->setDisjunction(fl::null);
//	rules->setImplication(new AlgebraicProduct);
//	rules->setActivation(new General);
//
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 9 then distance is 1", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 8 then distance is 2", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 7 then distance is 3", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 6 then distance is 4", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 5 then distance is 5", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 4 then distance is 6", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 3 then distance is 7", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 2 then distance is 8", engine));
//	rules->addRule(Rule::parse("if obstacle is 3 and speed is 1 then distance is 9", engine));
//
//	//rules->addRule(Rule::parse("if obstacle is 1 and speed is 2 then distance is 1", engine));
//	//rules->addRule(Rule::parse("if obstacle is 2 and speed is 2 then distance is 2", engine));
//	//rules->addRule(Rule::parse("if obstacle is 3 and speed is 2 then distance is 3", engine));
//	//rules->addRule(Rule::parse("if obstacle is 4 and speed is 2 then distance is 4", engine));
//	//rules->addRule(Rule::parse("if obstacle is 5 and speed is 2 then distance is 5", engine));
//	//rules->addRule(Rule::parse("if obstacle is 6 and speed is 2 then distance is 6", engine));
//	//rules->addRule(Rule::parse("if obstacle is 7 and speed is 2 then distance is 7", engine));
//	//rules->addRule(Rule::parse("if obstacle is 8 and speed is 2 then distance is 8", engine));
//	//rules->addRule(Rule::parse("if obstacle is 9 and speed is 2 then distance is 9", engine));
//
//	engine->addRuleBlock(rules);
//
//
//	//Before u are staring the engine, check status
//	std::string status{};
//	if (not engine->isReady(&status))
//	{
//		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
//	}
//	else
//	{
//		scalar distance_obstacle{28.000f};
//		scalar speed_car{90.000f};
//		int tab[10]{};
//		size_t counter{};
//		while(speed_car >= 0)
//		{
//			obstacle->setValue(distance_obstacle);
//			speed->setValue(speed_car);
//			engine->process();
//			tab[counter] = engine->getOutputValue("distance");
//			++counter;
//			speed_car -= 10.0f;
//		}
//		counter = 9;
//		speed_car = 90.f;
//		while (speed_car >= 0)
//		{
//			if (speed_car == 90.f)
//			{
//				FL_LOG("speed.input = " << Op::str(speed_car) << " ," << " obstacle.input = " << Op::str(distance_obstacle) << " distance.output = " << 90 << '\n');
//				counter--;
//			}
//			else
//			{
//				FL_LOG("speed.input = " << Op::str(speed_car) << " ," << " obstacle.input = " << Op::str(distance_obstacle) << " distance.output = " << tab[counter--] << '\n');
//			}
//			speed_car -= 10.0f;
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//
//
//
////#include "fl/Headers.h"
////#include <iostream>
////#include <string>
////#include <windows.h>
////
//////#define NEW_LINE '\n'
////
////int main()
////{
////	using _STD endl;
////	using _STD cin;
////	using _STD cout;
////	//using _STD cout;
////
////
////	using namespace fl;
////
////	Engine* engine = new Engine;
////	engine->setName("Obstacle");
////	engine->setDescription("");
////
////	InputVariable* speed = new InputVariable;
////	speed->setName("tempin");
////	speed->setDescription("");
////	speed->setEnabled(true);
////	speed->setRange(1.000f, 91.000f);
////	speed->setLockValueInRange(false);
////	speed->addTerm(new Ramp("cold", 10.000f, 15.000f));
////	speed->addTerm(new Ramp("chilly", 15.100f, 19.999f));
////	speed->addTerm(new Ramp("hot", 20.000f, 30.000f));
////	engine->addInputVariable(speed);
////
////	InputVariable* temp_outside = new InputVariable;
////	temp_outside->setName("tempout");
////	temp_outside->setDescription("");
////	temp_outside->setEnabled(true);
////	temp_outside->setRange(0.000f, 40.000f);
////	temp_outside->setLockValueInRange(false);
////	temp_outside->addTerm(new Ramp("cold", 0.000f, 15.000f));
////	temp_outside->addTerm(new Ramp("chilly", 15.100f, 19.999f));
////	temp_outside->addTerm(new Ramp("medium_hot", 20.000f, 30.000f));
////	temp_outside->addTerm(new Ramp("hot", 30.000f, 40.000f));
////	engine->addInputVariable(temp_outside);
////
////	OutputVariable* air_conditioner = new OutputVariable;
////	air_conditioner->setName("AC");
////	air_conditioner->setDescription("");
////	air_conditioner->setEnabled(true);
////	air_conditioner->setRange(10.0, 25.0);
////	air_conditioner->setLockValueInRange(false);
////	air_conditioner->setAggregation(new Maximum);
////	air_conditioner->setDefuzzifier(new Centroid());
////	air_conditioner->setDefaultValue(21.0);
////	air_conditioner->setLockPreviousValue(false);
////	air_conditioner->addTerm(new Ramp("cold", 10.0, 15.0));
////	air_conditioner->addTerm(new Ramp("chilly", 15.0, 19.9));
////	air_conditioner->addTerm(new Ramp("hot", 20.0, 25.0));
////	engine->addOutputVariable(air_conditioner);
////
////
////	RuleBlock* rules = new RuleBlock;
////	rules->setName("rules");
////	rules->setDescription("");
////	rules->setEnabled(true);
////	rules->setConjunction(new Minimum());
////	rules->setDisjunction(fl::null);
////	rules->setImplication(new AlgebraicProduct);
////	rules->setActivation(new General);
////
////	rules->addRule(Rule::parse("if tempin is cold and tempout is cold then AC is hot", engine));
////	rules->addRule(Rule::parse("if tempin is cold and tempout is chilly then AC is chilly", engine));
////	rules->addRule(Rule::parse("if tempin is cold and tempout is hot then AC is chilly", engine));
////
////	rules->addRule(Rule::parse("if tempin is chilly and tempout is cold then AC is hot", engine));
////	rules->addRule(Rule::parse("if tempin is chilly and tempout is chilly then AC is chilly", engine));
////	rules->addRule(Rule::parse("if tempin is chilly and tempout is hot then AC is cold", engine));
////
////	rules->addRule(Rule::parse("if tempin is hot and tempout is cold then AC is chilly", engine));
////	rules->addRule(Rule::parse("if tempin is hot and tempout is chilly then AC is chilly", engine));
////	rules->addRule(Rule::parse("if tempin is hot and tempout is hot then AC is cold", engine));
////
////	engine->addRuleBlock(rules);
////
////
////
////	//Before u are staring the engine, check status
////	std::string status{};
////	if (not engine->isReady(&status))
////	{
////		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
////	}
////	else
////	{
////		scalar temp_in = 10.0f;
////		scalar temp_out = 0.0f;
////
////		for (size_t i = 0; i < 3; ++i)
////		{
////			temp_out = 0;
////			for (size_t j = 0; j < 8; ++j)
////			{
////				temp_inside->setValue(temp_in);
////				temp_outside->setValue(temp_out);
////				engine->process();
////				FL_LOG("Temperature_inside.input = " << Op::str(temp_in) << " ," << "Temperature_outside.input = " << Op::str(temp_out) << " AC.output = " << engine->getOutputValue("AC") << '\n');
////				temp_out += 5.1f;
////			}
////			temp_in += 5.1f;
////		}
////	}
////
////	system("pause");
////	return 0;
////}

//podlewanie

#include "fl/Headers.h"
#include <iostream>
#include <string>
#include <windows.h>

//#define NEW_LINE '\n'

int main()
{
	using _STD endl;
	using _STD cin;
	using _STD cout;
	//using _STD cout;


	using namespace fl;

	Engine* engine = new Engine;
	engine->setName("Podlewanie");
	engine->setDescription("");

	InputVariable* temperature = new InputVariable;
	temperature->setName("temperature");
	temperature->setDescription("");
	temperature->setEnabled(true);
	temperature->setRange(10.000f, 30.000f);
	temperature->setLockValueInRange(false);
	temperature->addTerm(new Ramp("cold", 10.000f, 15.000f));
	temperature->addTerm(new Ramp("chilly", 15.100f, 19.999f));
	temperature->addTerm(new Ramp("hot", 20.000f, 30.000f));
	engine->addInputVariable(temperature);

	InputVariable* humidity = new InputVariable;
	humidity->setName("humidity");
	humidity->setDescription("");
	humidity->setEnabled(true);
	humidity->setRange(0.000f, 60.000f);
	humidity->setLockValueInRange(false);
	humidity->addTerm(new Ramp("small", 0.000f, 20.000f));
	humidity->addTerm(new Ramp("medium", 21.100f, 40.999f));
	humidity->addTerm(new Ramp("huge", 41.000f, 60.000f));
	engine->addInputVariable(humidity);

	OutputVariable* watering = new OutputVariable;
	watering->setName("watering");
	watering->setDescription("");
	watering->setEnabled(true);
	watering->setRange(5.000, 30.000);
	watering->setLockValueInRange(false);
	watering->setAggregation(new Maximum);
	watering->setDefuzzifier(new Centroid());
	watering->setDefaultValue(21.0);
	watering->setLockPreviousValue(false);
	watering->addTerm(new Ramp("small", 5.0, 15.0));
	watering->addTerm(new Ramp("medium", 15.1, 25.0));
	watering->addTerm(new Ramp("big", 25.1, 30.0));
	engine->addOutputVariable(watering);


	RuleBlock* rules = new RuleBlock;
	rules->setName("rules");
	rules->setDescription("");
	rules->setEnabled(true);
	rules->setConjunction(new Minimum());
	rules->setDisjunction(fl::null);
	rules->setImplication(new AlgebraicProduct);
	rules->setActivation(new General);

	rules->addRule(Rule::parse("if temperature is cold and humidity is small then watering is small", engine));
	rules->addRule(Rule::parse("if temperature is cold and humidity is medium then watering is small", engine));
	rules->addRule(Rule::parse("if temperature is cold and humidity is huge then watering is small", engine));

	rules->addRule(Rule::parse("if temperature is chilly and humidity is small then watering is big", engine));
	rules->addRule(Rule::parse("if temperature is chilly and humidity is medium then watering is medium", engine));
	rules->addRule(Rule::parse("if temperature is chilly and humidity is huge then watering is small", engine));

	rules->addRule(Rule::parse("if temperature is hot and humidity is small then watering is big", engine));
	rules->addRule(Rule::parse("if temperature is hot and humidity is medium then watering is medium", engine));
	rules->addRule(Rule::parse("if temperature is hot and humidity is huge then watering is small", engine));

	engine->addRuleBlock(rules);



	//Before u are staring the engine, check status
	std::string status{};
	if (not engine->isReady(&status))
	{
		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
	}
	else
	{
		scalar temperature_out = 10.0f;
		scalar humi = 0.0f;

		for (size_t i = 0; i < 3; ++i)
		{
			humi = 0;
			for (size_t j = 0; j < 10; ++j)
			{
				temperature->setValue(temperature_out);
				humidity->setValue(humi);
				engine->process();
				FL_LOG("Temperature.input = " << Op::str(temperature_out) << " ," << " Humidity.input = " << Op::str(humi) << " Watering.output = " << engine->getOutputValue("watering") << '\n');
				humi += 5.1f;
			}
			temperature_out += 5.1f;
		}

		temperature->setValue(28.000);
		humidity->setValue(58.000);
		engine->process();
		FL_LOG("Temperature.input = " << Op::str(28.000) << " ," << " Humidity.input = " << Op::str(58.000) << " Watering.output = " << engine->getOutputValue("watering") << '\n');

	}

	system("pause");
	return 0;
}
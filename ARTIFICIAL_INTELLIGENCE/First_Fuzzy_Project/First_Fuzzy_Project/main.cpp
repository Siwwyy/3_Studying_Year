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
//	engine->setName("Propability of crash");
//	engine->setDescription("");
//
//	InputVariable* speed = new InputVariable;
//	speed->setName("velocity");
//	speed->setDescription("");
//	speed->setEnabled(true);
//	speed->setRange(10.000, 200.000);
//	speed->setLockValueInRange(false);
//	speed->addTerm(new Ramp("slow", 10.000, 40.000));
//	speed->addTerm(new Ramp("medicore", 40.000, 90.000));
//	speed->addTerm(new Ramp("fast", 90.000, 150.000));
//	speed->addTerm(new Ramp("very fast", 150.000, 200.000));
//	engine->addInputVariable(speed);
//
//	InputVariable* sight = new InputVariable;
//	sight->setName("visibility");
//	sight->setDescription("");
//	sight->setEnabled(true);
//	sight->setRange(0.05, 4.0);
//	sight->setLockValueInRange(false);
//	sight->addTerm(new Ramp("bad", 0.05, 1.000));
//	sight->addTerm(new Ramp("medicore", 1.000, 1.500));
//	sight->addTerm(new Ramp("good", 1.500, 4.000));
//	engine->addInputVariable(sight);
//
//	OutputVariable* propability = new OutputVariable;
//	propability->setName("propability");
//	propability->setDescription("");
//	propability->setEnabled(true);
//	propability->setRange(0.000, 1.000);
//	propability->setLockValueInRange(false);
//	propability->setAggregation(new Maximum);
//	propability->setDefuzzifier(new Centroid());
//	propability->setDefaultValue(fl::nan);
//	propability->setLockPreviousValue(false);
//	propability->addTerm(new Ramp("small", 0.000, 0.300));
//	propability->addTerm(new Ramp("medicore", 0.300, 0.600));
//	propability->addTerm(new Ramp("high", 0.600, 1.000));
//	engine->addOutputVariable(propability);
//
//
//	RuleBlock* rules = new RuleBlock;
//	rules->setName("rules");
//	rules->setDescription("");
//	rules->setEnabled(true);
//	rules->setConjunction(new Minimum());
//	rules->setDisjunction(fl::null);
//	rules->setImplication(new AlgebraicProduct);
//	rules->setActivation(new General);
//	rules->addRule(Rule::parse("if velocity is slow and visibility is bad then propability is small", engine));
//	rules->addRule(Rule::parse("if velocity is slow and visibility is medicore then propability is small", engine));
//	rules->addRule(Rule::parse("if velocity is slow and visibility is good then propability is small", engine));
//	rules->addRule(Rule::parse("if velocity is medicore and visibility is bad then propability is medicore", engine));
//	rules->addRule(Rule::parse("if velocity is medicore and visibility is medicore then propability is small", engine));
//	rules->addRule(Rule::parse("if velocity is medicore and visibility is good then propability is small", engine));
//	rules->addRule(Rule::parse("if velocity is fast and visibility is bad then propability is high", engine));
//	rules->addRule(Rule::parse("if velocity is fast and visibility is medicore then propability is medicore", engine));
//	rules->addRule(Rule::parse("if velocity is fast and visibility is good then propability is small", engine));
//	rules->addRule(Rule::parse("if velocity is very fast and visibility is bad then propability is high", engine));
//	rules->addRule(Rule::parse("if velocity is very fast and visibility is medicore then propability is high", engine));
//	rules->addRule(Rule::parse("if velocity is very fast and visibility is good then propability is medicore", engine));
//	engine->addRuleBlock(rules);
//
//	std::string status;
//	if (not engine->isReady(&status))
//		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
//
//	scalar velocity = 175.0;
//	scalar sightness = 0.051;
//	for (size_t i = 0; i < 10; ++i)
//	{
//		speed->setValue(10*i+100);
//		sight->setValue(i);
//		engine->process();
//		FL_LOG("velocity.input = " << Op::str(i*10+200)
//			<< " ," << "sight.input = " << Op::str(i)
//			<< " propability.output = " << Op::str(engine->getOutputValue("propability")));
//	}
//
//
//	system("pause");
//	return 0;
//}

//
//
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
//	engine->setName("Air Condition AI");
//	engine->setDescription("");
//
//	InputVariable* temp_inside = new InputVariable;
//	temp_inside->setName("tempin");
//	temp_inside->setDescription("");
//	temp_inside->setEnabled(true);
//	temp_inside->setRange(10.000f, 30.000f);
//	temp_inside->setLockValueInRange(false);
//	temp_inside->addTerm(new Ramp("cold", 10.000f, 15.000f));
//	temp_inside->addTerm(new Ramp("chilly", 15.100f, 19.999f));
//	temp_inside->addTerm(new Ramp("hot", 20.000f, 30.000f));
//	engine->addInputVariable(temp_inside);
//
//	InputVariable* temp_outside = new InputVariable;
//	temp_outside->setName("tempout");
//	temp_outside->setDescription("");
//	temp_outside->setEnabled(true);
//	temp_outside->setRange(0.000f, 40.000f);
//	temp_outside->setLockValueInRange(false);
//	temp_outside->addTerm(new Ramp("cold", 0.000f, 15.000f));
//	temp_outside->addTerm(new Ramp("chilly", 15.100f, 19.999f));
//	temp_outside->addTerm(new Ramp("medium_hot", 20.000f, 30.000f));
//	temp_outside->addTerm(new Ramp("hot", 30.000f, 40.000f));
//	engine->addInputVariable(temp_outside);
//
//	OutputVariable* air_conditioner = new OutputVariable;
//	air_conditioner->setName("AC");
//	air_conditioner->setDescription("");
//	air_conditioner->setEnabled(true);
//	air_conditioner->setRange(10.0, 25.0);
//	air_conditioner->setLockValueInRange(false);
//	air_conditioner->setAggregation(new Maximum);
//	air_conditioner->setDefuzzifier(new Centroid());
//	air_conditioner->setDefaultValue(21.0);
//	air_conditioner->setLockPreviousValue(false);
//	air_conditioner->addTerm(new Ramp("cold", 10.0, 15.0));
//	air_conditioner->addTerm(new Ramp("chilly", 15.0, 19.9));
//	air_conditioner->addTerm(new Ramp("hot", 20.0, 25.0));
//	engine->addOutputVariable(air_conditioner);
//
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
//	rules->addRule(Rule::parse("if tempin is cold and tempout is cold then AC is hot", engine));
//	rules->addRule(Rule::parse("if tempin is cold and tempout is chilly then AC is chilly", engine));
//	rules->addRule(Rule::parse("if tempin is cold and tempout is hot then AC is chilly", engine));
//
//	rules->addRule(Rule::parse("if tempin is chilly and tempout is cold then AC is hot", engine));
//	rules->addRule(Rule::parse("if tempin is chilly and tempout is chilly then AC is chilly", engine));
//	rules->addRule(Rule::parse("if tempin is chilly and tempout is hot then AC is cold", engine));
//
//	rules->addRule(Rule::parse("if tempin is hot and tempout is cold then AC is chilly", engine));
//	rules->addRule(Rule::parse("if tempin is hot and tempout is chilly then AC is chilly", engine));
//	rules->addRule(Rule::parse("if tempin is hot and tempout is hot then AC is cold", engine));
//
//	engine->addRuleBlock(rules);
//
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
//		scalar temp_in = 10.0f;
//		scalar temp_out = 0.0f;
//
//		for (size_t i = 0; i < 3; ++i)
//		{
//			temp_out = 0;
//			for (size_t j = 0; j < 8; ++j)
//			{
//				temp_inside->setValue(temp_in);
//				temp_outside->setValue(temp_out);
//				engine->process();
//				FL_LOG("Temperature_inside.input = " << Op::str(temp_in) << " ," << "Temperature_outside.input = " << Op::str(temp_out) << " AC.output = " << engine->getOutputValue("AC") << '\n');
//				temp_out += 5.1f;
//			}
//			temp_in += 5.1f;
//		}
//	}
//
//	system("pause");
//	return 0;
//}


//podlewanie

#include "fl/Headers.h"
//#include <iostream>
//#include <string>
//#include <windows.h>

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
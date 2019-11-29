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
	engine->setName("Air Condition AI");
	engine->setDescription("");

	InputVariable* temp_inside = new InputVariable;
	temp_inside->setName("tempin");
	temp_inside->setDescription("");
	temp_inside->setEnabled(true);
	temp_inside->setRange(10.000f, 30.000f);
	temp_inside->setLockValueInRange(false);
	temp_inside->addTerm(new Ramp("cold", 10.000f, 15.000f));
	temp_inside->addTerm(new Ramp("chilly", 15.100f, 19.999f));
	temp_inside->addTerm(new Ramp("hot", 20.000f, 30.000f));
	engine->addInputVariable(temp_inside);

	InputVariable* temp_outside = new InputVariable;
	temp_outside->setName("tempout");
	temp_outside->setDescription("");
	temp_outside->setEnabled(true);
	temp_outside->setRange(0.000f, 40.000f);
	temp_outside->setLockValueInRange(false);
	temp_outside->addTerm(new Ramp("cold", 0.000f, 15.000f));
	temp_outside->addTerm(new Ramp("chilly", 15.100f, 19.999f));
	temp_outside->addTerm(new Ramp("medium_hot", 20.000f, 30.000f));
	temp_outside->addTerm(new Ramp("hot", 30.000f, 40.000f));
	engine->addInputVariable(temp_outside);

	OutputVariable* air_conditioner = new OutputVariable;
	air_conditioner->setName("AC");
	air_conditioner->setDescription("");
	air_conditioner->setEnabled(true);
	air_conditioner->setRange(10.0, 25.0);
	air_conditioner->setLockValueInRange(false);
	air_conditioner->setAggregation(new Maximum);
	air_conditioner->setDefuzzifier(new Centroid());
	air_conditioner->setDefaultValue(21.0);
	air_conditioner->setLockPreviousValue(false);
	air_conditioner->addTerm(new Ramp("cold", 10.0, 15.0));
	air_conditioner->addTerm(new Ramp("chilly", 15.0, 19.9));
	air_conditioner->addTerm(new Ramp("hot", 20.0, 25.0));
	engine->addOutputVariable(air_conditioner);


	RuleBlock* rules = new RuleBlock;
	rules->setName("rules");
	rules->setDescription("");
	rules->setEnabled(true);
	rules->setConjunction(new Minimum());
	rules->setDisjunction(fl::null);
	rules->setImplication(new AlgebraicProduct);
	rules->setActivation(new General);

	rules->addRule(Rule::parse("if tempin is cold and tempout is cold then AC is hot", engine));
	rules->addRule(Rule::parse("if tempin is cold and tempout is chilly then AC is chilly", engine));
	rules->addRule(Rule::parse("if tempin is cold and tempout is hot then AC is chilly", engine));

	rules->addRule(Rule::parse("if tempin is chilly and tempout is cold then AC is hot", engine));
	rules->addRule(Rule::parse("if tempin is chilly and tempout is chilly then AC is chilly", engine));
	rules->addRule(Rule::parse("if tempin is chilly and tempout is hot then AC is cold", engine));

	rules->addRule(Rule::parse("if tempin is hot and tempout is cold then AC is chilly", engine));
	rules->addRule(Rule::parse("if tempin is hot and tempout is chilly then AC is chilly", engine));
	rules->addRule(Rule::parse("if tempin is hot and tempout is hot then AC is cold", engine));

	engine->addRuleBlock(rules);



	//Before u are staring the engine, check status
	std::string status{};
	if (not engine->isReady(&status))
	{
		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
	}
	else
	{
		scalar temp_in = 10.0f;
		scalar temp_out = 0.0f;

		for (size_t i = 0; i < 3; ++i)
		{
			temp_out = 0;
			for (size_t j = 0; j < 8; ++j)
			{
				temp_inside->setValue(temp_in);
				temp_outside->setValue(temp_out);
				engine->process();
				FL_LOG("Temperature_inside.input = " << Op::str(temp_in) << " ," << "Temperature_outside.input = " << Op::str(temp_out) << " AC.output = " << engine->getOutputValue("AC") << '\n');
				temp_out += 5.1f;
			}
			temp_in += 5.1f;
		}
	}

	system("pause");
	return 0;
}
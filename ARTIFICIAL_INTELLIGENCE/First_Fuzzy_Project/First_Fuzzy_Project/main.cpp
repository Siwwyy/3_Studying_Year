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
	engine->setName("Propability of crash");
	engine->setDescription("");

	InputVariable* speed = new InputVariable;
	speed->setName("velocity");
	speed->setDescription("");
	speed->setEnabled(true);
	speed->setRange(10.000, 200.000);
	speed->setLockValueInRange(false);
	speed->addTerm(new Ramp("slow", 10.000, 40.000));
	speed->addTerm(new Ramp("medicore", 40.000, 90.000));
	speed->addTerm(new Ramp("fast", 90.000, 150.000));
	speed->addTerm(new Ramp("very fast", 150.000, 200.000));
	engine->addInputVariable(speed);

	InputVariable* sight = new InputVariable;
	sight->setName("visibility");
	sight->setDescription("");
	sight->setEnabled(true);
	sight->setRange(0.05, 4.0);
	sight->setLockValueInRange(false);
	sight->addTerm(new Ramp("bad", 0.05, 1.000));
	sight->addTerm(new Ramp("medicore", 1.000, 1.500));
	sight->addTerm(new Ramp("good", 1.500, 4.000));
	engine->addInputVariable(sight);

	OutputVariable* propability = new OutputVariable;
	propability->setName("propability");
	propability->setDescription("");
	propability->setEnabled(true);
	propability->setRange(0.000, 1.000);
	propability->setLockValueInRange(false);
	propability->setAggregation(new Maximum);
	propability->setDefuzzifier(new Centroid());
	propability->setDefaultValue(fl::nan);
	propability->setLockPreviousValue(false);
	propability->addTerm(new Ramp("small", 0.000, 0.300));
	propability->addTerm(new Ramp("medicore", 0.300, 0.600));
	propability->addTerm(new Ramp("high", 0.600, 1.000));
	engine->addOutputVariable(propability);


	RuleBlock* rules = new RuleBlock;
	rules->setName("rules");
	rules->setDescription("");
	rules->setEnabled(true);
	rules->setConjunction(new Minimum());
	rules->setDisjunction(fl::null);
	rules->setImplication(new AlgebraicProduct);
	rules->setActivation(new General);
	rules->addRule(Rule::parse("if velocity is slow and visibility is bad then propability is small", engine));
	rules->addRule(Rule::parse("if velocity is slow and visibility is medicore then propability is small", engine));
	rules->addRule(Rule::parse("if velocity is slow and visibility is good then propability is small", engine));
	rules->addRule(Rule::parse("if velocity is medicore and visibility is bad then propability is medicore", engine));
	rules->addRule(Rule::parse("if velocity is medicore and visibility is medicore then propability is small", engine));
	rules->addRule(Rule::parse("if velocity is medicore and visibility is good then propability is small", engine));
	rules->addRule(Rule::parse("if velocity is fast and visibility is bad then propability is high", engine));
	rules->addRule(Rule::parse("if velocity is fast and visibility is medicore then propability is medicore", engine));
	rules->addRule(Rule::parse("if velocity is fast and visibility is good then propability is small", engine));
	rules->addRule(Rule::parse("if velocity is very fast and visibility is bad then propability is high", engine));
	rules->addRule(Rule::parse("if velocity is very fast and visibility is medicore then propability is high", engine));
	rules->addRule(Rule::parse("if velocity is very fast and visibility is good then propability is medicore", engine));
	engine->addRuleBlock(rules);

	std::string status;
	if (not engine->isReady(&status))
		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);

	scalar velocity = 175.0;
	scalar sightness = 0.051;
	for (size_t i = 0; i < 10; ++i)
	{
		speed->setValue(10*i+100);
		sight->setValue(i);
		engine->process();
		FL_LOG("velocity.input = " << Op::str(i*10+200)
			<< " ," << "sight.input = " << Op::str(i)
			<< " propability.output = " << Op::str(engine->getOutputValue("propability")));
	}


	system("pause");
	return 0;
}
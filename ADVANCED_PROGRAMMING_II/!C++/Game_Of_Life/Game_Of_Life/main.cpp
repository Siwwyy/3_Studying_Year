#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cstdint>


#include "Logic.hpp"

//#include "Drawing.hpp"

int main(int argc, char* argv[])
{

	//using Creature::Animal;
	//using Creature::Sheep;
	//using Creature::Wolf;
	////using Engine::Keyboard_Event;


	////using namespace Engine;

	////Drawing Draw(30, 10);

	//////Draw.Draw_Area();
	////Draw.Draw_Object(29, 9, 'D');

	//Animal* an = new Sheep("d", 1, 1, "dd", true);
	//Animal* an2 = new Sheep("d", 1, 1, "dd", true);
	//Animal* an1 = new Wolf("d", 1, 1, "dd", true);

	//an->
	////Animal A;
	////A.
	////std::cout << typeid(*an).name() << '\n';
	////std::cout << typeid(*an1).name() << '\n';


	////dynamic_cast<Sheep&>(*an2) = dynamic_cast<Sheep&>(*an);
	////an->Move_Forwards();
	////an1->Move_Forwards();

	//std::cin.get();
	//Draw.Clear_Area();

	using Engine::Logic;

	Logic Obj(30, 10);
	Obj.Run_Game();

	system("pause");
	return EXIT_SUCCESS;
}
#include "Logic.hpp"

Engine::Logic::Logic(const int32_t width, const int32_t height):
	Draw(width,height),
	Key_Event()
{

}

Engine::Logic::Logic(const Logic& Object):
	Draw(Object.Draw),
	Key_Event(Object.Key_Event)
{

}

void Engine::Logic::Run_Game()
{
	bool is_not_end = true;
	int i = 0;
	while (is_not_end)
	{
		//Sheeps.insert(new Creature::Sheep("D", 0, 0, "not", false));
		Sheeps.emplace_back(new Creature::Sheep("D", 0, 0, "not", false));
		Draw.Draw_Object(Sheeps[i]->Get_Pos_X(), Sheeps[i]->Get_Pos_Y(), 'o');
	/*	Sleep(1000);*/
		Draw.Clear_Object(Sheeps[i]->Get_Pos_X(), Sheeps[i]->Get_Pos_Y());
		Sheeps[i]->Move_Forwards();
		i++;

	/*	if (Key_Event.Detect_Key(Keyboard_Event::Keys::W) == true)
		{
			is_not_end = false;
		}*/
	}
	Draw.Clear_Area();
}

Engine::Logic::~Logic()
{
	this->Sheeps.clear();
	Draw.Clear_Area();
}
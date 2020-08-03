#include "Logic.hpp"

void Engine::Logic::Draw_Objects()
{
	for (typename std::vector<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	{
		Draw.Draw_Object((*vec_iter)->Get_Pos_X(), (*vec_iter)->Get_Pos_Y(), 'o');
	}
}

void Engine::Logic::Clear_Objects()
{
	for (typename std::vector<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	{
		Draw.Clear_Object((*vec_iter)->Get_Pos_X(), (*vec_iter)->Get_Pos_Y());
	}
}

void Engine::Logic::Key()
{
	while (is_not_end)
	{
		if (Key_Event.Detect_Key(Keyboard_Event::Keys::ESC) == true)
		{
			is_not_end = false;
		}
	}
}

void Engine::Logic::Game()
{
	//Sheeps.insert(new Creature::Sheep("D", 0, 0, "not", false));
	Sheeps.emplace_back(new Creature::Sheep("D", 0, 0, "not", false));
	while (is_not_end)
	{
		Draw.Draw_Object(Sheeps[0]->Get_Pos_X(), Sheeps[0]->Get_Pos_Y(), 'o');
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		Draw.Clear_Object(Sheeps[0]->Get_Pos_X(), Sheeps[0]->Get_Pos_Y());
		Sheeps[0]->Move_Forwards();
	}
}

Engine::Logic::Logic(const int32_t width, const int32_t height) :
	Draw(width, height),
	Key_Event()
{

}

Engine::Logic::Logic(const Logic& Object) :
	Draw(Object.Draw),
	Key_Event(Object.Key_Event)
{

}

void Engine::Logic::Run_Game()
{
	std::thread t1(&Logic::Key,this);
	std::thread t2(&Logic::Game,this);

	t1.join();
	t2.join();

	Draw.Clear_Area();
}

Engine::Logic::~Logic()
{
	this->Sheeps.clear();
}
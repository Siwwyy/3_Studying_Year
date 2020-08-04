#include "Logic.hpp"

void Engine::Logic::Draw_Objects()
{
	//for (typename std::vector<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	//for (typename std::unordered_set<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	//{
	//	Draw.Draw_Object((*vec_iter)->Get_Pos_X(), (*vec_iter)->Get_Pos_Y(), 'o');
	//}
}

void Engine::Logic::Clear_Objects()
{
	//for (typename std::vector<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	//for (typename std::unordered_set<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	//{
	//	Draw.Clear_Object((*vec_iter)->Get_Pos_X(), (*vec_iter)->Get_Pos_Y());
	//}
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

void Engine::Logic::Move()
{
	//for (typename std::vector<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	/*for (typename std::unordered_set<Creature::Animal*>::const_iterator vec_iter = this->Sheeps.begin(); vec_iter != this->Sheeps.end(); ++vec_iter)
	{
		(*vec_iter)->Move_Forwards();
		
	}*/
}

void Engine::Logic::Add_Sheep()
{
	std::mt19937 rng(rand());
	std::uniform_int_distribution<int> uid_width(0, this->Draw.Get_Width() - 1);
	std::uniform_int_distribution<int> uid_height(0, this->Draw.Get_Height() - 1);
	Sheeps.insert(new Creature::Sheep("D", 0, 0, "Sheep", false));
	//Sheeps.insert(new Creature::Sheep("D", uid_width(rng), uid_height(rng), "Sheep", false));
}

void Engine::Logic::Game()
{
	while (is_not_end)
	{
		Add_Sheep();
		Draw_Objects();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

Engine::Logic::Logic(const int32_t width, const int32_t height) :
	Draw(width, height),
	Key_Event(),
	m_Wolf(new Creature::Wolf("Wolf", static_cast<int32_t>(0), static_cast<int32_t>(this->Draw.Get_Height()), "Wolf", true))
{

}

Engine::Logic::Logic(const Logic& Object) :
	Draw(Object.Draw),
	Key_Event(Object.Key_Event)
{

}

void Engine::Logic::Run_Game()
{
	std::thread t1(&Logic::Key, this);
	std::thread t2(&Logic::Game, this);

	t1.join();
	t2.join();

	Draw.Clear_Area();
}

Engine::Logic::~Logic()
{
	this->Sheeps.clear();
}
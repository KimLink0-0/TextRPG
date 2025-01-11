#include <iostream>
#include "FrameWorks.h"


using namespace std;

int main() 
{
	
	shared_ptr<GameMain> Game = GameMain::GetInstance();

	Game->Init();


	// IsGameEnded() 게임이 진행중이면 false,    !false = true
	while (!Game->IsGameEnded())
	{
		Game->Tick();
	}
	

	






	return 0;
}
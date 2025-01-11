#include <iostream>
#include "FrameWorks.h"


using namespace std;

int main() 
{
	
	shared_ptr<GameMain> Game = GameMain::GetInstance();

	Game->Init();


	while (!Game->IsGameEnded())
	{
		Game->Tick();
	}
	


	return 0;
}

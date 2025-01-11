#include "FrameWorks.h"

shared_ptr<GameMain> GameMain::instance = nullptr;



void GameMain::Init()
{

	GetManager<StageManager>()->Init();
	GetManager<EventManager>()->Init();



}


// 1 frame 에 할 일
void GameMain::Tick()
{
	system("cls");
	
	GetManager<StageManager>()->Tick();
	GetManager<EventManager>()->Tick();

	// 1. 선택지

			// 1. 전투 난이도 선택 (몬스터 종류← 로 선택하는 방식)
			// 2. 샵



	// 2. 선택

	// 3. 선택에 따른 실행



}

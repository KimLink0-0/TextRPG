#include "FrameWorks.h"

shared_ptr<GameMain> GameMain::instance = nullptr;



void GameMain::Init()
{

	GetManager<StageManager>()->Init();
	GetManager<EventManager>()->Init();



}


// 1 frame �� �� ��
void GameMain::Tick()
{
	system("cls");
	
	GetManager<StageManager>()->Tick();
	GetManager<EventManager>()->Tick();

	// 1. ������

			// 1. ���� ���̵� ���� (���� ������ �� �����ϴ� ���)
			// 2. ��



	// 2. ����

	// 3. ���ÿ� ���� ����



}

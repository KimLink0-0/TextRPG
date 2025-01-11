#include "StageManager.h"
#include "Stage.h"
#include "Stage_Start.h"

shared_ptr<StageManager> StageManager::instance = nullptr;


void StageManager::Init()
{


	CurrentStage = make_shared<Stage_Start>();

	CurrentStage->Init();


}

void StageManager::Tick()
{

	CurrentStage->Tick();


}

void StageManager::ChangeCurrentStage(EStageType NextStageType)
{
	switch (NextStageType)
	{
	case EStageType::StageStart:
	{
		CurrentStage = make_shared<Stage_Start>();
		break;
	}
	}
	CurrentStage->Init();
}

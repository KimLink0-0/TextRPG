#include "EventManager.h"
#include "FrameWorks.h"
#include "Stage.h"

shared_ptr<EventManager> EventManager::instance = nullptr;

void EventManager::ManageEvent()
{
	while (!EventQueue.empty()) 
	{
		const FEvent& CurrentEvent = EventQueue.front();

		switch (CurrentEvent.EventType)
		{
		case EEventType::ChangeStage:
		{
			EStageType NextStageType = *static_cast<EStageType*> (CurrentEvent.EventData1.get());
			GameMain::GetManager<StageManager>()->ChangeCurrentStage(NextStageType);
			

			break;
		}
		}

		EventQueue.pop();
	}
}

void EventManager::Init()
{

}

void EventManager::Tick()
{

	ManageEvent();

}

#pragma once
#include "Selectable.h"
#include "Stage_Start.h"
#include "FrameWorks.h"




class Selectable_Start : public Selectable
{
private:

	EStageType NextStageType;


	void ChangeStage()
	{
		FEvent Event(EEventType::ChangeStage, shared_ptr<void>(new EStageType(NextStageType), [](void* p)
		{
			EStageType* Ptr = static_cast<EStageType*>(p);
			delete Ptr;
		}));


		GameMain::GetManager<EventManager>()->AddEvent(Event);
	}




public:
	Selectable_Start()
	{
		SetName("Start");
		NextStageType = EStageType::StageStart;
	}


	virtual void Execute()
	{
		ChangeStage();
	}





};


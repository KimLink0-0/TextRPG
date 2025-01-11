#pragma once
#include <memory>
#include <queue>

using namespace std;

// 이벤트 타입이 몇개인지 체크하기 위해
enum class EEventType
{
	ChangeStage,
	End
};

struct FEvent
{
	FEvent(EEventType InEventType, shared_ptr<void> InEventData1 = nullptr, shared_ptr<void> InEventData2 = nullptr)
		: EventType(InEventType)
		, EventData1(InEventData1)
		, EventData2(InEventData2)
	{

	}

	EEventType EventType;

	shared_ptr<void> EventData1;
	shared_ptr<void> EventData2;

};

class EventManager
{
private:
	EventManager() = default;
	~EventManager() = default;

	static void Deleter(EventManager* ptr) 
	{
		delete ptr;
	}

	EventManager(EventManager& other) = delete;
	EventManager& operator = (const EventManager& other) = delete;


	static shared_ptr<EventManager> instance;

	static shared_ptr<EventManager> GetInstance()
	{
		if (nullptr == instance)
		{
			instance = shared_ptr<EventManager>(new EventManager(), Deleter);
		}
		return instance;
	}

	friend class GameMain;





private:

	//선입선출 FIFO
	queue<FEvent> EventQueue;

	void ManageEvent();

	

public:

	void AddEvent(const FEvent& Event)
	{
		EventQueue.push(Event);
	}
		

	void Init();

	void Tick();

};


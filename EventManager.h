#pragma once
#include <memory>
#include <queue>

using namespace std;

// �̺�Ʈ Ÿ���� ����� üũ�ϱ� ����
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

	//���Լ��� FIFO
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


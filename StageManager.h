#pragma once
#include <memory>


using namespace std;

class Stage;

enum class EStageType;



class StageManager
{

private:
	StageManager() = default;
	~StageManager() = default;
	
	
	static void Deleter(StageManager* ptr)
	{
		delete ptr;
	}


	StageManager(StageManager& other) = delete;
	StageManager& operator = (const StageManager& other) = delete;


	static shared_ptr<StageManager> instance;


	static shared_ptr<StageManager> GetInstance()
	{
		if (nullptr == instance)
		{
			instance = shared_ptr<StageManager>(new StageManager(), Deleter);
		}
		return instance;
	}


	friend class GameMain;



private:

	

	shared_ptr<Stage> CurrentStage;





public:

	void Init();


	void Tick();


	void ChangeCurrentStage(EStageType NextStageType);



};


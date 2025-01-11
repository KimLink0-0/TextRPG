#pragma once
#include <memory>
#include "StageManager.h"
#include "EventManager.h"

using namespace std;

class GameMain
{

private:
	// 외부에서 생성자에 접근하지 못하게 private 로 막음
	GameMain() = default;
	~GameMain() = default;

	static void Deleter(GameMain* ptr)
	{
		delete ptr;
	}

	// 복사 생성자랑 대입 연산자 막기

	// 생성자가 동일한 객체를 복사해서 생성하는 것을 막는다
	GameMain(const GameMain& other) = delete;

	// 가리키는 값이 바뀌지 않는 다는 것을 보장, 즉 본체는 데이터의 일관성을 유지 
	// 다른 객체에 덮어쓰기를 방지하며 복사본 생성을 방지
	GameMain& operator = (const GameMain& other) = delete;


	// 클래스의 static 변수는 언제 파괴될까? -> 만들 때부터 존재 -> 종료할 때 파괴
	// shared_ptr 을 사용할 때 헤맨 이유, 템플릿처럼 작성하면 되는 줄 몰랐음 << 
	// 포인터로 객체를 만드는 이유 : 동적 메모리 할당을 하면, 필요할 때 객체를 생성하는 방식으로 구현이 가능해짐
	// 정적 객체로 만들지 않는 이유 : 정적 객체들 간 초기화 순서를 예측하기 어렵고 의존 관계에 있을 경우 버그 발생 가능성이 있음 (글로는 알겠는데 예시가 없어서 이해가 안 됨)
	// static 을 사용하여 만드는 이유 : 싱글톤의 전역적 접근 가능성을 만들어주기 위해
	static shared_ptr<GameMain> instance;


	// 가리키는 대상이 바뀌지 않는 다는 것을 보장
public:
	static shared_ptr<GameMain> GetInstance()
	{
		if (nullptr == instance)
		{
			// Deleter 가 필요한 이유는, private 로 소멸자가 호출되지 않아기 때문에 refCount = 0 일 때 직접적으로 데이터 해제 작업을 해야하기 때문
			instance = shared_ptr<GameMain>(new GameMain(), Deleter);
		}

		return instance;
	}


	template<typename T>
	static shared_ptr<T> GetManager()
	{
		if (GameMain::instance == nullptr)
		{
			return nullptr;
		}

		// static 함수를 사용하는 방법, 타입에 :: 를 적어서 사용
		return T::GetInstance();
	}

	


private:



	// static instance 의 멤버 변수이기 때문에 static 을 적지 않아도 된다
	bool bIsGameEnded;

	
	


public:

	
	void Init();


	void Tick(); 


	bool IsGameEnded()			// getter bIsGameEnded 값을 가져오고
	{
		return bIsGameEnded;
	}

	
	void EndGame()				// setter bIsGameEnded 값을 설정한다, setter 는 일반적으로 매개변수를 받아서 true, false 를 자유롭게 변경할 수 있어야 한다.
	{
		bIsGameEnded = true;
	}


};


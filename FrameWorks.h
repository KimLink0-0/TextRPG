#pragma once
#include <memory>
#include "StageManager.h"
#include "EventManager.h"

using namespace std;

class GameMain
{

private:
	// �ܺο��� �����ڿ� �������� ���ϰ� private �� ����
	GameMain() = default;
	~GameMain() = default;

	static void Deleter(GameMain* ptr)
	{
		delete ptr;
	}

	// ���� �����ڶ� ���� ������ ����

	// �����ڰ� ������ ��ü�� �����ؼ� �����ϴ� ���� ���´�
	GameMain(const GameMain& other) = delete;

	// ����Ű�� ���� �ٲ��� �ʴ� �ٴ� ���� ����, �� ��ü�� �������� �ϰ����� ���� 
	// �ٸ� ��ü�� ����⸦ �����ϸ� ���纻 ������ ����
	GameMain& operator = (const GameMain& other) = delete;


	// Ŭ������ static ������ ���� �ı��ɱ�? -> ���� ������ ���� -> ������ �� �ı�
	// shared_ptr �� ����� �� ��� ����, ���ø�ó�� �ۼ��ϸ� �Ǵ� �� ������ << 
	// �����ͷ� ��ü�� ����� ���� : ���� �޸� �Ҵ��� �ϸ�, �ʿ��� �� ��ü�� �����ϴ� ������� ������ ��������
	// ���� ��ü�� ������ �ʴ� ���� : ���� ��ü�� �� �ʱ�ȭ ������ �����ϱ� ��ư� ���� ���迡 ���� ��� ���� �߻� ���ɼ��� ���� (�۷δ� �˰ڴµ� ���ð� ��� ���ذ� �� ��)
	// static �� ����Ͽ� ����� ���� : �̱����� ������ ���� ���ɼ��� ������ֱ� ����
	static shared_ptr<GameMain> instance;


	// ����Ű�� ����� �ٲ��� �ʴ� �ٴ� ���� ����
public:
	static shared_ptr<GameMain> GetInstance()
	{
		if (nullptr == instance)
		{
			// Deleter �� �ʿ��� ������, private �� �Ҹ��ڰ� ȣ����� �ʾƱ� ������ refCount = 0 �� �� ���������� ������ ���� �۾��� �ؾ��ϱ� ����
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

		// static �Լ��� ����ϴ� ���, Ÿ�Կ� :: �� ��� ���
		return T::GetInstance();
	}

	


private:



	// static instance �� ��� �����̱� ������ static �� ���� �ʾƵ� �ȴ�
	bool bIsGameEnded;

	
	


public:

	
	void Init();


	void Tick(); 


	bool IsGameEnded()			// getter bIsGameEnded ���� ��������
	{
		return bIsGameEnded;
	}

	
	void EndGame()				// setter bIsGameEnded ���� �����Ѵ�, setter �� �Ϲ������� �Ű������� �޾Ƽ� true, false �� �����Ӱ� ������ �� �־�� �Ѵ�.
	{
		bIsGameEnded = true;
	}


};


#pragma once
#include <memory>
#include "Selectable.h"
#include <vector>
#include <iostream>

using namespace std;

enum class EStageType
{
	StageStart,
	End
};

extern string SStageName[(int)EStageType::End];

class Stage
{
protected:
	vector<shared_ptr<Selectable>> Selectables;
	



private:

	void DisplaySelectable()
	{

		for (int i = 0; i < Selectables.size(); ++i)
		{
			cout << i+1 << ". " << Selectables[i]->GetName() << "\n" ;
		}

	}


public:

	virtual void Init() = 0;

	virtual void Tick();

	void Select();

};


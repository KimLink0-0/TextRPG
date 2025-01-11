#pragma once
#include <string>

using namespace std;

class Selectable
{

private:
	string Name;


protected:
	void SetName(const string& newName)
	{
		Name = newName;
	}


public:

	virtual void Execute() = 0;

	const string& GetName()
	{
		return Name;
	}

};

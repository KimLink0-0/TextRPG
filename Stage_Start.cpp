#include "Stage_Start.h"
#include "Selectable_Start.h"

void Stage_Start::Init()
{


	Selectables.push_back(make_shared<Selectable_Start>());
	Selectables.push_back(make_shared<Selectable_Start>());
	Selectables.push_back(make_shared<Selectable_Start>());
	Selectables.push_back(make_shared<Selectable_Start>());
	Selectables.push_back(make_shared<Selectable_Start>());


}

void Stage_Start::Tick()
{
	Stage::Tick();
}

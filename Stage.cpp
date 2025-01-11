#include "Stage.h"

extern string SStageName[(int)EStageType::End] =
{
	"StageStart",
};

void Stage::Tick()
{

	DisplaySelectable();
	Select();

}

void Stage::Select()
{

	int InputSelect;
	bool bIsRetry = false;

	
	while (true)
	{
		cin >> InputSelect;

		if (InputSelect >= 1 && InputSelect <= Selectables.size())
		{
			Selectables[InputSelect - 1]->Execute();
			break;
		}
		else
		{
			// �� �� ���� Ŀ�� �̵� �� ����� 
			cout << "\33[" << 1 << "A" << flush;
			cout << "\33[2K\r" << flush;


			if (false == bIsRetry)
			{
				cout << "�ٽ� �������ּ���. \n";
				bIsRetry = true;
			}
		}	
	}
}

#include <iostream>
#include "CMyListEx.h"
//#include "listArray.cpp"
using namespace std;

void StartMenu(CMyListEx** listArray);
void MakeList(CMyListEx** listArray);
void CopyList(CMyListEx** listArray);
void CoverList(CMyListEx** listArray);
void EditList(CMyListEx** listArray, int inputNum);


int main()
{
	CMyListEx* listArray[10];
	int inputNum;

	while (1)
	{
		StartMenu(listArray);
		cin >> inputNum;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << " �޴� ���� �ִ� ���ڸ� �Է��ϼ��� : ";
			continue;
		}

		switch (inputNum)
		{
		case 1:
			MakeList(listArray);
			break;
		case 2:
			CopyList(listArray);
			break;
		case 3:
			CoverList(listArray);
			break;
		case 0: cout << " �����մϴ�!\n";
			for (int i = 0; i < CMyListEx::listCount; i++)
				delete listArray[i];
			return 0;
		default:
			if (inputNum > 0 && inputNum <= CMyListEx::listCount + 3)
			{
				EditList(listArray, inputNum);
				break;
			}
			else
			{
				cout << "\n �޴� ���� �ִ� ���ڸ� �Է��ϼ���!" << endl;
				continue;
			}
		}
	}
	return 0;
}
//0 O I l | L 1

void StartMenu(CMyListEx** listArray)
{
	cout << "\n-----------------" << endl;
	cout << "����Ʈ �޴�" << endl;
	cout << "1 �� ����Ʈ �����" << endl;
	cout << "2 ����Ʈ ����" << endl;
	cout << "3 ����Ʈ ���� ����" << endl;
	if (CMyListEx::listCount)
		cout << "-����Ʈ ����-" << endl;
	//cout << CMyListEx::listCount << endl;
	for (int i = 0; i < CMyListEx::listCount; i++)
		cout << i + 4 << " " << listArray[i]->GetName() << endl;
	cout << "\n0 ����" << endl;
	cout << "-----------------" << endl;
	cout << " �޴��� ������(���� �Է�) : ";
}

void MakeList(CMyListEx** listArray)
{
	string subInputStr;
	int subInputNum;

	cout << "\n ����Ʈ�� �̸��� �Է��ϼ��� : ";
	cin >> subInputStr;
	cout << " ����Ʈ�� ù ���� �Է��ϼ��� : ";
	cin >> subInputNum;
	listArray[CMyListEx::listCount] = new CMyListEx(subInputNum);
	listArray[CMyListEx::listCount]->SetName(subInputStr);
	CMyListEx::listCount++;
}

void CopyList(CMyListEx** listArray)
{
	int listIndex;
	if (!CMyListEx::listCount)
	{
		cout << "\n ������ ����Ʈ�� �����ϴ�!" << endl;
		return;
	}
	cout << "\n-----------------" << endl;
	cout << "����Ʈ ����" << endl;
	for (int i = 0; i < CMyListEx::listCount; i++)
		cout << i + 1 << " " << listArray[i]->GetName() << endl;
	cout << "0 ������" << endl;
	cout << "-----------------" << endl;
	cout << " ������ ����Ʈ�� ������(���� �Է�) : ";

	cin >> listIndex;
	if (listIndex <= 0 || listIndex > CMyListEx::listCount)
		return;
	listArray[CMyListEx::listCount] = new CMyListEx(*listArray[listIndex - 1]);
	CMyListEx::listCount++;

}

void CoverList(CMyListEx** listArray)
{
	int listIndex;
	string subInputStr;

	if (!CMyListEx::listCount)
	{
		cout << "\n ���� �� ����Ʈ�� �����ϴ�!" << endl;
		return;
	}
	cout << "\n-----------------" << endl;
	cout << "����Ʈ ���� ����" << endl;
	for (int i = 0; i < CMyListEx::listCount; i++)
		cout << i + 1 << " " << listArray[i]->GetName() << endl;
	cout << "0 ������" << endl;
	cout << "-----------------" << endl;
	cout << " ���� �� ����Ʈ�� ������(���� �Է�) : ";

	cin >> listIndex;
	if (listIndex <= 0 || listIndex > CMyListEx::listCount)
		return;

	cout << "\n �� ����Ʈ�� �̸��� �Է��ϼ��� : ";
	cin >> subInputStr;

	CMyListEx* del = listArray[listIndex - 1];
	listArray[listIndex - 1] = new CMyListEx();
	listArray[listIndex - 1]->SetName(subInputStr);
	delete del;
}

void EditList(CMyListEx** listArray, int inputNum)
{
	CMyListEx* edit = listArray[inputNum - 4];
	int num;
	while (1)
	{
		edit->ShowMenu();
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\n �޴� ���� �ִ� ���ڸ� �Է��ϼ���!" << endl;
			continue;
		}
		switch (num)
		{
		case 1: edit->InsertFront();
			break;
		case 2: edit->InsertBack();
			break;
		case 3: edit->DeleteFront();
			break;
		case 4: edit->DeleteBack();
			break;
		case 5: edit->Print();
			break;
		case 6: edit->PrintReverse();
			break;
		case 0:
			return;
		default:
			cout << "\n �޴� ���� �ִ� ���ڸ� �Է��ϼ���!" << endl;
			continue;
		}
	}
}
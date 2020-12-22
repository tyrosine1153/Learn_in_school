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
			cout << " 메뉴 내에 있는 숫자를 입력하세요 : ";
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
		case 0: cout << " 종료합니다!\n";
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
				cout << "\n 메뉴 내에 있는 숫자를 입력하세요!" << endl;
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
	cout << "리스트 메뉴" << endl;
	cout << "1 새 리스트 만들기" << endl;
	cout << "2 리스트 복사" << endl;
	cout << "3 리스트 덮어 쓰기" << endl;
	if (CMyListEx::listCount)
		cout << "-리스트 편집-" << endl;
	//cout << CMyListEx::listCount << endl;
	for (int i = 0; i < CMyListEx::listCount; i++)
		cout << i + 4 << " " << listArray[i]->GetName() << endl;
	cout << "\n0 종료" << endl;
	cout << "-----------------" << endl;
	cout << " 메뉴를 고르세요(숫자 입력) : ";
}

void MakeList(CMyListEx** listArray)
{
	string subInputStr;
	int subInputNum;

	cout << "\n 리스트의 이름을 입력하세요 : ";
	cin >> subInputStr;
	cout << " 리스트의 첫 값을 입력하세요 : ";
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
		cout << "\n 복사할 리스트가 없습니다!" << endl;
		return;
	}
	cout << "\n-----------------" << endl;
	cout << "리스트 복사" << endl;
	for (int i = 0; i < CMyListEx::listCount; i++)
		cout << i + 1 << " " << listArray[i]->GetName() << endl;
	cout << "0 나가기" << endl;
	cout << "-----------------" << endl;
	cout << " 복사할 리스트를 고르세요(숫자 입력) : ";

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
		cout << "\n 덮어 쓸 리스트가 없습니다!" << endl;
		return;
	}
	cout << "\n-----------------" << endl;
	cout << "리스트 덮어 쓰기" << endl;
	for (int i = 0; i < CMyListEx::listCount; i++)
		cout << i + 1 << " " << listArray[i]->GetName() << endl;
	cout << "0 나가기" << endl;
	cout << "-----------------" << endl;
	cout << " 덮어 쓸 리스트를 고르세요(숫자 입력) : ";

	cin >> listIndex;
	if (listIndex <= 0 || listIndex > CMyListEx::listCount)
		return;

	cout << "\n 새 리스트의 이름을 입력하세요 : ";
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
			cout << "\n 메뉴 내에 있는 숫자를 입력하세요!" << endl;
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
			cout << "\n 메뉴 내에 있는 숫자를 입력하세요!" << endl;
			continue;
		}
	}
}
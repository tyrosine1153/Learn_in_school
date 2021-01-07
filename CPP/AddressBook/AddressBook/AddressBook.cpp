// Addresbook.cpp
#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define DATA_FILE_NAME "Address.dat"  // 주소록에 저장될 파일

///////////////////////////////////////////////////////
struct USERDATA {
	char szName[32];
	char szPhone[32];
	USERDATA* pNext;
};

// Head, Tail 포인터 선언 및 정의
USERDATA* pHead = nullptr;
USERDATA* pTail = nullptr;

///////////////////////////////////////////////////////
//함수 선언
USERDATA* FindNode(char* pszName);
int AddNewNode(char* pszName, char* pszPhone);
void Add();
void Search();
void PrintAll();
int RemoveNode(char* pszName);
void Remove();
int PrintUI();
int LoadList(const char* pszFileName);
int SaveList(const char* pszFileName);
void ReleaseList();

///////////////////////////////////////////////////////////
int main() {
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	// 메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:  //add
			Add();
			break;
		case 2:  //search
			Search();
			break;
		case 3:  //print all
			PrintAll();
			break;
		case 4:  //remove
			Remove();
			break;
		default:
			break;
		}
	}
	//종료전에 파일로 저장하고 메모리를 해제한다.
	SaveList(DATA_FILE_NAME);
	ReleaseList();
	return 0;
}

////////////////////////////////////////////////////////
// 함수 정의

// 리스트에서 이름으로 특정 노드를 검색하는 함수
USERDATA* FindNode(char* pszName) {
	USERDATA* pTmp = pHead;
	while (pTmp != NULL) {
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;
		// 다음 노드로 이동
		pTmp = pTmp->pNext;
	}
	return NULL;
}

int AddNewNode(char* pszName, char* pszPhone) {
	USERDATA* pNewUser = NULL;

	// 같은 이름이 이미 존재하는지 확인
	if (FindNode(pszName) != NULL)
		return 0;

	// 메모리 확보
	pNewUser = new USERDATA;
	memset(pNewUser, 0, sizeof(USERDATA));

	// 메모리에 값 저장
	sprintf(pNewUser->szName, "%s", pszName);
	sprintf(pNewUser->szPhone, "%s", pszPhone);
	pNewUser->pNext = nullptr;

	// 새로운 노드가 리스트 마지막에 삽입된다
	if (pTail == nullptr)
		pHead = pNewUser;
	else
		pTail->pNext = pNewUser;

	pTail = pNewUser;

	return 1;
}

///////////////////////////////////////////////////////
// 이름을 입력받아 리스트에 추가하는 함수
void Add() {
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };
	cout << "Input Name : ";
	fflush(stdin);
	cin >> szName;

	cout << "Input Phone Number";
	fflush(stdin);
	cin >> szPhone;

	AddNewNode(szName, szPhone);
}

////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search() {
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	cout << "Input Name : ";
	fflush(stdin);
	cin >> szName;

	pNode = FindNode(szName);
	if (pNode != NULL) {
		cout << "[" << pNode << "]" << pNode->szName << "\t"
			<< pNode->szPhone << "[" << pNode->pNext << "]\n";
	}
	else
		cout << "ERROR : 데이터를 찾을 수 없습니다.";

	cin.get();
}

////////////////////////////////////////////////////////////////
// 리스트에 들어있는 모든 데이터를 화면에 출력
void PrintAll() {
	USERDATA* pTmp = pHead;

	while (pTmp != NULL) {
		cout << "[" << pTmp << "]" << pTmp->szName << "\t"
			<< pTmp->szPhone << "[" << pTmp->pNext << "]\n";
		pTmp = pTmp->pNext;
	}

	cin.get();
}

////////////////////////////////////////////////////////////////
// 특정 노드를 검색하고 삭제하는 함수
int RemoveNode(char* pszName) {
	USERDATA* pPrevNode = nullptr;
	USERDATA* pDelete = pHead;

	while (pDelete!=NULL) {
		if (strcmp(pDelete->szName, pszName) == 0) {
			if (pPrevNode == nullptr)  // 삭제 노드가 처음 노드일때
				pHead = pDelete->pNext;
			else {
				if (pDelete == pTail)  //  삭제 노드가 마지막 노드일때
					pTail = pPrevNode;
				pPrevNode->pNext = pDelete->pNext;
			}
			delete pDelete;
			return 1;
		}
		pPrevNode = pDelete;
		pDelete = pDelete->pNext;
	}
}

////////////////////////////////////////////////////////////////
//이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove() {
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	cout << "Input Name : ";
	fflush(stdin);
	cin >> szName;

	RemoveNode(szName);
}

////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 User Interface 함수
int PrintUI() {
	int nInput = 0;

	cout << "\n[1]Add  [2]Search  [3]Print all  [4]Remove  [0]Exit\n";

	// 사용자가 선택한 메뉴의 값을 반환한다
	cin >> nInput;
	return nInput;
}

////////////////////////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 리스트를 완성하는 함수
int LoadList(const char* pszFileName) {
	FILE* fp = NULL;
	USERDATA user = { 0 };

	fp = fopen(pszFileName, "rb");
	if (fp == NULL)
		return 0;

	ReleaseList();

	while (fread(&user,sizeof(USERDATA),1,fp)) {
		AddNewNode(user.szName, user.szPhone);
	}

	fclose(fp);
	return 0;
}


int SaveList(const char* pszFileName);
void ReleaseList();
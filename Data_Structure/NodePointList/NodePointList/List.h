#ifndef _LIST_H_ //"List.h"
#define _LIST_H_

void InitList(List*); //����Ʈ�� �ʱ�ȭ
void LInsert(List*, Ldata); //�ڷ� ����
int LFirst(List*, Ldata); //ù �ڷ�?
int LNext(List*, Ldata); //���� �ڷ�?

Ldata LRemove(List*); //�ڷ� ����
void LPrint(List*); //����Ʈ �ڷ� ���
int LCount(List*); //����Ʈ �ڷ� ����
//���� ��Ģ
void SetSortRule(List*, int (*comp)(Ldata, Ldata));

#endif
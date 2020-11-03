#ifndef _LIST_H_
#define _LIST_H_

void InitList(List*);
void LInsert(List*, Ldata);
int LFirst(List*, Ldata);
int LNext(List*, Ldata);
Ldata LRemove(List*);
void LPrint(List*);
int LCount(List*);
void SetSortRule(List*, int (*comp)(Ldata, Ldata));

#endif

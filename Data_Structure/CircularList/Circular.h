#ifndef _CIRCULAR_H_
#define _CIRCULAR_H_

typedef struct _node {
    char Item;
    struct _node* Next;
}Node;

typedef Node* Ldata;

typedef struct _list {
    Ldata Tail;
    Ldata Before;
    Ldata Cur;
    int NumOfData;
    int (*func)(Ldata, Ldata);
}List;
#endif

#ifndef _POINT_H_ //"Point.h"
#define _POINT_H_

typedef struct _point {
	int x, y;
	struct _point* Next;
} Point;

typedef Point* Ldata;

typedef struct _list {
	Ldata Head, Before, Cur;
	int NumOfData;
	int (*comp)(Ldata, Ldata);
} List;

#endif
#ifndef LIST_H
#define LIST_H

#define N 10
#include<stdlib.h>
#include<stdio.h>

typedef struct list{
	double _value;			
	struct list* _next;
}list;
typedef list* LL;
 

#endif
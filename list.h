#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
void showtaks();

typedef struct
{
    char buffer[100];
    char time[50];
    int state;
} Data;

typedef struct List
{
    Data data;
    struct List *next;
} node, *nodeptr;
#endif // LIST_H

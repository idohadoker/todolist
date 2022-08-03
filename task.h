#ifndef TASK_H
#define TASK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
typedef struct
{
    int position;
    char buffer[100];
    char time[50];
    int state;
} Task;
int deletetasknumber();
void edittask();
Task createtask();

#endif
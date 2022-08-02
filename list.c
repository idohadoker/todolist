#include "list.h"
void options();
void createtask();
void edittask();
void deletetask();
void mark_as_done();
nodeptr list = NULL;

int main(int argc, char const *argv[])
{

    options();
    return 0;
}

void options()
{
    int option;
    while (1)
    {
        system("clear");
        printf("Choose Option\n");
        printf("1|-Show Tasks\n2|-Create a new task\n3|-Edit Task\n4|-Delete Task\n5|-Mark AS Done\n");
        scanf(" %d", &option);
        switch (option)
        {
        case 1:
            showtaks();
            break;
        case 2:
            createtask();
            break;
        case 3:
            edittask();
            break;
        case 4:
            deletetask();
            break;
        case 5:
            mark_as_done();
            break;

        default:
            break;
        }
        getchar();
    }
}

void createtask()
{

    system("clear");
    printf("\n-------------------------Create Task-------------------------\n");
    printf("enter new task\n");
    char new_task[100];

    scanf(" %99[a-zA-Z0-9 ]", new_task);

    nodeptr new_node = (nodeptr)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failure\n");
        exit(1);
    }
    new_node->next = NULL;
    strncpy(new_node->data.buffer, new_task, sizeof(new_task));
    new_node->data.state = 0;
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strncpy(new_node->data.time, asctime(timeinfo), 50);
    if (list == NULL)
    {
        list = (nodeptr)malloc(sizeof(node));
        if (list == NULL)
        {
            printf("Memory allocation failure\n");
            exit(1);
        }
        *list = *new_node;
    }
    else
    {
        nodeptr pos = list;
        while (pos->next != NULL)
        {
            pos = pos->next;
        }
        pos->next = malloc(sizeof(node));
        if (pos->next == NULL)
        {
            printf("Memory allocation failure\n");
            exit(1);
        }

        *pos->next = *new_node;
    }

    free(new_node);
    sleep(2);
}
// edit task and time
void edittask()
{
    system("clear");

    printf("\n-------------------------Edit Task-------------------------\n");
}

// delete task
void deletetask()
{
    system("clear");

    printf("\n-------------------------Delete Task-------------------------\n");
    sleep(1);
}
// show all tasks
void showtaks()
{
    system("clear");
    printf("\n-------------------------Show Tasks-------------------------\n");
    if (list == NULL)
    {
        printf("no tasks available\n");
        sleep(3);
    }
    nodeptr pos = list;
    int i = 1;

    while (pos)
    {
        printf("\n Task %d Time|- %s\t", i++, pos->data.time);
        printf("|- %s\t", pos->data.buffer);
        switch (pos->data.state)
        {
        case 0:
            printf("\t not done\n");
            break;
        case 1:
            printf("\t done\n");
            break;
        default:
            break;
        }
        fflush(stdout);
        pos = pos->next;
    }
    printf("\n press enter to key continue...\n");
    getchar();
}

// mark task as done
void mark_as_done()
{
}
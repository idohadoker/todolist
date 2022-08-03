#include "list.h"
void options();
void edittask();
void mark_as_done();
void showtasks();
void print_task();
nodeptr list = NULL;
int length = 0;

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
            showtasks();
            break;
        case 2:
            addtask();
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
void addtask()
{
    int i = 0;

    system("clear");
    printf("\n-------------------------Create Task-------------------------\n");
    printf("enter new task (type exit to leave)\n");

    nodeptr new_node = (nodeptr)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failure\n");
        exit(1);
    }
    new_node->next = NULL;
    new_node->data = createtask();
    if (strncmp(new_node->data.buffer, "exit", 5) != 0)
    {

        if (list == NULL)
        {
            new_node->data.position = i;
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
                pos->data.position = i++;
                pos = pos->next;
            }
            pos->next = malloc(sizeof(node));
            if (pos->next == NULL)
            {
                printf("Memory allocation failure\n");
                exit(1);
            }
            new_node->data.position = i;
            *pos->next = *new_node;
        }

        free(new_node);
        length++;
    }
    sleep(2);
}

// edit task and time
void edittask()
{
    int task, i;
    char new_task[100];
    nodeptr pos = list;
    system("clear");
    printf("\n-------------------------Edit Tasks-------------------------\n");
    print_task();
    printf("\n Enter task to change (press 0 to leave)\n");
    scanf("%d", &task);
    if (task == 0)
    {
        printf("leaving program\n");
    }
    else
    {
        if (task <= length)
        {
            printf("\n Enter new task \n");
            scanf(" %99[a-zA-Z0-9 ]", new_task);

            pos = list;
            i = 0;
            while (pos && i < task - 1)
            {
                pos = pos->next;
                i++;
            }
            strncpy(pos->data.buffer, new_task, 100);
            pos->data.state = 0;
            time_t rawtime;
            struct tm *timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strncpy(pos->data.time, asctime(timeinfo), 50);
        }
    }
    sleep(2);
}
// delete task list
void deletetask()
{
    int i;
    int task;
    system("clear");
    print_task();
    nodeptr pos = list;
    pos = list;
    i = 0;
    task = deletetasknumber();
    if (task == 0)
    {
        if (task <= length)
        {
            nodeptr temp = list;
            if (task - 1 == 0)
            {

                list = list->next;
                temp->next = NULL;
                free(temp);
            }
            else
            {
                for (i = 0; i < task - 2; i++)
                {
                    temp = temp->next;
                }
                nodeptr del = temp->next;
                temp->next = temp->next->next;
                del->next = NULL;
                free(del);
            }
            length--;
        }
    }
    sleep(2);
}

// show all tasks
void showtasks()
{
    system("clear");
    printf("\n-------------------------Show Tasks-------------------------\n");
    print_task();

    printf("\n press enter to key continue...\n");
    getchar();
}

// mark task as done
void mark_as_done()
{
    int task, i;
    nodeptr pos;
    system("clear");
    printf("\n-------------------------Mark AS DONE-------------------------\n");
    print_task();
    printf("\n Enter task to mark (press 0 to leave)\n");
    scanf("%d", &task);
    if (task == 0)
    {
        printf("leaving program\n");
    }
    else
    {
        pos = list;
        i = 0;
        while (i < task - 1)
        {
            pos = pos->next;
            i++;
        }
        if (pos->data.state == 0)
            pos->data.state = 1;
    }
    sleep(2);
}

void print_task()
{
    int i;
    if (list == NULL)
    {
        printf("no tasks available\n");
        sleep(3);
    }
    else
    {
        nodeptr pos = list;
        i = 0;

        while (pos)
        {
            pos->data.position = i++;
            printf("\n Task %d Time|- %s\t", pos->data.position + 1, pos->data.time);
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
            pos = pos->next;
        }
    }
}
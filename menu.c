#include<stdio.h>

#define DESC_LEN 50
#define CMD_NUM 10

typedef struct DataNode
{
    int cmd;
    char descpt[DESC_LEN];
    struct DataNode* next;
} tDataNode;

int main()
{
    tDataNode *head = NULL;
    tDataNode *p = NULL;
    int i;    
    /* Init Command List */
    for(i=0; i<CMD_NUM; i++)
    {
        p = (tDataNode*)malloc(sizeof(tDataNode));
        p->cmd = i;
        snprintf(p->descpt, DESC_LEN, "This is Command %d.", i);
        p->next = head;
        head = p;    
    }
    printf("Menu List:\n");
    p = head;
    while(p != NULL)
    {
        printf("%d--%s\n", p->cmd, p->descpt);
        p = p->next;
    } 
    /* Command Line begins */
    while(1)
    {
        int cmd;
        printf("Input a cmd number>");
        scanf("%d", &cmd);
        if(cmd >= CMD_NUM)
        {
            printf("This is a wrong commad!\n");
            continue;
        }
        
        p = head;
        while(p != NULL)    
        {
            if(cmd == p->cmd)
            {
                printf("%s\n", p->descpt);
                break;
            }
            p = p->next;
        }
    }

    return 0;
}

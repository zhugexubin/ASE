/**************************************************************************************************/
/* Copyright (C) zhugexubin, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  lab1.c                                                               */
/*  PRINCIPAL AUTHOR      :  Zhugexubin                                                           */
/*  SUBSYSTEM NAME        :  lab1                                                                */
/*  MODULE NAME           :  lab1                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/09                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Zhugexubin, 2014/09/10
 *
 */


#include <stdio.h>
#include <stdlib.h>

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct  DataNode *next;
} tDataNode;

static tDataNode head[] = 
{
    {"help", "this is help cmd!", Help,&head[1]},
    {"ls", "file1, file2, file3, file4", NULL, &head[2]},
    {"version", "menu program v1.0", NULL, NULL}
};

int main()
{
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = head;
        while(p != NULL)
        {
            if(!strcmp(p->cmd, cmd))
            {
                printf("%s - %s\n", p->cmd, p->desc);
                if(p->handler != NULL)
                {
                    p->handler();
                }
                break;
            }
            p = p->next;
        }
        if(p == NULL) 
        {
            printf("This is a wrong cmd!\n ");
        }
    }

    return 0;
}

int Help()
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0; 
}


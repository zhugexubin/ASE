/**************************************************************************************************/
/* Copyright (C) software design, SSE@USTC, 2014-2015                                             */
/*                                                                                                */
/*  FILE NAME             :  menu_final.c                                                         */
/*  PRINCIPAL AUTHOR      :  zhugexubin                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/09                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Zhugexubin, 2014/09/12
 *
 * Modularity
 */

/*************** Attention: This program should compile and run in Linux System *******************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define NUM 1024
#define LNUM 50
#define SIZE 50
#define DESC_LEN 50
#define CMD_NUM 10
#define CMD_MAX_LEN 50
#define CMD_PATH_ONE "/user/bin/"
#define CMD_PATH_TWO "/bin/"

/* Data Structure Definition */
typedef struct DataNode
{
    char* cmd;
    char* descpt;
    int (*handler)(void* cmd);
    struct DataNode* next;
} tDataNode;

/* Function Declaration */
int Help();
int Exit();
int mystrtok(char *argv[], char* string);
int Handler(void* cmd);
tDataNode* FindCmd(tDataNode* p, char* cmd);
int ShowAllCmd(tDataNode* p);

/* Init static CMD Data */
static tDataNode head[] = 
{
    { "help", "This is help command!", Help, &head[1] },
    { "version", "version 1.1.2", NULL, &head[2] },
    { "ls", "This is ls cmd:", Handler, &head[3] },
    { "exit", "Exit the Command Line", Exit, &head[4] },
    { "ps", "This is ps cmd:", Handler, &head[5] },
    { "ps -e", "This is ps -e cmd:", Handler, NULL },
};

/* Execute Cmd Line */
void BeginCmdLine()
{
    tDataNode *p = NULL;
    /* Command Line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd >");
        gets(cmd);
            
        p = FindCmd(head, cmd);
        if(p != NULL)
        {
            printf("%s\n", p->descpt);

            if(p->handler != NULL)
            {
                p->handler(cmd);
            }
        }
        if(p == NULL)
        {
            printf("This is a wrong command!\n");
        }
    }
}


int main()
{
    /* Command Line begins */
    BeginCmdLine();
    return 0;    
}

/* Find Command */
tDataNode* FindCmd(tDataNode* p, char* cmd)
{
    while(p != NULL)    
    {
        if(!strcmp(cmd, p->cmd))
        {
            return p;
        }
        p = p->next;
    }
    
}

/* Show All Command */
int ShowAllCmd(tDataNode* p)
{
    printf("Menu List:\n");

    while(p != NULL)
    {
        printf("\t%s--%s\n", p->cmd, p->descpt);
        p = p->next;
    } 
    return 0;
}

/* Help Handler */
int Help()
{
    ShowAllCmd(head);
    return 0;
}

/* Exit Handler */
int Exit()
{
    exit(0);
}

/* Split Command String */
int mystrtok(char *argv[], char* string){
    
    int i=0;
    char delim[]=" ";
    char *p;
    argv[0] = strtok(string,delim);
    while(argv[i]!=NULL)
    {
        argv[++i] = strtok(NULL,delim);
    }
    
    return 0;
}
/* Universal Handler */
int Handler(void* cmd)
{
    pid_t pid;
    int n;
    char* argv[NUM];
    char realCmdOne[CMD_MAX_LEN];
    char realCmdTwo[CMD_MAX_LEN];
    char agmt1[LNUM];
    char agmt2[LNUM];
    strcpy(realCmdOne, CMD_PATH_ONE);
    strcpy(realCmdTwo, CMD_PATH_TWO);
 
    pid = fork();
    mystrtok(argv, cmd);
    n = strlen((const char *)argv)/4;
    switch(n)
    {
        case 2: strcpy(agmt2, argv[1]);
        case 1: strcpy(agmt1, argv[0]);break;
        default:                       break;
    }

    strcat(realCmdOne, cmd);
    strcat(realCmdTwo, cmd);
    if(pid==-1) 
    {
        printf("fork failure!\n");
    }
    else if(pid==0) 
    {
        switch(n)
        {
            case 2: execl(realCmdOne, agmt1, agmt2, NULL, NULL);
                    execl(realCmdTwo, agmt1, agmt2, NULL, NULL);break;
            case 1: execl(realCmdOne, agmt1, NULL, NULL, NULL);
                    execl(realCmdTwo, agmt1, NULL, NULL, NULL); break;
            default:                                            break;
        }
    }
    else 
    {
        wait();
    } 
}


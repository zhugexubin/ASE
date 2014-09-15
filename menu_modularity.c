

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
int Handler(void* cmd);
tDataNode* FindCmd(tDataNode* p, char* cmd);
int ShowAllCmd(tDataNode* p);

/* Init static CMD Data */
static tDataNode head[] = 
{
	{ "help", "This is help command!", Help, &head[1] },
	{ "version", "This is version command!", NULL, NULL },
	{ "ls", "This is version command!", Handler, NULL }
};

int main()
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
			printf("This is a wrong command!\n");
		
	}

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
	
	return NULL;	
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

/* Universal Handler */
int Handler(void* cmd)
{
	char* realCmd = CMD_PATH_ONE;
	strcat(realCmd, cmd);
	execl(realCmd, "sdf", NULL, NULL, NULL);
	realCmd = CMD_PATH_TWO;
	strcat(realCmd, cmd);
	execl(realCmd, "sdf", NULL, NULL, NULL);

}

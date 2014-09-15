#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_NUM 10
#define CMD_MAX_LEN 50

/* Function Declaration */
int Help();

/* Init static CMD Data */
static tDataNode head[] = 
{
	{ "help", "This is help command!", Help, &head[1] },
	{ "help", "This is help command!", Help, &head[1] },
	{ "version", "This is version command!", NULL, NULL }
};
/* Execute Cmd Line */
void BeginCmdLine()
{
	tDataNode *p = NULL;
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd >");
		scanf("%s", cmd);
			
		p = FindCmd(head, cmd);
		if(p != NULL)
		{
			printf("%s\n", p->descpt);

			if(p->handler != NULL)
			{
				p->handler();
			}
		}
		if(p == NULL)
			printf("This is a wrong command!\n");	
	}
}

int main()
{
	/* Command Line begins */
	BeginCmdLine();

	return 0;
}


/* Help Handler */
int Help()
{
	ShowAllCmd(head);
	return 0;
}

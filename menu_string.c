#include<stdio.h>

#define DESC_LEN 50
#define CMD_NUM 10
#define CMD_MAX_LEN 50

int Help();

/* Data Structure Definition */
typedef struct DataNode
{
    	char* cmd;
	char* descpt;
	char (*handler)();
	struct DataNode* next;
} tDataNode;

/* Init static Data */
static tDataNode head[] = 
{
	{ "help", "This is help command!", Help, &head[1] },
	{ "version", "This is version command!", NULL, NULL }
};

int main()
{
	tDataNode *p = NULL;
	/* Command Line begins */
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd >");
		scanf("%s", cmd);
		
		p = head;
		while(p != NULL)	
		{
			if(!strcmp(cmd, p->cmd))
			{
				if(p->handler != NULL)
				{
					p->handler();
				}
				printf("%s\n", p->descpt);
				break;
			}
			p = p->next;
		}
		if(p == NULL)
		{
			printf("This is a wrong command!\n");
		}
	}

	return 0;
}

int Help()
{
	printf("Menu List:\n");
	tDataNode* p = head;
	while(p != NULL)
	{
		printf("%s--%s\n", p->cmd, p->descpt);
		p = p->next;
	} 

	return 0;
}

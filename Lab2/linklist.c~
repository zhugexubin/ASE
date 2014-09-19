#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

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

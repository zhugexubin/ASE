

/* data structure definition and its operations*/
typedef struct DataNode
{
    	char* cmd;
	char* descpt;
	int (*handler)();
	struct DataNode* next;
} tDataNode;

tDataNode* FindCmd(tDataNode* p, char* cmd);

int ShowAllCmd(tDataNode* p);

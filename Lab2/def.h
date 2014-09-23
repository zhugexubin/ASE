/* Macro Defination */
#define NUM 1024
#define LNUM 50
#define SIZE 50
#define DESC_LEN 50
#define CMD_MAX_LEN 50
#define CMD_PATH_ONE "/user/bin/"
#define CMD_PATH_TWO "/bin/"

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

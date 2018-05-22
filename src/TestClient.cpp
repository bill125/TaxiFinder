#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include<unistd.h>
#include<iostream>
#include "Comm.h"
#define SRVPORT 10005
#define CONNECT_NUM 5
// #define MAX_NUM 80
int main()
{
    int clientSock=-1;
    struct sockaddr_in serverAddr;

    clientSock=socket(AF_INET,SOCK_STREAM,0);
    if(clientSock<0)
    {
        printf("socket creation failed\n");
        exit(-1);
    }
    printf("socket create successfully.\n");

    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons((u_short) SRVPORT);
    serverAddr.sin_addr.s_addr=htons(INADDR_ANY);
    if(connect(clientSock,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr_in))<0)
    {
        printf("Connect error.\n");
        exit(-1);
    }
    printf("Connect successful.\n");

    // char sedBuf[MAX_NUM]="116.44530,39.97466,116.25060,40.16492";
    char sedBuf[MAX_NUM]={0};
    char revBuf[MAX_NUM]={0};
    while(gets(sedBuf))
    {
        if(write(clientSock,sedBuf,strlen(sedBuf))==-1)
        {
            printf("send error!\n");
        }
        printf("Me(Client):%s\n",sedBuf);
        bzero(sedBuf,sizeof(sedBuf));
        if(read(clientSock,revBuf,MAX_NUM)==-1)
        {
            printf("rev error!\n");
        }
        printf("Sever:%s\n",revBuf);
        if(strcmp(revBuf,"Goodbye,my dear client!")==0)
            break;
        bzero(revBuf,sizeof(revBuf));
    }
    close(clientSock);

    return 0;
}
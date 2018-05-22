#include "Comm.h"
#include <sstream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string>

string Convert(double x)  
{  

    ostringstream out;
    out.precision(10);//覆盖默认精度
    out<<x;
    string str= out.str();
    return str;
}  

int initSocket() {
    int serverSock = -1, clientSock = -1;
    struct sockaddr_in serverAddr;

    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSock < 0) {
        printf("socket creation failed\n");
        return -1;
    }
    printf("socket create successfully.\n");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons((u_short) SRVPORT);
    serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
    bind(serverSock,(struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in));
    printf("Bind successful.\n");

    if(listen(serverSock,10)==-1) {
        printf("Listen error!\n");
    }
    printf("Start to listen!\n");
    
    return serverSock;
}

void parseData(string s, double &lngt1, double &lat1, double &lngt2, double &lat2) {
    int h = 0;
    int comma1 = -1, comma2 = -1, comma3 = -1;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == ',') {
            if (comma1 == -1) {
                comma1 = i;
            } else if (comma2 == -1) {
                comma2 = i;
            } else {
                comma3 = i;
            }
        }
    }
    
    lngt1 = atof(s.substr(0, comma1).c_str());
    lat1 = atof(s.substr(comma1 + 1, comma2 - comma1 - 1).c_str());
    lngt2 = atof(s.substr(comma2 + 1, comma3 - comma2 - 1).c_str());
    lat2 = atof(s.substr(comma3 + 1, s.length() - comma3 - 1).c_str());    
}

string codeData(vector<double> & lngt,vector<double> & lat)
{
    string res = "";
    int n = lngt.size();
    for (int i = 0; i < n; ++ i) {
        res = res + Convert(lngt[i]) + "," + Convert(lat[i]);
        res += (i == n - 1) ? ";" : ",";
    }
    return res;
}
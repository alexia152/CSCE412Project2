#ifndef loadbalancer
#define loadbalancer
#include<bits/stdc++.h>
#include "request.h"
#include "webserver.h"

using namespace std;

class LoadBalancer {
    public:
        LoadBalancer();
        void incrementTime(int time);
        void queueWebServer(WebServer* webServer);
        void sendRequest(WebServer* webServer, Request* requestObj);
        int currentTime;
        queue<Request*> requests;
        queue<WebServer*> activeServers;
        queue<WebServer*> idleServers; 
};

#endif
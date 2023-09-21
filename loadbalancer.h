#ifndef loadbalancer
#define loadbalancer
#include<bits/stdc++.h>
#include "request.h"
#include "webserver.h"

using namespace std;

class LoadBalancer {
    public:
        LoadBalancer();
    private:
        int currentTime;
        queue<Request> requestQ;
        queue<WebServer> serverQ;
};

#endif
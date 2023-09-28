#ifndef webserver
#define webserver
#include <bits/stdc++.h>
#include "request.h"

using namespace std;

enum WebServerStatus {processingRequest, readyForRequest};

class WebServer {
    public:
       WebServer();
       void setCompletionTime(int time, Request* requestObj);
       int getCompletionTime();
       Request* getCurrentRequest();
       WebServerStatus getWebServerStatus();
       int getServerID();

    private:
        WebServerStatus status;
        Request* currentRequest;
        int completionTime;
        int serverID;
};

#endif
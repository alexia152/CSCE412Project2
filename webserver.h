#ifndef webserver
#define webserver
#include <bits/stdc++.h>
#include "request.h"

using namespace std;

enum WebServerStatus {processingRequest, readyForRequest};

class WebServer {
    public:
       WebServer();
       void processRequest(Request request);
       WebServerStatus getWebServerStatus();

    private:
        WebServerStatus status;
};

#endif
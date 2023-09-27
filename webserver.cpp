#include <bits/stdc++.h>
#include "webserver.h" //change to header file?
#include "request.h"


using namespace std;

WebServer::WebServer() {
    this->status = readyForRequest;
}
 
void WebServer::setCompletionTime(int time, Request* requestObj) {
    this->completionTime = time + requestObj->getTime();
    this->currentRequest = requestObj;
}

int WebServer::getCompletionTime() {
    return this->completionTime;
}

WebServerStatus WebServer::getWebServerStatus() { //how to request another? needs to communicate w load balancer?
    return this->status;
}

Request* WebServer::getCurrentRequest() {
    return this->currentRequest;
}


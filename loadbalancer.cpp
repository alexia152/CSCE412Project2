#include <bits/stdc++.h>
#include "loadbalancer.h"
#include "webserver.h"
#include "request.h"

using namespace std;

LoadBalancer::LoadBalancer() {
    this->currentTime = 0;
}

void LoadBalancer::queueWebServer(WebServer* webServer) {
    idleServers.push(webServer);
}

void LoadBalancer::sendRequest(WebServer* webServer, Request* requestObj) {
    webServer->setCompletionTime(this->currentTime, requestObj);
}
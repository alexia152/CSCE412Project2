#include <bits/stdc++.h>
#include "webserver.h"
#include "request.h"

using namespace std;

WebServer::WebServer()
{
    this->status = readyForRequest;
    if (!serverIDs.empty())
    {
        this->serverID = serverIDs.front();
        serverIDs.pop();
    }
    else
    {
        this->serverID = currentID;
        currentID++;
    }
}

void WebServer::setCompletionTime(int time, Request *requestObj)
{
    this->completionTime = time + requestObj->getTime();
    this->currentRequest = requestObj;
}

int WebServer::getCompletionTime()
{
    return this->completionTime;
}

int WebServer::getServerID()
{
    return this->serverID;
}

WebServerStatus WebServer::getWebServerStatus()
{ 
    return this->status;
}

Request *WebServer::getCurrentRequest()
{
    return this->currentRequest;
}

WebServer::~WebServer()
{
    serverIDs.push(this->getServerID());
}

int WebServer::currentID = 0;

queue<int> WebServer::serverIDs = queue<int>();
#include <bits/stdc++.h>
#include "webserver.h" //change to header file?
#include "request.h"

using namespace std;

 
void WebServer::processRequest(Request requestObj) {
    this->status = processingRequest;
    cout << "Processing request with IP in: " << requestObj.getIPIn() << ", IP out: " << requestObj.getIPOut() << ", and time: " << requestObj.getTime() << endl;
    //simulate time?
    this->status = readyForRequest; //request finished
}

WebServerStatus WebServer::getWebServerStatus() { //how to request another? needs to communicate w load balancer?
    return this->status;
}
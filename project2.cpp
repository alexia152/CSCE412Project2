#include <bits/stdc++.h>
#include "request.h"
#include "loadbalancer.h"
#include "webserver.h"

using namespace std;

int main()
{
    int numServers, numTime;

    // handle user input
    cout << "Please input the number of servers you would like: ";
    cin >> numServers;
    cout << endl;
    cout << "Please input the amount of time you would like the load balancer to run for: ";
    cin >> numTime;
    cout << endl;

    // create load balancer
    LoadBalancer *loadBalancer = new LoadBalancer();

    // create web servers
    for (int k = 0; k < numServers; k++)
    {
        WebServer *webServer = new WebServer();
        loadBalancer->idleServers.push(webServer);
    }

    // generate full queue
    for (int k = 0; k < numServers * 5; k++)
    {
        Request *newRequest = new Request();
        loadBalancer->requests.push(newRequest);
    }

    // while we have not finished running time
    while (loadBalancer->currentTime <= numTime)
    {
        // i need to look at our active webservers and remove them from the queue and
        // put their servers back to idle as needed
        while (!loadBalancer->activeServers.empty() && loadBalancer->activeServers.front()->getCompletionTime() < loadBalancer->currentTime)
        {
            // get the next webserver
            WebServer *webServer = loadBalancer->activeServers.front();
            loadBalancer->activeServers.pop();

            // cout << "Finished request: " << webServer->getCurrentRequest()->getIPIn() << endl;

            // delete the request and put the server into the idle queue
            delete webServer->getCurrentRequest();
            loadBalancer->idleServers.push(webServer);
        }

        // then I need to process more requests with the idle servers
        while (!loadBalancer->idleServers.empty() && !loadBalancer->requests.empty())
        {
            // get the next webserver and request
            WebServer *webServer = loadBalancer->idleServers.front();
            Request *requestObj = loadBalancer->requests.front();
            // remove them from their queues
            loadBalancer->idleServers.pop();
            loadBalancer->requests.pop();

            // set their completion times
            webServer->setCompletionTime(loadBalancer->currentTime, requestObj);

            // add this server to the list of active servers
            loadBalancer->activeServers.push(webServer);

            // cout << "Processing request: " << requestObj->getIPIn() << endl;
        }

        // increment cycle time
        loadBalancer->currentTime++;
    }
    return 0;
}

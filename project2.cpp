#include <bits/stdc++.h>
#include "request.h"
#include "loadbalancer.h"
#include "webserver.h"

using namespace std;

/**
 * @brief The main function for the load balancer simulation.
 *
 * This function simulates the operation of a load balancer, including creating web servers,
 * processing requests, and managing server capacity.
 *
 * @return 0 on successful execution.
 */

int main()
{
    ofstream myfile;
    myfile.open("log.txt");

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

    loadBalancer->requestCapacity = 5 * numServers;
    // generate full queue
    for (int k = 0; k < loadBalancer->requestCapacity; k++)
    {
        Request *newRequest = new Request();
        loadBalancer->requests.push(newRequest);
    }

    // while we have not finished running time
    while (loadBalancer->currentTime <= numTime)
    {
        //look at active webservers and remove them from the queue and put their servers back to idle as needed
        while (!loadBalancer->activeServers.empty() && loadBalancer->activeServers.front()->getCompletionTime() < loadBalancer->currentTime)
        {
            // get the next webserver
            WebServer *webServer = loadBalancer->activeServers.front();
            loadBalancer->activeServers.pop();

            myfile << "Finished request with IP In: " << webServer->getCurrentRequest()->getIPIn() << " in Server: " << webServer->getServerID() << endl;
            loadBalancer->requestsProcessed++;

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
        }

        // generate new requests at 30% chance
        int val = rand() % 100;
        if (val <= 30)
        {
            Request *requestObj = new Request();
            loadBalancer->requests.push(requestObj);
            myfile << "New request generated with IP In: " << requestObj->getIPIn() << endl;
        }

        // logic to add and remove webservers as needed
        // if we are at 80% capacity, add another server
        // if we are below 30% capacity, remove another server
        double queueFillPercentage = (double)loadBalancer->requests.size() / loadBalancer->requestCapacity;
        if (queueFillPercentage > 0.8)
        {
            WebServer *webServer = new WebServer();
            loadBalancer->idleServers.push(webServer);
            myfile << "Added Server: " << webServer->getServerID() << endl;
            loadBalancer->serversAdded++;
        }
        else if (queueFillPercentage < 0.3)
        {
            if (!loadBalancer->idleServers.empty())
            {
                WebServer *webServer = loadBalancer->idleServers.front();
                loadBalancer->idleServers.pop();
                myfile << "Removed Server: " << webServer->getServerID() << endl;
                loadBalancer->serversDeleted++;

                delete webServer;
            }
        }

        // increment cycle time
        loadBalancer->currentTime++;
    }

    myfile << endl << endl;
    myfile << "Starting queue size: " << loadBalancer->requestCapacity << endl;
    myfile << "Ending queue size: " << loadBalancer->requests.size() << endl;
    myfile << "Request processing time range: 3 - 50 clock cycles" << endl;
    myfile << "Requests processed: " << loadBalancer->requestsProcessed << endl;
    myfile << "Servers added: " << loadBalancer->serversAdded << endl;
    myfile << "Servers deleted: " << loadBalancer->serversDeleted << endl;
    myfile << "Maximum webservers at a time: " << WebServer::currentID << endl;
    

    myfile.close();
    return 0;
}

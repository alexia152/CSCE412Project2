#ifndef loadbalancer
#define loadbalancer
#include <bits/stdc++.h>
#include "request.h"
#include "webserver.h"

using namespace std;

/**
 * @class LoadBalancer
 * @brief Manages the load balancing of web server requests.
 */
class LoadBalancer
{
public:
    /**
     * @brief Default constructor for the LoadBalancer class.
     *
     * Initializes the load balancer with default values for its members.
     */
    LoadBalancer();

    /**
     * @brief Increment the current time managed by the load balancer.
     *
     * @param time The amount by which to increment the current time.
     */
    void incrementTime(int time);

    /**
     * @brief Queue a web server for load balancing.
     *
     * @param webServer A pointer to the WebServer object to be added to the queue of idle servers.
     */
    void queueWebServer(WebServer *webServer);

    /**
     * @brief Send a request to a specific web server.
     *
     * @param webServer A pointer to the target WebServer.
     * @param requestObj A pointer to the Request object to be processed by the web server.
     */
    void sendRequest(WebServer *webServer, Request *requestObj);

    /**
     * @brief Represents the current time managed by the load balancer.
     */
    int currentTime;

    /**
     * @brief Represents the maximum capacity for concurrent requests.
     */
    int requestCapacity;

    /**
     * @brief Represents the number of servers added to the load balancer.
     */
    int serversAdded;

    /**
     * @brief Represents the number of servers deleted from the load balancer.
     */
    int serversDeleted;

    /**
     * @brief Represents the total number of requests processed by the load balancer.
     */
    int requestsProcessed;

    /**
     * @brief Queue of pending requests to be processed by web servers.
     */
    queue<Request *> requests;

    /**
     * @brief Queue of currently active web servers processing requests.
     */
    queue<WebServer *> activeServers;

    /**
     * @brief Queue of idle web servers available for processing requests.
     */
    queue<WebServer *> idleServers;
};

#endif
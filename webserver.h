#ifndef webserver
#define webserver
#include <bits/stdc++.h>
#include "request.h"

using namespace std;

/**
 * @enum WebServerStatus
 * @brief Represents the status of a web server, either 'processingRequest' or 'readyForRequest'.
 */
enum WebServerStatus
{
    processingRequest,
    readyForRequest
};

/**
 * @class WebServer
 * @brief Represents a web server with information about its status, completion time, and current request.
 */
class WebServer
{
public:
    /**
     * @brief Default constructor for the WebServer class.
     *
     * Initializes a WebServer object with default values.
     */
    WebServer();

    /**
     * @brief Set the completion time for the web server.
     *
     * @param time The completion time to set.
     * @param requestObj A pointer to the associated Request object.
     */
    void setCompletionTime(int time, Request *requestObj);

    /**
     * @brief Get the completion time of the web server.
     *
     * @return An integer representing the completion time.
     */
    int getCompletionTime();

    /**
     * @brief Get the current request being handled by the web server.
     *
     * @return A pointer to the current Request object, or nullptr if no request is being handled.
     */
    Request *getCurrentRequest();

    /**
     * @brief Get the status of the web server.
     *
     * @return A WebServerStatus enum representing the server's status.
     */
    WebServerStatus getWebServerStatus();

    /**
     * @brief Get the server ID of the web server.
     *
     * @return An integer representing the server's ID.
     */
    int getServerID();

    /**
     * @brief Static queue to store available server IDs.
     */
    static queue<int> serverIDs;

    /**
     * @brief Static variable to track the current server ID.
     */
    static int currentID;

    /**
     * @brief Destructor for the WebServer class.
     *
     * Puts the server's ID back into the available server IDs queue.
     */
    ~WebServer();

private:
    /**
     * @brief Represents the current status of the web server.
     */
    WebServerStatus status;

    /**
     * @brief Pointer to the current Request object being handled by the web server.
     */
    Request *currentRequest;

    /**
     * @brief Represents the completion time of the current request.
     */
    int completionTime;

    /**
     * @brief Represents the server's ID.
     */
    int serverID;
};

#endif
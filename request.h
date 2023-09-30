#ifndef request
#define request
#include <bits/stdc++.h>

using namespace std;

/**
 * @class Request
 * @brief Represents a request object with IP addresses and time information.
 */

class Request
{
public:
    /**
     * @brief Default constructor for the Request class.
     *
     * Initializes a Request object with random IP addresses and a random time.
     */
    Request();

    /**
     * @brief Get the incoming IP address of the request.
     *
     * @return A string representing the incoming IP address.
     */
    string getIPIn();

    /**
     * @brief Get the outgoing IP address of the request.
     *
     * @return A string representing the outgoing IP address.
     */
    string getIPOut();

    /**
     * @brief Get the time of the request.
     *
     * @return An integer representing the time of the request.
     */
    int getTime();

private:
    /**
     * @brief The incoming IP address of the request.
     */
    string ipIn;

    /**
     * @brief The outgoing IP address of the request.
     */
    string ipOut;

    /**
     * @brief The processing time of the request.
     */
    int time;

    /**
     * @brief Generate a random IP address.
     *
     * @return A string containing a randomly generated IP address in the format "XXX.XXX.XXX".
     */
    string generateRandomIP();

    /**
     * @brief Generate a random time value.
     *
     * @return An integer representing a random time value.
     */
    int generateRandomTime();
};

#endif

#include <bits/stdc++.h>
#include "request.h"
using namespace std;

Request::Request() {
    this->ipIn = generateRandomIP();
    this->ipOut = generateRandomIP();
    this->time = generateRandomTime();
}

string Request::getIPIn() {
    return this->ipIn;
}

string Request::getIPOut() {
    return this->ipOut;
}

int Request::getTime() {
    return this->time;
}

string Request::generateRandomIP() {
    return to_string(rand() % 999 + 100) + "." + to_string(rand() % 999 + 100) + "." + to_string(rand() % 999 + 100);
}

int Request::generateRandomTime() {
    return rand() % 50 + 3; //shpuld there be a different max and min
}


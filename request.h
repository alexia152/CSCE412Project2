#ifndef request
#define request
#include <bits/stdc++.h>

using namespace std;

class Request {
    public:
        Request();
        string getIPIn();
        string getIPOut();
        int getTime();

    private:
        string ipIn;
        string ipOut;
        int time;

        string generateRandomIP();
        int generateRandomTime();
};

#endif


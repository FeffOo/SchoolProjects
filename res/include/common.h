#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include <pthread.h>
#include <assert.h>

#include <zmq.hpp>

//only for the server
#include "ThreadPoolClass.cpp"

using namespace std;
using namespace zmq;

const int BUFFER_SIZE = 512;
const int PORT = 7575;
const int DEFAULT_SLEEP_TIME = 10;
const int CLIENT_USERNAME_SIZE = 32;
const int DEFAULT_THREADS_NUMBER = 4;

const char Client_Username[CLIENT_USERNAME_SIZE] = {"User"}; // Default to "User"

char Server_Addr[] = {"tcp:://localhost:7575"};


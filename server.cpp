#pragma once
#include "res/include/common.h"

void ManageConnetion();
void AcceptConnetion();

void *serverSock;
void *context;

unsigned short int connectedUsers = 0;
char Packet[BUFFER_SIZE];
ThreadPool MainManager(DEFAULT_THREADS_NUMBER);
ThreadPool NetIOManager(DEFAULT_THREADS_NUMBER);

int main(int argc, char **argv){
    
    context = zmq_ctx_new ();
    serverSock = zmq_socket (context, ZMQ_REP);
    int socketBind = zmq_bind (serverSock, "tcp://*:5555");
    assert(socketBind == 0);

    for(int netIOManCounter = 0; netIOManCounter < DEFAULT_THREADS_NUMBER; ++netIOManCounter){
        NetIOManager.enqueue([netIOManCounter]{
            AcceptConnetion();
        });
    
    }

    for(int mainManCounter = 0; mainManCounter < DEFAULT_THREADS_NUMBER; ++mainManCounter){
        MainManager.enqueue([mainManCounter]{
            ManageConnetion();
        });
    
    }

    zmq_close (serverSock);
    zmq_ctx_destroy (context);

    return EXIT_SUCCESS;
}


void ManageConnection(){

    while(1){
        zmq_recv(serverSock, Packet, BUFFER_SIZE, 0);
        printf("%s\n", Packet);
        sleep(DEFAULT_SLEEP_TIME);

    }

}

void AcceptConnection(){
    
}
#pragma once
#include "res/include/common.h"

pthread_t clientThread;

int main(int argc, char **argv){

    char Packet[BUFFER_SIZE] = {};

    void *context = zmq_ctx_new ();
    void *clientSocket = zmq_socket (context, ZMQ_REQ);
    
    zmq_connect (clientSocket, Server_Addr);

    while(1){
        zmq_send(clientSocket, Packet, BUFFER_SIZE, 0);
    }

    zmq_close (clientSocket);
    zmq_ctx_destroy (context);
    
    return EXIT_SUCCESS;
}
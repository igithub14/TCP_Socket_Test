
//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPClient" directory.

/*
 Here is depicted the workflow for the TCP client:
 
   socket()   Create a socket through a call to socket()
      |
      |
     . .
      .
   bind()  bind the socket to an IP and Port through bind()
      |
      |
     . .
      .
    listen()    the server can listen for connections thanks to listen()
      |
      |
     . .
      .
    accept() the server can accept the connection through accept() and then send() or recv() data 
             to the other socket he's connected to
*/ 

//We want to include some stuff from stdio and stdlib
#include <stdio.h>
#include <stdlib.h>

// The following are for definition of socket functions and API
#include <sys/types.h>
#include <sys/socket.h>

//... for the structures we need to store address infos
#include <netinet/in.h>

int main () {
    

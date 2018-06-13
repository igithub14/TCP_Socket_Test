
//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPClient" directory.

/*
 Here is depicted the workflow for the TCP client:
 
   socket()   Create a socket through a call to socket()
      |
      |
     . .
      .
   connect()  Connect to a remote address through a call to connect()
      |
      |
     . .
      .
    recv()    Starts receiving data
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
    

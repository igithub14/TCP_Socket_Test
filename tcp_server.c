
//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPServer" directory.

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

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main () {
 
 //define a strring to hold the data to be sent to the client
 char server_message[256] = "You have rached the server";
 
 //cresate the server socket
 int server_socket;
 server_socket = socket(AF_INET, SOCK_STREAM, 0);
 
 // define the server address
 struct sockaddr_in_server_address;
 server_adress.sin.family = AF_INET;
 server_adress.sin_port = htons(9002);
 server_adress.sin_addr.s_addr = INADDR_ANY;
 
 //bind the socket to our specified IP and port
 bind (server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
 
 listen(server_socket, 5);
 
 return 0;
}
    

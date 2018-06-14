
//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPServer" directory.

/*
 Here is depicted the workflow for the TCP server:
 
 +---------------+
 |               |
 |   socket()    |  Create a socket through a call to socket()
 |               |
 +---------------+
         |
         |
         v
 +---------------+
 |               |
 |    bind()     |   Bind the socket to an IP and Port through bind()
 |               |
 +---------------+      
         |
         |
         v
 +---------------+
 |               |
 |   listen()    |   The server can listen for connections thanks to listen()
 |               |
 +---------------+
         |
         |
         v
 +---------------+
 |               |
 |    accept()   |   The server can accept the connection through accept()...  
 |               |   
 +---------------+
          |
         |
         v
 +---------------+
 |               |
 | send()/recv() |  ... and then send() or recv() data to the other socket he's connected to
 |               |   
 +---------------+
 
*/ 

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main () {
 
 //define a string to hold the data to be sent to the client
 char server_message[256] = "You have rached the server";
 
 //cresate the server socket
 int server_socket; //this Integer holds the return value of the socket call
 server_socket = socket(AF_INET, SOCK_STREAM, 0);
 
 // define the server address
 struct sockaddr_in_server_address;
 server_adress.sin.family = AF_INET;
 server_adress.sin_port = htons(9002);
 server_adress.sin_addr.s_addr = INADDR_ANY;
 
 //bind the socket to our specified IP and port
 bind (server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
 
 listen(server_socket, 5);
 
 int client_socket;
 client_socket = accept (server_socket, NULL, NULL);
 
 //send the message
 send (client_socket, server_message, sizeof(server_message), 0);
 
 //close the socket
 close (server_socket);
 return 0;
}
    

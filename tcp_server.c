
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
 char server_message[256] = "You have reached the server";
 
 //cresate the server socket
 int server_socket; //this Integer holds the return value of the socket call
 server_socket = socket(AF_INET, SOCK_STREAM, 0);
 
 // define the server address 
 struct sockaddr_in server_address; 
 server_address.sin_family = AF_INET;
 server_address.sin_port = htons(9002);
 server_address.sin_addr.s_addr = INADDR_ANY; // actual address
 
 //call the bind the socket to our specified IP and port. That is to bind the socket to our specified IP and Port
 bind (server_socket, (struct sockaddr*) &server_address, sizeof(server_address)); 
 
 listen(server_socket, 5); //start listening for connections. The second param is a backlog. 
 
 int client_socket; //this Integer holds the client socket
 client_socket = accept (server_socket, NULL, NULL); /* the client_socket is then the result 
                                                        of the accept() of the server_socket. So now we have a 2-way connection
                                                        between the server and the client*/
 
 //send the message
 send (client_socket, server_message, sizeof(server_message), 0); /* now we can start sending data to the client socket 
                                                                     the first param is the client_socket, the second 
                                                                     is the mesage we whant to send from the server*/
 
 //close the socket
 close (server_socket);
 return 0;
}
    

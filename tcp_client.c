//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPClient" directory.

/*
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
    
  //Definition of a socket:
  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0); // call to the socket() function
                                                    // AF_INET is the socket Domain
                                                    // SOCKET_STREAM is the type of the socket (eg: TCP or UDP... In this case it is TCP)
                                                    // 0 means we want to use the defaut protocol (TCP) 
                                                    // then we have create the socket.
  
  // Now we want to create the other end of the communication, to which we want to Connect. 
  // Then we want to call the connect() function. 
  // Before to call the connect functionwe need to specify the address we want to connect to; this is why we need netinet.in.h 
  // who contains a Structure in which we can define IP and Port numbers.
  // Definition of an address Structure for the socket:
  struct sockaddr_in server_address;
  //sin_family and  and sin_port are some of the fields that constitute the struct
  server_address.sin_family = AF_INET; // type of the address
  server_address.sin_port = htons(9002); // we could pass an integer, but better to use the conversion function htons(). 
                                         // 9002 is a port numer that is not used by the OS. 
  server_address.sin_addr.s_addr = INADDR_ANY; //here we specify the actual address we want to connect to.
                                               // INADDR_ANY == 0.0.0.0
  
   // then we have defined the address we want to connect to. 
   
  int connection_status = connect (network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  
  //test
  if (connection_status == -1) {
    printf ("There was an error making the connection to the remote socket.\n\n");
  }
  
  //
  char server_response[256];
  recv (network_socket, &serve_response, sizeof (serve_response), 0);
  
  //...
  
  return 0;
}

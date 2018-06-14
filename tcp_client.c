//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPClient" directory.

/*
 Here is depicted the workflow for the TCP client:
 
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
 |   connect()   |  Connect to a remote address through a call to connect()
 |               |
 +---------------+      
         |
         |
         v
 +---------------+
 |               |
 |    recv()     |  Starts receiving data
 |               |
 +---------------+
       
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
  
  // then we have defined the address we want to connect to. So now it make sense to kalling the connect() function.
  // the first param we pass to connect() is the socket network_socket.
  // then we need to cast the server address struct to a slightly different struck 
  // then we pass the size of the address. 
  // NB: connect() returns an integer that lets us know if the connection was successful or not.
  int connection_status = connect (network_socket, (struct sockaddr *) &server_address, sizeof(server_address)); 
  
  // then now we test if the connection was successful or not
  // if connection_status is zero then it was ok; if -1 something went wrong.
  if (connection_status == -1) {
    printf ("There was an error making the connection to the remote socket.\n\n");
  }
  
  // Now we can start sending or receiving data from the server.
  // Let's see recv()  function.
  // the first param we pass to recv() is the socket
  // second we pass a string we want to use to send back data from the server. We pass the address of this string &serve_response.
  // the third param is the size of the server response (of the string)
  // is an options parameter.
  char server_response[256];
  recv (network_socket, &server_response, sizeof (serve_response), 0);
  
  // then we just print the data we got back from the server
  print ("The server sent the data: %s\n", server_response);
   
  // now we can close the socket by useing the close funcion
  // this function takes the socket as a parameter
  close(network_socket);
  
  return 0;
}

//Run it on a Linux System.
//Put it inside: "~/Sockets/TCPClient" directory.

//We want to include some stuff from stdio and stdlib
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main () {
    
  //Definition of a socket:
  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  //definition of an address for the socket:
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
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

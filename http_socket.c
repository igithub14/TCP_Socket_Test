#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <string.types.h>

int main () {

  // we whant to render a XML file.

  //we are gona use a c method for opening and reading a file.
  
  // open a ifle to serve
  FILE *html_data;
  html_data = fopen("index.html", "r");
  
  char response_data[1024];
  fgets(response_data, 1024, html_data);
  
  char http_header[1024] = "HTTP/1.1 200 OK\r\n\n"//here  a semcolon needed
  strcat(http_header. response_data);
  
  // create a socket
  int server_socket;
  server_socket = (AF_INET, SOCK_STREAM, 0);
  
  // define the address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons (8001);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  bind (server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  //...
  
  return 0;
}

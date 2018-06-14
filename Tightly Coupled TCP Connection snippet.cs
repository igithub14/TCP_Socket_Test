
//... This is a C# code snippet.

/*
  This snippet depicts how a Client can invoke a remote function via a TCP conneciton.
  This procedure is only reasonable on a tightly coupled system.
  The scenario is that of a front-end web client invoking a remote function on a back-end system.
  Eg: Bank system. The client invokes the remote function to make a fund transfer.
  Notes: the use of TCP allows the independence from the OS type. However, the platform independence 
  works only for simple messages: byte streams.  In order to convert our data into a byte stream 
  we used the BitConverter class; but the internal representation of an integer number varies with computer systems 
  (eg: the representation can be 32bit or 64bit). Also, some systems store their numbers in big-endian 
  while others store them in little-endian format. 
  A second problem with this approach is that we hardcode the location of the remote machine; this can be tedious, so 
  we want to make a connection that can be independent from the machine we are connecting to.
  Also, we are using TCP wich is connection oriented, then we are establishing temporal dependencies between the two machines.
  which must be available at the same time.
*/

//...
String hostName = "www.bank.com"; /* The IPHostEntry class associates a Domain Name System (DNS) host name 
                                     with an array of aliases and an array of matching IP addresses.*/


int port = 80; 
 
                                     
IPHostEntry hostInfo = Dns.GetHostByName(hostName); /* This row queries the DNS database for information 
                                                       on the host www.contoso.com and returns the information in an IPHostEntry instance. */
IPAddress address = hostInfo.AddressList[0]; /*Gets IP address from AddresList[] and assigns it to address*/
 
IPEndPoint endpoint = new IPEndPoint(address, port); /* Represents a network endpoint as an IP address and a Port number*/
 
Socket socket = new Socket(address.AddressFamily, SocketType.Stream, ProtocolType.Tcp); /* The Socket class allows you to configure your Socket. 
                                                                                           AddressFamiliy allows to select the right addressing schema (dunno what it really is). */
socket.Connect(endpoint); /* Establishes a connection to the remote host*/
 
byte[] amount = BitConverter.GetBytes(1000); /* Converts the assigned data to a bytes matrix*/
byte[] name = Encoding.ASCII.GetBytes("Joe");

int bytesSent = socket.Send(amount); /* the method socket.send() sends syncronously data to a connected object on the remote host*/
bytesSent    += socket.Send(name); 
 
socket.Close(); /*this method closes the TCP connection to the remote host, and releases the resources associated to the Socket*/


//... This is a C# code snippet.

/*
  This snippet depicts how a Client can invoke a remote function via a TCP conneciton.
  This procedure is only reasonable on a tightly coupled system.
  The scenario is that of a front-end web client invoking a remote function on a back-end system.
  Eg: Bank system. The client invokes the remote function to make a fund transfer.
*/

//...
String hostName = "www.bank.com"; /* The IPHostEntry class associates a Domain Name System (DNS) host name 
                                     with an array of aliases and an array of matching IP addresses.
                                  */


int port = 80; 
 
                                     
IPHostEntry hostInfo = Dns.GetHostByName(hostName); /* This row queries the DNS database for information 
                                                       on the host www.contoso.com and returns the information in an IPHostEntry instance.   
                                                    */
IPAddress address = hostInfo.AddressList[0]; /*Gets IP address from AddresList[] and assigns it to address*/
 
IPEndPoint endpoint = new IPEndPoint(address, port); /* Represents a network endpoint as an IP address and a Port number*/
 
Socket socket = new Socket(address.AddressFamily, SocketType.Stream, ProtocolType.Tcp); /* The Socket class allows you to configure your Socket. 
                                                                                           AddressFamiliy allows to select the right addressing schema (dunno what it really is). */
socket.Connect(endpoint); 
 
byte[] amount = BitConverter.GetBytes(1000); byte[] name   = Encoding.ASCII.GetBytes("Joe");

int bytesSent = socket.Send(amount); bytesSent    += socket.Send(name); 
 
socket.Close(); 

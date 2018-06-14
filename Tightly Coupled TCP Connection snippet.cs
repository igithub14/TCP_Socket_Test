
//...
//This is a C# code snippet.

/*
  This snippet depicts how a Client can invoke a remote function via a TCP conneciton.
  This procedure is only reasonable on a tightly coupled system.
*/

//...
String hostName = "www.eaipatterns.com"; int port = 80; 
 
IPHostEntry hostInfo = Dns.GetHostByName(hostName); IPAddress address = hostInfo.AddressList[0]; 
 
IPEndPoint endpoint = new IPEndPoint(address, port); 
 
Socket socket = new Socket(address.AddressFamily, SocketType.Stream, ProtocolType.Tcp); socket.Connect(endpoint); 
 
byte[] amount = BitConverter.GetBytes(1000); byte[] name   = Encoding.ASCII.GetBytes("Joe");

int bytesSent = socket.Send(amount); bytesSent    += socket.Send(name); 
 
socket.Close(); 

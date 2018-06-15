# TCP_Socket_Test
This bunch of files are for testing a TCP connection between two tightly coupled homogeneous systems. Later, I'm gonna test a more loosely coupled solution. 

The main goal is to make it possibile the communication between two heterogeneous systems.

In order to make the solution more loosely coupled I must remove all the dependencies one by one.

Referring to the file *Tightly Coupled TCP Connection snippet.cs*, I must consider the following dependencies:

  • Platform Technology: internal representations of numbers and objects
  • Location: hard-coded machine addresses
  • Time: all components have to be available at the same time  
  • Data Format: the list of parameters and their types must match 
  
Then:
  • I can use a data format that is self-describing and platform independent, such as XML
  • instead of sending information directly to a specific machine we should send it to an addressable 'channel'
  • enhance the channel to Queue up sent requests until the network and the receiving system are ready (IMPORTANT). 
    That is why we need to wrap data inside Messages.
  •  we also need some way to make data format transformations inside the channel, using transformers
  
After having configured a TCP client/server connection, I whant to implement HTTP Protocol on top of it.
Note: remember that sockets sit underneath all of the typical internet protocols we use. 

HTTP stays on top of TCP protocol.

At client side we write code to ask the server for  particular resource. The servfer answers retreiving either the response or an error msg.
        
     +----------------------+
     |                      |
     |    GET /index.html   |
     |                      |
     +----------------------+
                |
                V
            `-.....-
            |       |  // server
            |       |
            `-.....-


...

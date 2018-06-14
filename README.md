# TCP_Socket_Test
This bunch of files are for testing a TCP connection between two tightly coupled homogeneous systems. Later, I'm gonna test a more loosely coupled solution. 

The main goal is to make it possibile the communication between two heterogeneous systems.

In order to make the solution more loosely coupled I must remove all the dependencies one by one.

Referring to the file , I must consider the following dependencies:

  • Platform Technology: internal representations of numbers and objects
  • Location: hard-coded machine addresses
  • Time: all components have to be available at the same time  
  • Data Format: the list of parameters and their types must match 
  
  

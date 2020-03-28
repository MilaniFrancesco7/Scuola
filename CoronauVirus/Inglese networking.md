# Networking exercises

NIC - HUB - ROUTER - SWITCH - BRIDGE - REPEATER - GATEWAY

1. To connect channels toghether and divide a network into separate segments. -> ROUTER
2. To connect two different networks. -> GATEWAY
3. To connect several cables to single ouput, -> HUB
4. To direct signals to the correct destination. -> SWITCH
5. To improve the quality of degraded signals. -> REPEATER
6. To inspect incoming traffic. -> BRIDGE
7. To provide the connection between the computer and the network cables. -> NIC

PROS OF NETWORKS
- Printers and Scanners can be shared among different computers
- Hardware can be shared among different users, it is faster to install and easier to mantain and upgrade
- users have access to a central store of data
- communication and transport of files across the network is very quick
- secure is improved with the use of passwords, and the works is backed up
- communication across the network is cheaper than software for each standalone computer

CONS OF NETWORKS
- cables and servers can be expensives to install and replace
- a fault with the server will prevent the  whole network from working
- a network manager is needed and can be expansive
- networks are vulnerable to viruses and hackers



## Match each description with the appropriate network topology
1. All devices are connected to a main central node or server. the other nodes are connected to it and to each other through a switch or a hub. **STAR**
2. All devices are connected to a central cable, called the
bus or back bone. There are more than two endpoints which
are created by adding branches to the main section. If data
are being sent between nodes, the others cannot transmit. **BUS**
3. All devices are connected to one another in the shape of
a ring. Each device is connected directly to two other
devices, one on either side of it. Data travel in one direction
using a control signal called token.  **RING**
4. All the nodes of the network are connected to a common
transmission mediums with exactly two endpoints. The data
transmitted is received simultaneously by all the nodes in
the network. **LINE**
5. There is a direct link between all pairs of nodes. There
are multiple paths for data provided by a large number of
redundant links between nodes. **MESH**
6. There are redundant interconnections between network
nodes. Every node has a connection to any other node in
the network. **FULLY CONNECTED**
7. A hybrid type in which groups of star networks are
connected to a linear backbone, like in a a family tree. **TREE** 



## Read the texts pp. 104-105 and fill in the table below.
| TOPOLOGY | ADVANTAGES | DISADVANTAGES |
| ----------------- | -------- | -------------- |
| Bus | Inexpensive and easy to set up, it doesn't require much cable    | A damage or failure in the main cable will cause the whole network to fail or unusable. <br> If more than a few dozen computers are added to a bus network, the network will become slower because of possible collisions. <br> Every workstation on the network sees all of the data which is passing through the network|
| Ring | Transmission is fast and there is no risk of data collision | If the main cable fails or any device is faulty the whole network will fail.|
| Star | If one cable or device fails then all the others will continue to work | Cable and device are expensive to install because this type of network uses the most cable. <br>If also new hubs, switches or routers are required this will lead to extra cost. |
| Tree (Star bus) | It supports future expandibility of the network much better than a bus or star topology.<br>It is fault tolerant and easy to troubleshoot. |The installation of new hardware and additional cable makes it very expensive.|




## Exercise 6-7 p 107

Sequenza testo: **D-E-C-G-H-F-A-I**

1. **What is an Ethernet?**
Ethernet is not a single proguct, but rather a technical standard developed for network communications by Xerox, DEC and Intel, which the rest of the computer community have adopted.
 2. **Which network architecture will be found in an Ethernet?**
 All nodes, clients and servers on an Ethernet network are attached to the LAN which branches off a common line as in a bus configuration.
 3. **How does a node send data or messages through the network?** 
 When a node needs to send data to another node, it sends the data, or message, through the network interface card (NIC) installed in an expansion slot.
 4. **How is a message transmitted from node to node?**
Switches and routers use the information which is included in the message to determine where to forward the packet. In a network joined by hubs, the hubs themselves check the address to determine which packets to pay attention to and which to ignore. 
 6.   **How does a node with a message gain access to the network?**
 The network interface card listens to be sure that no other signals are being transmitted along the network. It then sends its message to another node through the network card's transceiver. Each node's network connection has its own transceiver.
 7. **What happens if two computers start transmitting messages simultaneously?**
When two nodes send messages simultaneously, the collision of the two messages creates a recognizable electrical interference pattern that travels along the bus. The request results in a "busy line" signal, which is detected by the senders.
 9. **How will all the other nodes know that the network is blocked?**
 The first sender to detect a collision sends a special signal that jams the network so that all nodes will know that the network is blocked.
 10. **What will these nodes do then?**
Transmission from all nodes is halted, and each node waits a random length of time before trying to resend its message. The process repeats itself until one of the nodes sends its message without encountering another node message.


In the Ethernet access method, all nodes on network operate like a conversation between **polite** people. When people meet and begin talking at the same time, one must wait until the other has finished. This happens very **quickly** as Ethernet LANs transmit **informations** at 2GB per second. The protocol **states** that all computers must sense the bus at all times. When a computer wants to send data or a message, it can do it **immediately** only if cannot **detect** any data on the bus. If there are other data being transmitted, then the node has to try later. Sometimes two or more computers start transmitting **simultaneously**.
If this happens, we say that a **collision** occurs. All the transmitting computers will receive a "busy line" signal and will have to stop sending data and try again after a random **length** of time.
If a network is **heavily** loaded, there will be many collisions.
As a consequence, the network **performance** will deteriorate.
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIxNDA3MzM1MDcsMTM1NDIyNTAxNiwtMT
AyNjA1Mjg0OCw5OTE4Nzc0MzQsMTE5NTQ3Mzc1LDczODcxODA2
MywtMjA5NzcyOTQ3NSw2MzU4OTMyMjcsMTIxNTA4MDU2MF19
-->
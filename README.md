# cpp_graph

##### This contains code on how to implement general purpose graph.
##### The main problem I faced while creating one is what to store in list of connected nodes/neighbouring nodes (in adjacency list). Let me explain. 
<code>let's say if we want to name the vertices in the form of character so a node should have following
<ul>
  <li>1. name/id of the node</li>
  <li>2. list of connected node</li>
 </ul>
if the name of the node is integer then there is no problem, in this situation accessing node from adjacency list is constant time but when the name of node is different then while implementing bfs or any other similar algorithm we will not be able to access to the node in constant time if the adjacency list is list of name/id. Solution to this is simple use list of pointer as adjacency list instead of list of name/id. 
Now I have to figure out what and how to store all nodes, wether we should store it as list of pointer to node or list of node. The problem with storing list of node is that sometimes it messes with the value of address of the node (When you store node in vector it changes it's location so sometimes address changes, sometimes not always, I don't know why). So, it is safe to store list of pointer to node rather than list of node as a graph or collection of node.</code>


#### conclusion
We should store both adjacency list and list of node as list of pointer to node.

# Searching shortest path in Matrix using Dijkstra's algorithm  
searching shortest path algorithm

# 1. INTRODUCTION

     Objective of our project was to find a shortest path from one point to other . So for that we use dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm).It  is an algorithm for finding the shortest paths between two nodes in a graph. For a given source node in the graph, the algorithm finds the shortest path between that node and every other. It can also be used for finding the shortest paths from a single node to a single destination node by stopping the algorithm once the shortest path to the destination node has been determined. We have use Code blocks   compiler for debugging and compiling the code.
# 2. WORKING METHODOLOGY

We want to find shortest distance between two points so we have choose Dijkstra's algorithm to solve these problem statement . It picks the unvisited vertex with the lowest distance, calculates the distance through it to each unvisited neighbour, and updates the neighbour’s distance if smaller. Mark visited when done with neighbours. Dijkstra's algorithm has many variants but the most common one is to find the shortest paths from the source vertex to all other vertices in the graph.
Algorithm Steps:

•	First we create an array named visited of size equal to number of vertices . Then  we mark all vertices as unvisited . That is we assign value 0 to all nodes. 
•	Then we create another array named distance and we assign  a value infinity to all the vertices except one which is starting vertex . We assign value 0 to starting vertex. Then we set our starting point as current vertex.  
•	For the current vertex, consider all of its unvisited neighbors and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbor B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, keep the current value.
•	When we are done considering all of the unvisited neighbors of the current node, mark the current node as visited i.e assign it with value 1 then due to these a visited node will never be checked again.
•	If the destination vertex has been marked visited (when planning a route between two specific vertices) or if the smallest tentative distance among the vertices in the unvisited set is infinity occurs when there is no connection between the initial vertex and remaining unvisited vertices), then stop. The algorithm has finished.
•	Otherwise, select the unvisited vertex that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.



# 3. INSIGHTS
1.	First  problem was that in dijkstras algorithm the edges should have some weights . But in our case there were no weights to our edges . So to solve these problem we first took the input array from user and we ask for the weights of each edges from user and we have told them that if an edge contain an obstacle then assign that edge with infinity value and all other edge 1 value.
2.	For dijkstras algorithm the input needed is of type adjesance matrix i.e it is a matrix which shows the relationship between edges i.e it shows whether the vertex is connected to other vertex or not . So to create these matrix we define the required matrix and except for the vertex whose i and j value are equal we assign all others to infinity and equals once to 0 and when user inputs the weight of that particular edge we replace the infinity value with that value in these way we created the adjesance matrix.


# Graph-header-file


This header file is made to simplify the process of creating a graph and performing certain operations and algorithms on it. It is highly useful in competitive programming where speed is of utmost essence.

How to use?

To initialise a graph, we need to create an object of the class. The constructor automatically creates an ajacency list of the size you sepcify. For example: if you want to create a graph which would contain 'n' nodes, you would do.

<b>`Graph g(n);` </b>

Now, we want to create edges.

So, 

<b>```g.addEdge(int u, int v, int weight);```</b>

For an unweighed graph, we could simply take the weights to be same.

Other funcitonalities like DFS, BFS, isCyclic are also added.

So, to check if there is cycle in the graph, just do :
``` g.isCyclic();```

or to traverse the graph by using DFS : 
```
vector<int> result;
result = g.DFS(int startingNode);
```






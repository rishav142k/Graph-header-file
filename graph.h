// Author : limestrapper

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue> // for BFS
#include <iostream>


class Graph {
	
	private:
	int numberOfNodes;
	std::vector<std::vector<std::pair<int, int > > > adjacencyList;
	
	public :
		
		void addEdge(int Node1, int Node2, int weight);
		std::vector<int> DFS(int source);
		std::vector<int> BFS(int source);
		void dfshelper(int source , std::vector<int> &nodesDiscovered, std::vector<bool> &visited);
		bool isCyclic();
		bool CyclicHelper(int node, std::vector<bool> &visited, int parent);
		bool isBipartite();
		bool isBipartiteHelper();
		void deleteGraph();
		Graph(int numberOfNodes);
		
};


#endif //GRAPH_H

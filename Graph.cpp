#include "graph.h"

using namespace std;

Graph::Graph(int numberOfNodes) {
	this->numberOfNodes = numberOfNodes;
	adjacencyList = vector<vector<pair<int, int> > > (numberOfNodes + 1);	
}


void Graph :: addEdge(int Node1, int Node2, int weight) {
	adjacencyList[Node1].push_back({Node2, weight});
	adjacencyList[Node2].push_back({Node1, weight});
}


vector<int> Graph::BFS(int source) {
		vector<int> nodesDiscovered;
		queue<int> nodesToDiscover;
		
		bool visited[numberOfNodes+1];
		
		for(int i = 0; i < numberOfNodes; i++) {
			visited[i] = 0;
		}
		
		nodesToDiscover.push(source);
		visited[source] = 1;  // visited the source and pushed it into the queue
		
		while(!nodesToDiscover.empty()) // loop till nodesToDiscover is empty, i.e. traversed all the nodes
		{
			int currentNode = 	nodesToDiscover.front();
			nodesToDiscover.pop();
			
			for(pair<int, int> neighbours : adjacencyList[currentNode]) {
				int neighbour = neighbours.first;
				if(!visited[neighbour]) {
					
					visited[neighbour] = 1;
					int neighbour = neighbours.first;
					nodesDiscovered.push_back(neighbour);
					// int weight = neighbours.second;
					
					nodesToDiscover.push(neighbour); /// pushed the node into the vector.
				}
			}
		}
	return nodesDiscovered; 
}
void Graph :: dfshelper(int source , vector<int> &nodesDiscovered, vector<bool> &visited) {
	visited[source] = 1;	
	nodesDiscovered.push_back(source);
	
	for(pair<int, int> neighbours : adjacencyList[source]) {
		int neighbour;
		
		neighbour = neighbours.first;
		//weight = neighbours.second;
		
		if(!visited[neighbour]) {
			dfshelper(neighbour, nodesDiscovered, visited);
		}
	}
}

vector<int> Graph :: DFS(int source) {
	vector<int> nodesDiscovered;
	vector<bool> visited(numberOfNodes + 1); 
	
	dfshelper(source, nodesDiscovered, visited);
	
	return nodesDiscovered;
}


bool Graph :: CyclicHelper(int node, vector<bool> &visited , int parent) {
	visited[node] = true;
	for(pair<int, int>  neighbours : adjacencyList[node]) {
		int neighbour = neighbours.first;
		if(!visited[neighbour]) {
			if(CyclicHelper(neighbour, visited, node)) {
				return true;
			}
		}
		else if(neighbour != parent) {
			return true;
		}
	}
return false;
}

bool Graph :: isCyclic() {
	vector<bool> visited(numberOfNodes + 1);
	for(int i = 1; i <= numberOfNodes; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= numberOfNodes; i++) {
		if(!visited[i]) {
			if(CyclicHelper(i, visited, -1)) {
				return true;
			}
		}
	}
return false;
}

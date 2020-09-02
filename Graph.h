#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue> // for BFS
#include <iostream>

using namespace std;


class Graph {
	
	int numberOfNodes;
	vector<vector<pair<int, int > > > adjacencyList;
	
	public :
		Graph(int numberOfNodes) {
			this->numberOfNodes = numberOfNodes;
			adjacencyList = vector<vector<pair<int, int> > > (numberOfNodes + 1);	
		}
		
		void addEdge(int Node1, int Node2, int weight);
		vector<int> DFS(int source);
		vector<int> BFS(int source);
		void dfshelper(int source , vector<int> &nodesDiscovered, vector<bool> &visited);
		
};

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

int main() {
	
    int n, m;
    cin >> n >> m;
    Graph G(n);
	int a,b;
	while(m--) {
		cin >> a >> b;
		G.addEdge(a, b, 0);
	}

    vector<int> res = G.DFS(3);
    
    
    cout << res.size() << "\n";
    for(unsigned int i = 0; i < res.size(); i++) {
    	cout << res[i] << " ";
    }

return 0;
}




#endif

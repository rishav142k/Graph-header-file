#include "graph.h"
#include <iostream>

using namespace std;

int main() {
	
	
	Graph g(10);
	
	g.addEdge(1,2,0);
	g.addEdge(2,3,0);
	g.addEdge(5,1,0);
	g.addEdge(4,2,0);
	g.addEdge(3,2,0);
	g.addEdge(3,5,0);
	g.addEdge(1,1,0);
	g.addEdge(4,3,0);
	
	 vector<int> res = g.DFS(1);
	cout << "BFS:";
	for(int i = 0 ; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	
return 0;
}

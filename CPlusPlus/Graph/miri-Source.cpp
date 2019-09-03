#include <iostream>
#include <fstream>
#include "clsGraph_i.hpp"


using namespace std;


int main()
{
	//test the individual methods
	mirielli::clsGraph graph("Simple Graph", mirielli::clsGraph::undirected);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);


	graph.add_edge(1, 2, 21, 1);
	graph.add_edge(1, 3, 22, 1);


	graph.print();


	//test the file I/O
	ifstream fin;
	ifstream fin2;
	mirielli::clsGraph fileGraph(fin, "AdjList.lst");
	mirielli::clsGraph fileGraph2(fin2, "AdjMatrix.tam");
	fileGraph.print();
	fileGraph2.print();
	
	return 0;
}
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEyNDAzMDY3NzhdfQ==
-->

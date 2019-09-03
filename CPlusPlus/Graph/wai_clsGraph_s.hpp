#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "wai_clsVertex.hpp"


using namespace std;

namespace Wai {
	class clsGraph {
	private:
		clsVertex* find_vertex(int vertexID);
		clsEdge* find_edge(int SRCvertexID, int DESTvertex);

	public:
		enum GraphType { undirected, directed }; //defines a graph type
		string ID; //a string used to identify a graph
		GraphType graphType; //a designation of a graph’s type
		int Graph_Size; //size of the graph
		int Edge_Count; //number of edges contained in graph

		clsGraph(); //graph default constructor (id=”ugraph”) (type=undirected)
		clsGraph(string id, GraphType g); //graph parameterized constructor
		clsGraph(ifstream& FIN, string FN);

		vector<clsVertex*> vertices; //a vector of pointers to the graph’s vertices

		//adds a pointer to a vertex to the graph’s vertices vector – must look up address first
		void add_vertex(int id);
		void add_edge(int sourceID, int destination, int id, double weight);

		// prints graph name and details, each vertex and its associated edges see screenshot below
		void print();
	};

}

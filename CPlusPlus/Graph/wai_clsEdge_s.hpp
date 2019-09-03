#pragma once

using namespace std;

namespace Wai {

	class clsVertex; //null reference class;

	class clsEdge  //declaration of a edge class
	{
	public:
		int ID; //integer used to uniquely identify an edge
		double weight; //a weight or cost of an edge – connection between 2 vertexes
		clsVertex *destination_vertex; //a pointer to the destination vertex class

		clsEdge(); //default constructor (id=0, weight=0)
		clsEdge(int, double); //parameterized constructor taking in ID and weight.

	};
}

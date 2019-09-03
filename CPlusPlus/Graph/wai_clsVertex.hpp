#pragma once


#include <vector>
#include "wai_clsEdge_i.hpp"


using namespace std;


namespace Wai {


	class clsVertex {
	public:
		int ID; //integer used to uniquely ID a vertex
		int inDegree;
		int outDegree;
		vector<Wai::clsEdge*> edges; //a vector of pointers to a vertex�s edges
	};
};


<!--stackedit_data:
eyJoaXN0b3J5IjpbMTExNjY4OTk2N119
-->
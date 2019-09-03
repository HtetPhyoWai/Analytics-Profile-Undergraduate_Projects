#pragma once
#include "wai_clsEdge_s.hpp"

namespace Wai {
	clsEdge::clsEdge()
	{
		ID = 0;
		weight = 0;
		destination_vertex = 0;
	}

	clsEdge::clsEdge(int id, double WEIGHT)
	{
		ID = id;
		weight = WEIGHT;
		destination_vertex = 0;
	}
}

#include "wai_clsgraphD_i.hpp"



int main()
{
	

	Wai ::graph G;

	int Shortest_Distance;

	G.Accept();
	G.Display();

	Shortest_Distance = G.Calc_Shortest_Dist();
	
	cout << "\ndistance is" << Shortest_Distance;
	
	return 0;


}
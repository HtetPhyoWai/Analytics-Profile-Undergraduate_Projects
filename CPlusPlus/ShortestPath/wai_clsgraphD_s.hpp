#pragma once
#include<iostream>
#define infinite 999

using namespace std;



namespace Wai
{
	class graph
	{
	int Graph[20][20];
		// Adjacency Matrix int No_of_Vertices;
	public:
		void Accept();
		void Display();
		int Calc_Shortest_Dist();

	private:

		int No_of_Vertices;


	};

}



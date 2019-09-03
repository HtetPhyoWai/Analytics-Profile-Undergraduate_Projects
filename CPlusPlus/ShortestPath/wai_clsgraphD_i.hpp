#pragma once

#include "wai_clsgraphD_s.hpp"


namespace Wai 
{



	void graph::Accept()
	{
		int i, j;

		cout << "Enter no of vertex";
		cin >> No_of_Vertices;
		
		for (i = 1; i <= No_of_Vertices; i++)
		{
			for (j = 1; j <= No_of_Vertices; j++)
			{
				Graph[i][j] = infinite;
			}
		}
		for (i = 1; i <= No_of_Vertices; i++)
		{
			for (j = i + 1; j <= No_of_Vertices; j++)
			{
				cout << "\n Please enter weight from" << i << "to" << j << ":";
				cin >> Graph[i][j];
				Graph[j][i] = Graph[i][j];
			}
		}
	}
	
	
	void graph::Display()
	{
		int i, j;
		cout << "Graphs Adjacency Matrix is\n";
		
		for (i = 1; i <= No_of_Vertices; i++)
		{
			for (j = 1; j <= No_of_Vertices; j++)
			{
				cout << "\t" << Graph[i][j];
			}
			cout << "\n";
		}
	}
	
	
	
	int graph::Calc_Shortest_Dist()
	{
		int cost, curr, src, cost1 = 0, desti, start, new1, i, k = 1, temp;
		int visited[20], dist[20];
		cout << "\nEnter the source";
		cin >> src;
		cout << "\nEnter the destination";
		cin >> desti;


		for (i = 0; i <= No_of_Vertices; i++)
		{
			visited[i] = 0;
			dist[i] = infinite;
		}

		visited[src] = 1;
		dist[src] = 0;
		curr = src;
		cout << "\nPath is" << src;
		while (curr != desti)
		{
			cost = infinite;
			start = dist[curr];
			for (i = 1; i <= No_of_Vertices; i++)
			{
				if (visited[i] == 0)
				{
					new1 = start + Graph[curr][i];
					if (new1 < dist[i])
						dist[i] = new1;
					if (dist[i] < cost)
					{
						cost = dist[i];
						temp = i;
					}
				}
			}
			curr = temp;
			visited[curr] = 1;
			cout << "\n Curr node is" << curr;
			cost1 = cost1 + cost;
		}
		return cost1;
	}


}


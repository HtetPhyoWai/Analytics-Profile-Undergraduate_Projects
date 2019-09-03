#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "wai_clsGraph_s.hpp"


namespace Wai {
	clsGraph::clsGraph()
	{
		ID = "undirectedGraph";
		graphType = undirected;
	}

	clsGraph::clsGraph(string id, GraphType g)
	{
		ID = id;
		graphType = g;
	}

	clsGraph::clsGraph(ifstream& FIN, string FN)
	{
		string tempStr;
		istringstream inStrStream;
		string Fext;
		string GraphName;
		string GraphTypeName;
		GraphType GType;
		clsVertex* sourceV;
		clsVertex* destV;
		clsEdge* Edge;
		int v1ID, v2ID;
		int eID = 1;

		double weight;

		int rowCount = 0;
		int colCount = 0;
		Fext = FN.substr(FN.find("."), FN.length() - 1);
		if (Fext == ".lst" || Fext == ".tam")
		{
			FIN.open(FN);
			if (FIN.good())
			{
				if (Fext == ".lst") //a list file has been found
				{
					while (!FIN.eof())
					{
						getline(FIN, tempStr);
						if (tempStr[0] != '/') //a data line has been found;
						{
							if (rowCount == 0) //first line of data in file nameing graph
							{
								GraphName = tempStr.substr(0, tempStr.find(" "));
								GraphTypeName = tempStr.substr(tempStr.find(" "), tempStr.length());

								ID = GraphName;
								if (GraphTypeName[1] == 'd' || GraphTypeName[1] == 'D')
									graphType = directed;
								else
									graphType = undirected;
							}
							else  //start of adjecency list
							{

								istringstream(tempStr) >> v1ID >> v2ID >> weight;
								add_vertex(v1ID);
								add_vertex(v2ID);
								add_edge(v1ID, v2ID, eID, weight);
								eID++;
							}
							rowCount++;
						}
					}
				}
				else
					if (Fext == ".tam") //this is a matrix based graph 
					{
						while (!FIN.eof())
						{
							getline(FIN, tempStr);
							if (tempStr[0] != '/') //a data line has been found;
							{
								if (rowCount == 0) //first line of data in file nameing graph
								{
									GraphName = tempStr.substr(0, tempStr.find(" "));
									GraphTypeName = tempStr.substr(tempStr.find(" "), tempStr.length());

									ID = GraphName;
									if (GraphTypeName[1] == 'd' || GraphTypeName[1] == 'D')
										graphType = directed;
									else
										graphType = undirected;
								}
								else  //start of adjecency Matrix
								{
									stringstream ss(tempStr);
									colCount = 0;
									while (ss >> v1ID)
									{
										colCount++;
										if (rowCount == 1) //this is start of the vertex list IDs
										{
											add_vertex(v1ID); //add vertex by id
										}
										else //this is the matrix of data
										{
											if (v1ID != 0)
											{
												add_edge(rowCount - 1, colCount, eID, v1ID);
											}
										}
										eID++;
									}
								}
								rowCount++;
							}
						}
					}
			} //if fext==file types
			//cout << "Rows=" << rowCount-2 << "  Columns=" << colCount << endl;
		}
	}

	clsVertex* clsGraph::find_vertex(int vertexID)
	{
		/*
		BEGIN Algorithm
			Declare pointer to vertex class as Vaddr = null
			Decalare vcount as integer = 0
			delcare vertexFound as boolean = false

			while (vertext found is false AND vcount less than verticies size)
				if vertices at (vount) ->ID = vertexID then
					vertexFound = true
					Vaddr = vertices at (vcount)
				end if
				increment vcount
			end while
			return Vaddr
		END Algorithm
		*/
		clsVertex* Vaddr = NULL;
		int vcount = 0;
		bool vertexFound = false;

		while ((vertexFound == false) && (vcount < vertices.size()))
		{
			if (vertices[vcount]->ID == vertexID)
			{
				vertexFound = true;

				Vaddr = vertices[vcount];
			}
			vcount++;

		}

		return Vaddr;
	}

	void clsGraph::add_vertex(int id) { //creates new vertex or creates vertex based on ID

		/*
		BEGIN Algorithm
		Declare pointer to vertex class as Vertex = null

		if (find_vertex(id) = null) then
			vertex = new clsVertex
			vertix->ID = id;
			insert vertex into END of verticies
			set Graph_size = vertices size
		end if

		END Algorithm
		*/

		clsVertex* Vertex = NULL;
		if (find_vertex(id) == NULL)
		{
			Vertex = new clsVertex;
			Vertex->ID = id;

			vertices.insert(vertices.end(), Vertex);

			Graph_Size = vertices.size();
		}

	}

	clsEdge* clsGraph::find_edge(int SRCvertexID, int DESTvertexID) {
		/*
		BEGIN Algorithm
		Declare pointer to vertex class as SourceVertex = null
		Declare pointer to vertex class as DestinatoinVertex = null
		Declare pointer to edge class as returnEDGE = null
		Declare edgeount as integer = 0
		Decalre EdgeFound as boolean = false

		Set sourceVertex = find_vertex(SRCvertexID)
		if (sourceVertex NOT null) then
			while (EdgeFound is false and edgecount less than sourceVertex->edges size
				if (sourceVertex->edges at edgecount -> destination_vertex->ID == DESTvertexID) then
					EdgeFound = true
					returnEDGE = sourceVertex->edges at edgecount
				endif
				increment edgecount
			end while
			return returnEDGE
		END Algorithm
		*/

		clsVertex* DestinationVertex = NULL;
		clsVertex* SourceVertex = NULL;
		clsEdge* returnEdge = NULL;
		int edgecount = 0;
		bool EdgeFound = false;

		SourceVertex = find_vertex(SRCvertexID);

		if (SourceVertex != NULL)
		{
			while ((EdgeFound == false) && (edgecount < SourceVertex->edges.size()))
			{
				if (SourceVertex->edges[edgecount]->destination_vertex->ID == DESTvertexID)
				{
					EdgeFound = true;

					returnEdge = SourceVertex->edges[edgecount];
				}
				edgecount++;

			}
		}
		return returnEdge;


	};

	void clsGraph::add_edge(int sourceID, int destination, int id, double weight)
	{
		/*
		BEGIN Algorithm

			Declare pointer to edge class as newEdge = null
			Declare pointer to edge class as foundedge = null
			Declare pointer to vertex class as SourceVertex = null
			Declare pointer to vertex class as DestinatoinVertex = null

			sourceVertex = find_vertex(sourceID)
			foundedge = find_edge(sourceID,destinationID)*/
		clsEdge* newEdge = NULL;
		clsEdge* foundEdge = NULL;
		clsVertex* SourceVertex = NULL;
		clsVertex* DestinationVertex = NULL;

		SourceVertex = find_vertex(sourceID);
		foundEdge = find_edge(sourceID, destination);

		/*	if (foundedge NULL) then
				set newedge = new clsedge
				set destinationVertex = find_vertex(destination)
				newedge->destination_vertex = destinationVertex
				newedge->ID = id;
				newedge->weight = weight;

				set sourceVertex->edges.push_back(newedge);

				//update the in/out degree counts -- note incrementing of edge direction direction
				increment sourceVertex outDegree
				increment destinationVertex inDegree
			end if */

		if (foundEdge == NULL)
		{
			newEdge = new clsEdge;
			DestinationVertex = find_vertex(destination);
			newEdge->destination_vertex = DestinationVertex;
			newEdge->ID = id;
			newEdge->weight = weight;

			SourceVertex->edges.push_back(newEdge);

			//update the in/out degree counts -- note incrementing of edge direction direction
			SourceVertex->outDegree++;
			DestinationVertex->inDegree++;
		}
		/*if (graphType is undirected) then
			foundedge = find_edge(destination, sourceID);
			if (foundedge is NULL) then
				Declare pointer to edge class as edge2 = null
				Set edge2 = new clsEdge;
				edge2->destination_vertex = find_vertex(sourceID)
				edge2->ID = id
				edge2->weight = weight
				newedge->destination_vertex->edges.push_back(edge2)

				//update the in/out degree counts -- note incrementing of edge direction direction
				increment sourceVertex inDegree
				increment destinationVertex outDegree
			end if
		end if

	END Algorithm
	*/

		if (graphType == undirected) 
		{	
			foundEdge = find_edge(destination, sourceID);

		if (foundEdge == NULL)
		{
			clsEdge* edge2 = NULL;
			edge2 = new clsEdge;
			edge2->destination_vertex = find_vertex(sourceID);
			edge2->ID = id;
			edge2->weight = weight;
			newEdge->destination_vertex->edges.push_back(edge2);

			//update the in/out degree counts -- note incrementing of edge direction direction
			SourceVertex->inDegree;

			DestinationVertex->outDegree;

			}
		}


	}

	void clsGraph::print()
	{
		string graphtype = "";
		string titlestr = "";

		if (this->graphType == this->directed) {
			graphtype = "Directed Graph";
		}
		else {
			graphtype = "Undirected Graph";
		}

		titlestr = this->ID + " === [" + graphtype + "]" + '\n';


		cout << endl;
		cout << "-----------------------------------------" << endl;
		cout << titlestr;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < vertices.size(); i++)
		{
			cout << vertices[i]->ID << "-> ";
			for (int a = 0; a < vertices[i]->edges.size(); a++)
			{
				cout << vertices[i]->edges[a]->destination_vertex->ID << ' ';
			}
			cout << " InDegree = " << vertices[i]->inDegree << " OutDegree = " << vertices[i]->outDegree;
			cout << endl;
		}
		cout << "-----------------------------------------" << endl;
	}
}
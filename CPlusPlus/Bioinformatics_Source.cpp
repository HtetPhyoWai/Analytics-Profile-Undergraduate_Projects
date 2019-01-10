//OBJECTIVES
//1)Read in standardized FASTA formatted protein structure data from a sequential text-based data file into a user-defined data structure.
//2)Parse and assign FASTA formatted protein structure data into an array capable of storing a protein structure’s definition, its amino acid sequence, and the protein’s length andweight in Dalton units.
//3)Output a report displaying processing results.

# Programmer Name :HTET PHYO WAI

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>


void InputfileName(char[]);
void print_description(const char[]);
void Length_Char(const  char[]);
void Proteinweight(char[], float & );
void LightestWeightcheck(float & weight);

using namespace std;

int main()
{


	ifstream DataIn;
	char userinput[50];
	char ProteinDescription[300]; // Declaring the array.
	char AminoAcidSequence[300]; 
	string record;
	int count = 1;
	float weight; 

	InputfileName(userinput);

	DataIn.open(userinput);
	cout << endl << endl;

	while (getline(DataIn, record) )
	{
		DataIn >> record;
		DataIn.get(ProteinDescription, 300);
		
		if ((record == "1") || (record == "3") || (record == "5"))
		{
			cout << "We are reading Protein '" << count << "' from our record" << endl;
			cout << "This is the Description of the Protein" << endl << endl;
			print_description(ProteinDescription);
			count++;
		}
		if ((record == "2") || (record == "4")|| (record == "6"))
			{  
				cout << "This is Amino Acid Sequence" << endl << endl;
				print_description(ProteinDescription);
				Length_Char(ProteinDescription);
				Proteinweight(ProteinDescription, weight);
				cout << "The total weight of the protein is " << weight << " Delton unit." << endl << endl;
				LightestWeightcheck(weight);
				cout << "---------------------------------------------------------------------" << endl;
				cout << endl;
			}
		
	}
	cout << endl << endl;
	DataIn.close();


// Exit the Program using user input
int EndInput; cout << "Press any key to exit " << endl; cin >> EndInput;

return 0;
}


void InputfileName(char userinput[])
{
	cout << "Please enter the file name to read (Type -  seqs.fasta.dat ) " << endl;
	cin.get ( userinput, 50);
}

void print_description(const char MyArray[])
{
	int ii = 0; int ArrayLength = 0;
	while (MyArray[ii] != '\0')
	{
		ArrayLength++; ii++;
	}

	//cout << "Printing the array : " << endl << endl;

	for (long i = 0; i <= ArrayLength; i++)
	{
		cout << MyArray[i];
	}
	cout << endl;
	cout << endl;
}

void Length_Char(const char MyArray[])
{

	int ii = 0;
	int ArrayLength = 0;
	while (MyArray[ii] != '\0')
	{
		ArrayLength++;
		ii++;
	}
	cout << "The length of the Amino Acid Sequence is " << ArrayLength << endl << endl;

}

void Proteinweight( char MyArray[], float & weight)
{

	int ii = 0; int ArrayLength = 0;  //Finding the ArrayLength to measure weight in the loop
	while (MyArray[ii] != '\0')
	{ ArrayLength++; ii++; }
	
	weight = 0; 
	
	for (long i = 0; i <= ArrayLength; i++)
	{
		if (MyArray[i] == 'G') { weight = weight + 57; } 
		if (MyArray[i] == 'A') { weight = weight + 71.1; }
		if (MyArray[i] == 'V') { weight = weight + 99.1; }
		if (MyArray[i] == 'L') { weight = weight + 113.2; }
		if (MyArray[i] == 'I') { weight = weight + 113.2; }
		if (MyArray[i] == 'M') { weight = weight + 131.2; }
		if (MyArray[i] == 'P') { weight = weight + 97.1; }
		if (MyArray[i] == 'F') { weight = weight + 147.2; }
		if (MyArray[i] == 'W') { weight = weight + 186.2; }
		if (MyArray[i] == 'S') { weight = weight + 87.1; }
		if (MyArray[i] == 'N') { weight = weight + 114.1; }
		if (MyArray[i] == 'Q') { weight = weight + 121.8; }
		if (MyArray[i] == 'Y') { weight = weight + 163.2; }
		if (MyArray[i] == 'C') { weight = weight + 103.1; }
		if (MyArray[i] == 'K') { weight = weight + 128.2; }
		if (MyArray[i] == 'R') { weight = weight + 156.2; }
		if (MyArray[i] == 'H') { weight = weight + 137.1; }
		if (MyArray[i] == 'D') { weight = weight + 115.1; }
		if (MyArray[i] == 'E') { weight = weight + 129.1; }
		if (MyArray[i] == 'T') { weight = weight + 101.1; }

	}
	//cout << endl ;
	


}

void LightestWeightcheck(float & weight)
{
	ifstream DataIn;
	DataIn.open("seqs.fasta.dat");
	string record; 	char ProteinDescription[300]; float weight0 = 0;
	float weight1 = 0; 	float weight2 = 0; 	float weight3 = 0;


	while (getline(DataIn, record))
	{
		DataIn >> record;
		DataIn.get(ProteinDescription, 300);

		Proteinweight(ProteinDescription, weight0);
		if (record == "2")  weight1 = weight0; 
		if (record == "4")  weight2 = weight0;
		if (record == "6")  weight3 = weight0; 	


		if ((record == "2") && (weight < weight2) && (weight < weight3)) { cout << "This is the protein with the lightest weight!" << endl; }
		if ((record == "4") && (weight < weight1) && (weight < weight3)) { cout << "This is the protein with the lightest weight!" << endl; }
		if ((record == "6") && (weight < weight2) && (weight < weight1)) { cout << "This is the protein with the lightest weight!" << endl; }

	}

	DataIn.close();

}

























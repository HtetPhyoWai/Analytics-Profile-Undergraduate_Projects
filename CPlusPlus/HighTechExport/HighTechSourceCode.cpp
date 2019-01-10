//Description
//This program use input data from world bank's 'High Techonlogy Export' indicators for various countries. 
//The program then execute the summary report of yearly export or specific country indicators based on the user input with use of struct data types, headers and modular data structures.

//Programmer Name: HTET PHYO WAI

#include <string>  // For string type 
#include <iostream> 
#include <fstream>  // For file I/O 
#include <iomanip>  // For output formatting 

#include "FileIOHEADER.h"  // User define library containing File IO. 
#include "IOHEADER_1.h"  // User defined library containing all I/O functions.
#include "Header_Structs1.h" // User defined library containing struct records of Years.

using namespace std;


//*****************************************************************************************************

int main() { 

	ifstream HighTechExport;
	ofstream CountryReport;
	ofstream SingleYearReport;
	ofstream SingleCountryReport;

	Year year;

	OpenFile(HighTechExport, "HighTechExport.in");   // function call   
	OpenFile(CountryReport, "CountryReport.out");  // function call

	CReport(HighTechExport, CountryReport, year);
	
	cout << "Please check CountryReport file in your drive for the summary report" <<endl << endl;

	CloseFile(CountryReport, "CountryReport.out");  // function call 
	CloseFile(HighTechExport, "HighTechExport.in");




	OpenFile(HighTechExport, "HighTechExport.in");
	OpenFile(SingleYearReport, "SingleYearReport.out");

	YearReport(HighTechExport, SingleYearReport, year);

	cout << "Please check SingleYearReport file in your drive for the summary report" << endl << endl;

	CloseFile(HighTechExport, "HighTechExport.in");     // function call   
	CloseFile(SingleYearReport, "SingleYearReport.out");





	OpenFile(SingleCountryReport, "SingleCountryReport.out");
	OpenFile(HighTechExport, "HighTechExport.in");

	SingleCReport(HighTechExport, SingleCountryReport, year);

	cout << "Please check SingleCountryReport file in your drive for the summary report" << endl <<  endl;


	CloseFile(SingleCountryReport, "SingleCountryReport.out");
	CloseFile(HighTechExport, "HighTechExport.in");     // function call   

	return 0;

}


	





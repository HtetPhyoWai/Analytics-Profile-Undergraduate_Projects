
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


	
/*
	try {   // Input.  Open Files.  
		OpenFile (CustomerDataIn, "CustMast.in");   // function call   
		OpenFile (DailyTransactionsIn, "DailyTrans.in");  // function call  
		OpenFile (LabelsOut, "Labels.doc");   // function call   
		OpenFile (CustomerMasterOut, "NewCustMast.out");  // function call 
		cout << endl << "********************************************" << endl; 

			// Process  
		Cust = ReadCust(CustomerDataIn, Cust);     // function call   
		ReadDailyTrans(DailyTransactionsIn, Trans);    // function call   
		cout<< "********************************************" << endl; 

		while (Cust.AcctNo != "EOF")      //(!CustomerDataIn.eof())  
		{    
			while (Trans.AcctNo != "EOF")    //(!DailyTransactionsIn.eof()) 

		{ if (Trans.AcctNo == Cust.AcctNo) 
			{
			Update(Cust, Trans);  // function call 

								  // Output results to Customer Master file.      
			WriteCMFile(CustomerMasterOut, Cust);  // function call     

								  // Increment Daily Transaction accumulator.      
			++NumberOfDailyTransProcessed; 

								  // Output results to Mailing Label file for Printing.       
			WriteMLFile(LabelsOut, Cust); // function call 

								  // Increment Number of Labels accummulator.        
			++NumberOfLabels;       
			} // End if. 

			ReadDailyTrans(DailyTransactionsIn, Trans); // function call     
			} // End While.         
			CloseFile(DailyTransactionsIn, "DailyTrans.in");  // function call     
			OpenFile(DailyTransactionsIn, "DailyTrans.in");  // function call     
			Cust = ReadCust(CustomerDataIn, Cust);   // function call    
			ReadDailyTrans(DailyTransactionsIn, Trans);  // function call 

		} // End While. 

		  // End of Program Tasks.   
			
			WriteSummary(NumberOfDailyTransProcessed, NumberOfLabels);  // function call      
																		
																		// Close Files.  
			CloseFile(CustomerDataIn, "CustMast.in");   // function call   
			CloseFile(DailyTransactionsIn, "DailyTrans.in"); // function call   
			CloseFile(LabelsOut, "Labels.doc");     // function call   
			CloseFile(CustomerMasterOut, "NewCustMast.out");  // function call    
	} //End try.  
	
	catch (exception & e)  
	{  
		cout << e.what() << endl << endl;  }  
	catch (...)  
	{   
		cout << "General exception caught." << endl << endl; 
	}   

		return 0;

} 




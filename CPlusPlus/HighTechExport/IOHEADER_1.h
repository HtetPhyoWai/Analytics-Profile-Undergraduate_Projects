#ifndef IOHEADER_1 
#define IOHEADER_1 

#include <string>  // For string type
#include <iostream> 
#include <fstream>  // For file I/O 
#include <iomanip>  // For output formatting 

#include "Header_Structs1.h" 

using namespace std;

void OpenFile(ifstream &, string);
void OpenFile(ofstream &, string);
void CloseFile(ifstream &, string);
void CloseFile(ofstream &, string);
void CReport(ifstream&, ofstream &, Year);
void YearReport(ifstream&, ofstream &, Year);
void SingleCReport(ifstream&, ofstream &, Year);


void CReport(ifstream& HighTechExport, ofstream & CountryDetailOut, Year y3er)
{
	 
	 string record;
	 float first5yravg;
	 float last5yravg;
	 int countrecord = 1;
	 int totalcountrecord;

	 CountryDetailOut << "COUNTRY" << "         " << "2001" << " " << "2002" << " " << "2003" << " " << "2004" << " " << "2005" << " " << "2006"
		 << " " << "2007" << " " << "2008" << " " << "2009" << " " << "2010" << " " << "2001-5Avg" << " " << "2006-10Avg" << endl;

	while ( getline(HighTechExport, record))
	{


		HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
			>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
		
		first5yravg = (y3er.Y2001 + y3er.Y2002 + y3er.Y2003 + y3er.Y2004 + y3er.Y2005) / 5;
		last5yravg = (y3er.Y2006 + y3er.Y2007 + y3er.Y2008 + y3er.Y2009 + y3er.Y2010) / 5;

		CountryDetailOut << record << "         " << setprecision(2)<< y3er.Y2001 << "   " << setprecision(2) << y3er.Y2002 << "   " << setprecision(2) << y3er.Y2003 << "   "  
			<< setprecision(2) << y3er.Y2004 << "   " << setprecision(2) << y3er.Y2005 << "   " << setprecision(2) << y3er.Y2006
			<< "   " << setprecision(2) << y3er.Y2007 << "   " << setprecision(2) << y3er.Y2008 << "   " << setprecision(2) << y3er.Y2009 << "   " 
			<< setprecision(2) << y3er.Y2010 << "   " << setprecision(2) << first5yravg << "   " << setprecision(2) << last5yravg << endl;

		countrecord++;
		totalcountrecord = countrecord;
	}
	CountryDetailOut << "We have listed the total number of " << totalcountrecord << " countries from our record" << endl;

}
// End of CReport Function ******************************************************************************** 

void YearReport(ifstream& HighTechExport, ofstream & CountryYearOut, Year y3er)
{

	string record;
	int UserYear = 0;


	cout << "Please Enter a year you want(2001 -10) for summary report." << endl;
	cin >> UserYear;

	CountryYearOut << "COUNTRY" << "         " << UserYear << endl;

	if (UserYear == 2001)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010; 
			CountryYearOut << record << "         " << y3er.Y2001 << endl; }
	}
	else if (UserYear == 2002)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2002 << endl;
		}
	}
	else if (UserYear == 2003)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2003 << endl;
		}
	}
	else if (UserYear == 2004)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2004 << endl;
		}
	}
	else if (UserYear == 2005)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2005 << endl;
		}
	}
	else if (UserYear == 2006)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2006 << endl;
		}
	}
	else if (UserYear == 2007)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2007 << endl;
		}
	}
	else if (UserYear == 2008)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2008 << endl;
		}
	}
	else if (UserYear == 2009)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2009<< endl;
		}
	}
	else if (UserYear == 2010)
	{
		while (getline(HighTechExport, record)) {
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;
			CountryYearOut << record << "         " << y3er.Y2010 << endl;
		}
	}
}
// End of YearReport Function ********************************************************************************

void SingleCReport(ifstream& HighTechExport, ofstream & CountryDetailOut, Year y3er)
{

	string record;
	string UserCountry;


	cout << "Please Enter a country you want for summary report. Make sure there is no space in-between. e.g if your selected country is United States, try UnitedStates instead " << endl;
	cin >> UserCountry;

	CountryDetailOut << "COUNTRY" << "         " << "2001" << " " << "2002" << " " << "2003" << " " << "2004" << " " << "2005" << " " << "2006"
		<< " " << "2007" << " " << "2008" << " " << "2009" << " " << "2010" << endl;

	

		while (getline(HighTechExport, record))
		{
			HighTechExport >> record >> y3er.Y2001 >> y3er.Y2002 >> y3er.Y2003 >> y3er.Y2004 >> y3er.Y2005 >> y3er.Y2006
				>> y3er.Y2007 >> y3er.Y2008 >> y3er.Y2009 >> y3er.Y2010;

			if (record == UserCountry)
			{
			CountryDetailOut << UserCountry << "         " << setprecision(2) << y3er.Y2001 << "   " << setprecision(2) << y3er.Y2002 << "   " << setprecision(2) << y3er.Y2003 << "   "
				<< setprecision(2) << y3er.Y2004 << "   " << setprecision(2) << y3er.Y2005 << "   " << setprecision(2) << y3er.Y2006
				<< "   " << setprecision(2) << y3er.Y2007 << "   " << setprecision(2) << y3er.Y2008 << "   " << setprecision(2) << y3er.Y2009 << "   "
				<< setprecision(2) << y3er.Y2010 << endl;
			}
		
		}
	
}

#endif /* End of IOHeader_1 */

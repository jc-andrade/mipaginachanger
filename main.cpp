// TODO: ALLOW USER TO DECIDE THEIR FINAL CALENDAR FILENAME

/* 
 Created by Julio Andrade, all rights reserved. 
    Do not distribute.
    This program takes input an .ics file (calendar file) and changes the summaryof the event to make it shorter
 Written for Fruit Stand employees to use with their schedules
 */

#include <iostream> // Input output stream
#include <fstream> // File stream
#include <string>
#include <stdio.h> // For remove?
using namespace std;

int main()
{
    string month;
    string day;
    string strNew = "SUMMARY:";

    cout << "Hi! Make sure your calendar file is on the desktop.\n\nPlease enter the month the same way it's written in the file you downloaded. [Example: 04]: ";
    cin >> month;
    cout << "\nNow please, enter the day the same way: ";
    cin >> day;
    
    string strReplace = "SUMMARY:Schedule for week ";
    strReplace.append(month);
    strReplace.append("/");
    strReplace.append(day);
    
    string fileName = "Schedule for " + month + "_" + day + ".ics";
    
    ifstream inFile;
    inFile.open(fileName);
    ofstream outFile("New Schedule.ics");
    
    if (!inFile)
    {
        cout << "Error opening files!\nFollow the instructions carefully and re-run!" << endl;
	return 0;
    }
    
    string strTemp;
    
    while (getline(inFile, strTemp))
    {
        if (strTemp == strReplace)
            strTemp = strNew;
        
        outFile << strTemp << "\n";
    }

    remove(fileName.c_str());
    cout << "Thanks for using!" << endl;
}

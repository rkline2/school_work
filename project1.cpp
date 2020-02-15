#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

void printBoard(char testFile[], char line[])
{
        //creation of ifstream class object to read file
        ifstream inputStream;

        //open file 
        inputStream.open(testFile);

        int i = 0, row = 1;

        cout << "    1   2   3   4" << endl << row << "|  ";
        
        while(i<15)
        {
                //read line from file
                inputStream >> line;
                cout << line << "|  ";
                i++;

                //creates new row after 4 cols created
                if(i%4==0)
                {
                        row++;
                        cout << endl << row << "|  ";
                }
        }
        cout << endl << endl;
}


int main() 
{
        char test1[15], test2[15], test3[15], testFile[15], line[4];

        cout << "Enter test file: ";
        cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        printBoard(testFile, line);

        return 0;
}

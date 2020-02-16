#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;



int checkRow(int i, int row)
{
        //creates new row after 4 cols created
        if(i%4==0)
        {
                row++;
                cout << endl << row << "|  ";
        }

        return row;
}

void printBoard(char testFile[], char line[])
{
        //creation of ifstream class object to read file
        ifstream inputStream;

        //open file 
        inputStream.open(testFile);

        int i = 0, row = 1;
        int num = 0;

        cout << "    1   2   3   4" << endl << row << "|  ";

        while(i<15)
        {
                //read line/num from file
                inputStream >> num;

                if(num>9)
                {
                        cout << num << " |  ";
                        row = checkRow(i, row);
                        i++;
                }
                else
                        cout << num << "| ";
                        row = checkRow(i, row);
                        i++;
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

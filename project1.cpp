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
        if(i!=0 && i%4==0)
        {
                row++;
                cout << endl << row << "|  ";
        }

        return row;
}

void printBoard(char testFile[]) 
{
        //creation of ifstream class object to read file
        ifstream inputStream;

        //open file 
        inputStream.open(testFile);

        int i = 0, row = 1, num = 0;

        cout << "     1    2    3    4" << endl << row << "|  ";

        while(i<16)
        {
                //read line/num from file
                inputStream >> num;

                if(num>9)
                {
                        row = checkRow(i, row);
                        cout << num << "|  ";
                        i++;
                }
                else
                {
                        row = checkRow(i, row);
                        cout << " " << num << "|  ";
                        i++;
                }
        }

        cout << endl << endl;
}


int main() 
{
        char test1[15], test2[15], test3[15], testFile[15];

        cout << "Enter test file: ";
        cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        printBoard(testFile);

        return 0;
}

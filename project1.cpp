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


int checkCol(int i, int col)
{
        //restart col after new row is created
        if(i%4==0)
                col = 1;
        else
                col++;

        return col; 
}

void printBoard(char testFile[]) 
{
        //creation of ifstream class object to read file
        ifstream inputStream;

        //open file 
        inputStream.open(testFile);

        int i = 0, row = 1, col = 1, num = 0;
        int pointZero[2] = {0,0};

        cout << "     1    2    3    4" << endl << row << "|  ";

        while(i<16)
        {
                //read line/num from file
                inputStream >> num;

                if(num==0)
                {
                        pointZero[0] = row;
                        pointZero[1] = col;

                        row = checkRow(i, row);
                        col = checkCol(i, col);
                        i++;
                } else if(num>9) {
                        row = checkRow(i, row);
                        col = checkCol(i, col);
                        cout << num << "|  ";
                        i++;
                } else {
                        row = checkRow(i, row);
                        col = checkCol(i, col);
                        cout << " " << num << "|  ";
                        i++;
                }
        }

        cout << endl << endl;
        cout << "Coordinates of Zero are: (" << pointZero[0] << "," << pointZero[1] << ")" << endl;
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

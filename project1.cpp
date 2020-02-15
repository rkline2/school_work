#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

void printArray(char array[], int strLength)
{
        for(int i=0; i<strLength; i++)
        {
                cout << array[i] << " ";
        }
}


int main() 
{
        char test1[15], test2[15], test3[15], testFile[15], line[4];

        cout << "Enter test file: ";
        cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        ifstream inputStream;

        inputStream.open(testFile);

        int i = 0, row = 1;

        cout << "    1   2   3   4" << endl << row << "|  ";
        
        while(i<15)
        {
                inputStream >> line;
                cout << line << "|  ";
                i++;

                if(i%4==0)
                {
                        row++;
                        cout << endl << row << "|  ";
                }
        }

        cout << endl << endl;

        return 0;
}

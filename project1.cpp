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
        char test1[15];
        char test2[15];
        char test3[15];
        char testFile[15];
        char line[15];

        cout << "Enter test file: ";
        cin >> testFile;
        cout << "Test file chosen: " << testFile << endl;

        ifstream inputStream;

        inputStream.open(testFile);

        int i = 0;

        while(i<15)
        {
                inputStream >> line;
                cout << line << endl;
                i++;
        }

        return 0;
}

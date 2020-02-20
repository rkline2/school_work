#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>//will delete later
using namespace std;


void printBoard(int board[][4]);
void createBoard(string testFile);//char testFile[])

int main() 
{
        char testFile[15] = {0}, gameBoard[15] = {0};
        string tempTestFile = "proj1_test1.txt";


        //cout << "Enter test file: ";
        //cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        //createBoard(testFile);
        createBoard(tempTestFile);
        //create testFile pointer and pass it into gamePlay function
        //cout << "Test file: " << &testFile << endl;

        return 0;
}

void printBoard(int board[][4])
{
        int row = 1;
        cout << "     1    2    3    4" << endl << row << "|  ";

        for(int i=0; i<4; i++)
        {
                if(row>1)
                        cout << endl << row << "|  ";

                for(int j=0; j<4; j++)
                {
                        if(board[i][j]<10)
                        {
                                cout << " "<< board[i][j] << "|  ";
                        }
                        else
                        {
                                cout << board[i][j] << "|  ";
                        }
                }
        row++;
        }
        cout << endl << endl;
}

void createBoard(string testFile)//char testFile[])
{
        int board[4][4], num = 0;

        ifstream inputStream;

        inputStream.open(testFile);

        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        inputStream >> num;
                        board[i][j] = num;
                }
        }

        printBoard(board);
}

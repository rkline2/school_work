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

int checkCol(int i, int col)
{
        //restart col after new row is created
        if(i%4==0)
                col = 1;
        else
                col++;

        return col; 
}

/*void gamePlay(char gameBoard)
{

}*/

void printBoard(int board[][4])
{
        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        cout << board[i][j];
                }
        }
}

void createBoard(char testFile[])
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
                        row = checkRow(i, row);
                        col = checkCol(i, col);
                        pointZero[0] = row;
                        pointZero[1] = col;
                        cout << " " << num << "|  ";
                        i++;
                } 
                else if(num>9)
                {
                        row = checkRow(i, row);
                        col = checkCol(i, col);
                        cout << num << "|  ";
                        i++;
                }
                else
                {
                        row = checkRow(i, row);
                        col = checkCol(i, col);
                        cout << " " << num << "|  ";
                        i++;
                }
        }

        cout << endl << endl;
        cout << "Coordinates of Zero are: (" << pointZero[0] << "," << pointZero[1] << ")" << endl <<endl;
}

int main() 
{
        char testFile[15] = {0}, gameBoard[15] = {0};

        cout << "Enter test file: ";
        cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        //start of game
        //printInitBoard(testFile);

        createBoard(testFile);

        //create testFile pointer and pass it into gamePlay function
        cout << "Test file: " << &testFile << endl;

        return 0;
}

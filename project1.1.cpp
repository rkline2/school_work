#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>//will delete later
using namespace std;


void print1dBoard(int board1d[16]);
void print2dBoard(int board2d[][4]);
void createBoard(string testFile, int board1d[16], int board2d[][4]);//char testFile[])
void changeBoard(int board2d[][4], int row, int col);
void playGame(int board2d[][4], int board1d[16], int findZero[2], int validNeighbor[4]);
void findZero(int board2d[][4], int board1d[16], int findZero[2], int validNeighbor[4]);
void sanitizer(int board2d[][4], int zero[2], int validNeighbor[4]);

const int ABOVE = 0;
const int RIGHT = 1;
const int BELOW = 2;
const int LEFT = 3;

int main() 
{
        char testFile[15] = {0}, gameBoard[15] = {0};
        string tempTestFile = "proj1_test3.txt";
        int board1d[16], board2d[4][4], zero[2]={0}, validNeighbor[4]={0}, num = 0;
        //cout << "Enter test file: ";
        //cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        //createBoard(testFile);
        createBoard(tempTestFile, board1d, board2d); 
        //create testFile pointer and pass it into gamePlay function
        //cout << "Test file: " << &testFile << endl;
        print2dBoard(board2d);

        print1dBoard(board1d);

        playGame(board2d, board1d, zero, validNeighbor);

        //sanitizer(board2d, zero, validEntry);

        return 0;
}


void playGame(int board2d[][4], int board1d[16], int zero[2], int validNeighbor[4])
{
        int row = 0, col = 0;
        bool GAME_OVER = true;

        cout << "What is the row (left) and column (top) to slide?" << endl;
        cin >> row;
        cin >> col; 
        cout << endl;

        //function to find zero 
        findZero(board2d, board1d, zero, validNeighbor);

        //delete neighbors that are out of bounds
        sanitizer(board2d, zero, validNeighbor);


        //check if coordinates neighbor zero
        //switch(zero[0])

        //game loop
        while(GAME_OVER == true)
        {


        }
        //if they do, then call changeBoard



        cout << endl;
        cout << "valid neighbor ABOVE: " << validNeighbor[0] << endl;
        cout << "valid neighbor RIGHT: " << validNeighbor[1] << endl;
        cout << "valid neighbor BELOW: " << validNeighbor[2] << endl;
        cout << "valid neighbor LEFT: " << validNeighbor[3] << endl;


        changeBoard(board2d, row, col);

        print2dBoard(board2d);
}

void validOptions(int board2d[][4], int zero[2], int validNeighbor[4])
{
        //validEntry[0] = board2d[i-1][j];
        //validEntry[1] = board2d[i][j+1];
        //validEntry[2] = board2d[i+1][j];
        //validEntry[3] = board2d[i][j-1];
}

void sanitizer(int board2d[][4], int zero[2], int validNeighbor[4])
{ 
        switch(zero[0])
        {
                case 0: cout << "first row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[ABOVE] = -1;
                                        validNeighbor[LEFT] = -1; 
                                        break;
                                case 1: cout << "second col";
                                        validNeighbor[ABOVE] = -1;
                                        break;
                                case 2: cout << "third col";
                                        validNeighbor[ABOVE] = -1;
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[ABOVE] = -1;
                                        validNeighbor[RIGHT] = -1;
                                        break;
                        }
                        break;
                        
 case 1: cout << "second row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[LEFT] = -1;
                                        break;
                                case 1: cout << "second col";
                                        break;
                                case 2: cout << "third col";
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[RIGHT] = -1;
                                        break;
                        }
                        break;

                case 2: cout << "third row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[LEFT] = -1;
                                        break;
                                case 1: cout << "second col";
                                        break;
                                case 2: cout << "third col";
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[RIGHT] = -1;
                                        break;
                        }
                        break;
              case 3: cout << "fourth row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[LEFT] = -1;
                                        validNeighbor[BELOW] = -1;
                                        break;
                                case 1: cout << "second col";
                                        validNeighbor[BELOW] = -1;
                                        break;
                                case 2: cout << "third col";
                                        validNeighbor[BELOW] = -1;
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[RIGHT] = -1;
                                        validNeighbor[BELOW] = -1;
                                        break;
                        }
                        break;
        }
        cout << endl;
}

void findZero(int board2d[][4], int board1d[16], int zero[2], int validNeighbor[4])
{

        /*
        int zero1d = 0;

        for(int i=0; i<16; i++)
        {
                if(board1d[i] == 0)
                {
                        zero1d = board1d[i];

                        validEntry[0] = board1d[i-4];
                        validEntry[1] = board1d[i+1];
                        validEntry[2] = board1d[i+4];
                        validEntry[3] = board1d[i-1];
                }
        }
        */

        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        if(board2d[i][j] == 0)
                        {
                                zero[0] = i;
                                zero[1] = j;
                                
                                                        if(board2d[i][j] == 0)
                        {
                                zero[0] = i;
                                zero[1] = j;

                                validNeighbor[ABOVE] = board2d[i-1][j];
                                validNeighbor[RIGHT] = board2d[i][j+1];
                                validNeighbor[BELOW] = board2d[i+1][j];
                                validNeighbor[LEFT] = board2d[i][j-1];
                        }
                }

        }

        cout << "row: " << zero[0]+1 << endl;
        cout << "col: " << zero[1]+1 << endl << endl;

        cout << "above: " << validNeighbor[ABOVE] << endl;
        cout << "right: " << validNeighbor[RIGHT] << endl;
        cout << "below: " << validNeighbor[BELOW] << endl;
        cout << "left: " << validNeighbor[LEFT] << endl;
}

void changeBoard(int board2d[][4], int row, int col)
{
        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        continue;
                }
        }
}

void print2dBoard(int board2d[][4])
{
        int row = 1;
        cout << endl << "     1    2    3    4" << endl << row << "|  ";

        for(int i=0; i<4; i++)
        {
                if(row>1)
                        cout << endl << row << "|  ";

                for(int j=0; j<4; j++)
                {
                        if(board2d[i][j]<10)
                                cout << " "<< board2d[i][j] << "|  ";
                        else
                                cout << board2d[i][j] << "|  ";
                }
        row++;
        }
        cout << endl << endl;
}

void print1dBoard(int board1d[16])
{ 
        cout << endl;

        for(int i=0; i<16; i++)
        {
                cout << board1d[i] << ", ";
        }

        cout << endl;
}

void createBoard(string testFile, int board1d[16], int board2d[][4])//char testFile[])
{
        int num = 0, k = 0;

        ifstream inputStream;

        inputStream.open(testFile);

        for(int i=0; i<16; i++)
        {
                inputStream >> num;
                board1d[i] = num;
        }

        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        board2d[i][j] = board1d[k];
                        k++;
                }
        }
}

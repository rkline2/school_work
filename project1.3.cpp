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
void createBoard(string testFile, int board2d[][4]);//char testFile[])
void changeBoard(int board2d[][4], int row, int col);
void playGame(int board2d[][4], int findZero[2], int validNeighbor[4]);
void findZero(int board2d[][4], int findZero[2], int validNeighbor[4]);
void sanitizer(int board2d[][4], int zero[2], int validNeighbor[4]);
int inputValidation(int num);
void neighborsValidation(int board2d[][4], int row, int col, int validNeighbor[4], int zero[4]);
void checkNeighbors(int validNeighbor[4]);

const int ABOVE = 0;
const int RIGHT = 1;
const int BELOW = 2;
const int LEFT = 3;

const int CLEAR= 0;

const int MAX_ROW = 4;
const int MIN_ROW = 1;

const int MAX_COL = 4;
const int MIN_COL = 1;
const int COORDINATES = 2;

const int TOTAL_NEIGHBORS = 4;

int main() 
{
        char testFile[15] = {0}, gameBoard[15] = {0};
        string tempTestFile = "proj1_test3.txt";
        int board1d[16], board2d[MAX_ROW][MAX_COL], zero[COORDINATES]={0}, validNeighbor[TOTAL_NEIGHBORS]={0}, num = 0;
        //cout << "Enter test file: ";
        //cin >> testFile;
        cout << "Test file chosen: " << testFile << endl << endl;

        //createBoard(testFile);
        createBoard(tempTestFile, board2d); 
        //create testFile pointer and pass it into gamePlay function
        //cout << "Test file: " << &testFile << endl;
        //print2dBoard(board2d);

        //print1dBoard(board1d);

        playGame(board2d, zero, validNeighbor);


        return 0;
}

void playGame(int board2d[][MAX_COL], int zero[COORDINATES], int validNeighbor[TOTAL_NEIGHBORS])
{
        int row, col = CLEAR;
        bool GAME_OVER = false;


        while(GAME_OVER == false)
        {
                print2dBoard(board2d);

                //function to validate input
                row = inputValidation(row);
                col = inputValidation(col);

                //function to find zero 
                findZero(board2d, zero, validNeighbor);

                //check neighbors
                checkNeighbors(validNeighbor);

                //clear neighbors that are out of bounds
                sanitizer(board2d, zero, validNeighbor);

                //check neighbors
                checkNeighbors(validNeighbor);

                //check if coordinates neighbor zero
                //neighborsValidation(board2d, row, col, validNeighbor, zero);

                //check neighbors
                //checkNeighbors(validNeighbor);
                
                 //move the game piece
                board2d[row][col] = board2d[zero[0]][zero[1]];
                board2d[zero[0]][zero[1] = board2d[row][col]];
                //check to see if board matches winning board

                //if so, game_over = true.

        }


        cout << endl;
        //cout << "valid neighbor ABOVE: " << validNeighbor[0] << endl;
        //cout << "valid neighbor RIGHT: " << validNeighbor[1] << endl;
        //cout << "valid neighbor BELOW: " << validNeighbor[2] << endl;
        //cout << "valid neighbor LEFT: " << validNeighbor[3] << endl;
}

void checkNeighbors(int validNeighbor[TOTAL_NEIGHBORS])
{
        for(int i=0; i<4; i++)
        {
                cout << "Valid neighbor: " << validNeighbor[i] << endl;
        }
        cout << endl;
}

void neighborsValidation(int board2d[][MAX_COL], int row, int col, int validNeighbor[TOTAL_NEIGHBORS], int zero[COORDINATES])
{
        bool input = false;
        int count = 0;

        while(input == false)
        {
                if(board2d[row][col] == validNeighbor[ABOVE] ||
                board2d[row][col] == validNeighbor[RIGHT] ||
                board2d[row][col] == validNeighbor[LEFT] || 
                board2d[row][col] == validNeighbor[BELOW])
                {
                        input = true;
                }

                else
                {
                        cout << endl << count << " Invalid input, try again." << endl;
                        cout << "Board coordinates: " << row << ", " << col << endl;
                        cout << "Zero coordinates: " << zero[0] << ", " << zero[1] << endl;

                        print2dBoard(board2d);
                        row, col = CLEAR;
                        row = inputValidation(row);
                        col = inputValidation(col);
                        count++;
                        input = false;

                }
                
                        }
}

int inputValidation(int num)
{
        while(num<1 || num>4)
        {
                cout << "What is the row (left) and column (top) to slide?" << endl;
                cin >> num;
        }

        return num;
}

void sanitizer(int board2d[][MAX_COL], int zero[COORDINATES], int validNeighbor[TOTAL_NEIGHBORS]) 
{ 
        switch(zero[0])
        {
                case 0: cout << "first row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[ABOVE] = CLEAR;
                                        validNeighbor[LEFT] = CLEAR; 
                                        break;
                                case 1: cout << "second col";
                                        validNeighbor[ABOVE] = CLEAR;
                                        break;
                                case 2: cout << "third col";
                                        validNeighbor[ABOVE] = CLEAR;
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[ABOVE] = CLEAR;
                                        validNeighbor[RIGHT] = CLEAR;
                                        break;
                        }
                        break;
case 1: cout << "second row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[LEFT] = CLEAR;
                                        break;
                                case 1: cout << "second col";
                                        break;
                                case 2: cout << "third col";
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[RIGHT] = CLEAR;
                                        break;
                        }
                        break;

                case 2: cout << "third row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[LEFT] = CLEAR;
                                        break;
                                case 1: cout << "second col";
                                        break;
                                case 2: cout << "third col";
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[RIGHT] = CLEAR;
                                        break;
                        }
                        
                          break;

                case 3: cout << "fourth row ";
                        switch(zero[1])
                        {
                                case 0: cout << "first col";
                                        validNeighbor[LEFT] = CLEAR;
                                        validNeighbor[BELOW] = CLEAR;
                                        break;
                                case 1: cout << "second col";
                                        validNeighbor[BELOW] = CLEAR;
                                        break;
                                case 2: cout << "third col";
                                        validNeighbor[BELOW] = CLEAR;
                                        break;
                                case 3: cout << "fourth col";
                                        validNeighbor[RIGHT] = CLEAR;
                                        validNeighbor[BELOW] = CLEAR;
                                        break;
                        }
                        break;
        }
        cout << endl;
}

void findZero(int board2d[][MAX_COL], int zero[COORDINATES], int validNeighbor[TOTAL_NEIGHBORS])
{
        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        if(board2d[i][j] == 0)
                        {
                                zero[0] = i+1;
                                zero[1] = j+1;

                                validNeighbor[ABOVE] = board2d[i-1][j];
                                validNeighbor[RIGHT] = board2d[i][j+1];
                                validNeighbor[BELOW] = board2d[i+1][j];
                                validNeighbor[LEFT] = board2d[i][j-1];
                        }
                }

        }

        //cout << "row: " << zero[0]+1 << endl;
        //cout << "col: " << zero[1]+1 << endl << endl;

        cout << "above: " << validNeighbor[ABOVE] << endl;
        cout << "right: " << validNeighbor[RIGHT] << endl;
        cout << "below: " << validNeighbor[BELOW] << endl;
        cout << "left: " << validNeighbor[LEFT] << endl;
}

void print2dBoard(int board2d[][MAX_COL])
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


void createBoard(string testFile, int board2d[][MAX_COL])//char testFile[])
{
        int num = 0, k = 0;

        ifstream inputStream;

        inputStream.open(testFile);

        for(int i=0; i<4; i++)
        {
                for(int j=0; j<4; j++)
                {
                        inputStream >> num;
                        board2d[i][j] = num;
                }
        }
}

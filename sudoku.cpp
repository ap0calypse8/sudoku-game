#include<iostream>
#include"sudoku.h"
#include<cstdlib>
#include<algorithm>
#include<random>


sudoku::sudoku() : board(9 , std::vector<int>(9 , 0))   {}   //a 2D vector to take rows and columns  


void sudoku::generatepuzzle() { //function to genearte the puzzle
    //generatesolution();//function to generate the complete puzzle
    do {solvesudoku();
    removenumbers();
    } while (!checkSolvable());
}

bool sudoku::solvesudoku() {
    return solvesudokuHelper(0, 0);
}

bool sudoku::solvesudokuHelper(int row, int col) {
    if (row == 9) {
        return true; // Base case: solution found
    }

    if (col == 9) {
        return solvesudokuHelper(row + 1, 0); // Move to the next row
    }

    if (board[row][col] != 0) {
        return solvesudokuHelper(row, col + 1); // Skip filled cells
    }

    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //std::random_shuffle(values.begin(), values.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);


    for (int num : values) {
        if (isvalid(row, col, num)) {
            board[row][col] = num;
            if (solvesudokuHelper(row, col + 1)) {
                return true;
            }
            board[row][col] = 0; // Backtrack: reset the cell to 0
        }
    }

    return false;
}


    void sudoku::displaypuzzle() { //displays the puzzle
        for(int i = 0 ; i < 9 ; ++i){
            if( i % 3 == 0 && i != 0) {
                std::cout << "---------------------"<<"\n";
            }
            for(int j = 0; j < 9 ; ++j){
                if(j % 3 == 0 && j!= 0){
                    std::cout<<"|";
                }
                std::cout<<board[i][j] << " ";
            }
            std::cout<<"\n";
        }
    }


//function to check for valid moves
bool sudoku::isvalid(int row, int col, int num) const {

    if(board[row][col] != 0){ //checks if the cell is preoccupied
        return false;
    }

    for(auto i = 0; i < 9 ; ++i){ //checks if the entered value is already in row and column 
        if(board[row][i] == num || board[i][col] == num ) {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(auto i = 0; i < 9; ++i){
        for(auto j = 0; j < 9; ++j){
        if(board[i + startRow][j + startCol] == num) {
            return false;
        }
    }
}
    return true;
}

//function to fill in each cell with a number
bool sudoku::fillCell(int row, int col,int num) {
    if(isvalid(row,col,num)){
        board[row][col] = num;
        return true;
    }
    return false;
}


/*void  sudoku::generatesolution() { //function to generate the entire sudoku
        std::vector<int> values = {1,2,3,4,5,6,7,8,9};
        for(auto i = 0; i < 9; ++i){
            std::random_shuffle(values.begin(),values.end());
            for(auto j = 0; j < 9 ; ++j){
                board[i][j]=values[j];
            }
        }
    }*/

void sudoku::removenumbers() { //removes values from the complete puzzle
    int remove = 30;
    while( remove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if(board[row][col] != 0){
            board[row][col] = 0;
            --remove;
        }
    }
}


bool sudoku::checkSolvable() {
    sudoku temp = *this; // Create a copy of the current puzzle
    return temp.solvesudokuHelper(0, 0); // Check if the puzzle is solvable
}
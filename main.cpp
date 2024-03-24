#include<iostream>
#include <algorithm>
#include <random>
#include <vector>
#include "sudoku.h"
#include <ctime>

int main() {
    sudoku game;
    game.generatepuzzle(); // Generate the Sudoku puzzle
    std::cout << "Sudoku Puzzle:" << std::endl;
    game.displaypuzzle(); // Display the puzzle

    


    if (game.checkSolvable()) {
        std::cout << "The puzzle is solvable." << std::endl;
    } else {
        std::cout << "The puzzle is not solvable." << std::endl;
        // Take appropriate action if the puzzle is not solvable
    }




    // Main game loop
    while (true) {
        int row, col, num;
        std::cout << "Enter row, column, and number (0 0 0 to quit): ";
        std::cin >> row >> col >> num;

        if (row == 0 && col == 0 && num == 0) {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            std::cout << "Invalid input. Please enter row, column, and number between 1 and 9." << std::endl;
            continue;
        }

        if (!game.fillCell(row - 1, col - 1, num)) {
            std::cout << "Invalid move. Please try again." << std::endl;
            continue;
        }

        std::cout << "Updated Sudoku Puzzle:" << std::endl;
        game.displaypuzzle(); // Display the updated puzzle
    }

    return 0;
}
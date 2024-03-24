#pragma once

#include<vector>

class sudoku {
    private:
        std::vector<std::vector<int>> board;
        //void generatesolution();
        bool solvesudoku();
        bool solvesudokuHelper(int row,int col);
        void removenumbers();

    public:
    sudoku();
    void generatepuzzle();
    void displaypuzzle();
    bool isvalid(int row, int col, int num) const;
    bool fillCell(int row, int col,int num);
    bool checkSolvable();

};
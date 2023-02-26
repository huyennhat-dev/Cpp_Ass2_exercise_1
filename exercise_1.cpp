#include <iostream>

const int ROWS = 3;
const int COLS = 3;

bool isLoShuMagicSquare(int square[ROWS][COLS]) {
    int sum = 0;

    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += square[i][j];
        }
        if (i == 0) {
            sum = rowSum;
        }
        else if (rowSum != sum) {
            return false;
        }
    }

    for (int j = 0; j < COLS; j++) {
        int colSum = 0;
        for (int i = 0; i < ROWS; i++) {
            colSum += square[i][j];
        }
        if (colSum != sum) {
            return false;
        }
    }

    int diagSum1 = square[0][0] + square[1][1] + square[2][2];
    int diagSum2 = square[0][2] + square[1][1] + square[2][0];
    if (diagSum1 != sum || diagSum2 != sum) {
        return false;
    }

    return true;
}

int main() {
    int square[ROWS][COLS];

    std::cout << "Enter values for the 3x3 Lo Shu Magic Square:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cin >> square[i][j];
        }
    }

   
    if (isLoShuMagicSquare(square)) {
        std::cout << "The square is a Lo Shu Magic Square!" << std::endl;
    }
    else {
        std::cout << "The square is not a Lo Shu Magic Square." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std::chrono;

const int MATRIX_SIZE = 400;

// Fill a matrix with random values
void fillRandomMatrix(int matrix[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
        for (int j = 0; j < MATRIX_SIZE; ++j)
            matrix[i][j] = rand() % 100;
}

// Multiply two matrices
void multiplyMatrices(const int matrix1[][MATRIX_SIZE], const int matrix2[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; ++k)
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

int main()
{
    srand(time(nullptr));

    int matrix1[MATRIX_SIZE][MATRIX_SIZE];
    int matrix2[MATRIX_SIZE][MATRIX_SIZE];
    int resultMatrix[MATRIX_SIZE][MATRIX_SIZE];

    // Fill matrices with random values
    fillRandomMatrix(matrix1);
    fillRandomMatrix(matrix2);

    auto startTime = high_resolution_clock::now();
    // Perform matrix multiplication
    multiplyMatrices(matrix1, matrix2, resultMatrix);
    auto stopTime = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    std::cout << "Multiplication completed in: " << duration.count() << " microseconds" << std::endl;

    // Write result to file
    std::ofstream outputFile("Sequential_Results.txt");
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
            outputFile << resultMatrix[i][j] << "\t";
        outputFile << std::endl;
    }
    outputFile << "Execution time: " << duration.count() << " microseconds";
    outputFile.close();

    return 0;
}

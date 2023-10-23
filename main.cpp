#include <iostream>
#include <fstream>
#include <vector>

#define name_of_file "matrix_input.txt"
static const int max_size = 100;

void reading_file(std::vector<std::vector<int>>& matrix_A, std::vector<std::vector<int>>& matrix_B, int& size);
void matrix_printing(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> adding_matrices(const std::vector<std::vector<int>>& matrix_A, const std::vector<std::vector<int>>& matrix_B, int size);
std::vector<std::vector<int>> multiplying_matrices(const std::vector<std::vector<int>>& matrix_A, const std::vector<std::vector<int>>& matrix_B, int size);
std::vector<std::vector<int>> contrast_between_matrices(const std::vector<std::vector<int>>& matrix_A, const std::vector<std::vector<int>>& matrix_B, int size);

int main() {
    int size;
    std::vector<std::vector<int>> matrixA;
    std::vector<std::vector<int>> matrixB;
    reading_file(matrixA, matrixB, size);

    std::cout << "Shero Baig" << std::endl;
    std::cout << "Lab #6: Matrix Manipulation" << std::endl;
    std::cout << "Matrix A:" << std::endl;
    matrix_printing(matrixA);
    std::cout << "Matrix B:" << std::endl;
    matrix_printing(matrixB);

    std::cout << "Matrix Sum (A+B):" << std::endl;
    std::vector<std::vector<int>> sum_matrix = adding_matrices(matrixA, matrixB, size);
    matrix_printing(sum_matrix);

    std::cout << "Matrix Product (A*B):" << std::endl;
    std::vector<std::vector<int>> multiplying_matrix = multiplying_matrices(matrixA, matrixB, size);
    matrix_printing(multiplying_matrix);

    std::cout << "Matrix Difference (A-B):" << std::endl;
    std::vector<std::vector<int>> difference_matrix = contrast_between_matrices(matrixA, matrixB, size);
    matrix_printing(difference_matrix);

    return 0;
}

void reading_file(std::vector<std::vector<int>>& matrix_A, std::vector<std::vector<int>>& matrix_B, int& size) {
    std::ifstream file(name_of_file);
    char text;
    std::string extra_text;
    file >> size;
    getline(file, extra_text);

    matrix_A.resize(size, std::vector<int>(size));
    matrix_B.resize(size, std::vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix_A[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix_B[i][j];
        }
    }

    file.close();
}

void matrix_printing(const std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> adding_matrices(const std::vector<std::vector<int>>& matrix_A, const std::vector<std::vector<int>>& matrix_B, int size) {
    std::vector<std::vector<int>> answer_matrix(size, std::vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            answer_matrix[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
    return answer_matrix;
}

std::vector<std::vector<int>> multiplying_matrices(const std::vector<std::vector<int>>& matrix_A, const std::vector<std::vector<int>>& matrix_B, int size) {
    std::vector<std::vector<int>> answer_matrix(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                answer_matrix[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    return answer_matrix;
}

std::vector<std::vector<int>> contrast_between_matrices(const std::vector<std::vector<int>>& matrix_A, const std::vector<std::vector<int>>& matrix_B, int size) {
    std::vector<std::vector<int>> answer_matrix(size, std::vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            answer_matrix[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }
    return answer_matrix;
}

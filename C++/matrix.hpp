#include <iostream>
using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();
    friend istream& operator>>(istream& in, Matrix& matrix);
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    Matrix operator*(Matrix &other);

private:
    int rows;
    int cols;
    int **matrix;
};

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) 
{
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        matrix[i] = new int[cols];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

istream& operator>>(istream& in, Matrix& matrix) 
{
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            in >> matrix.matrix[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& os, const Matrix& matrix) 
{
    for (int i = 0; i < matrix.rows; ++i) 
    {
        for (int j = 0; j < matrix.cols; ++j) 
        {
            os << matrix.matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix Matrix::operator*(Matrix &other) 
{
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < other.cols; ++j) 
        {
            result.matrix[i][j] = 0;
            for (int k = 0; k < cols; ++k)
            {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const unsigned int M = 3;
typedef double typeMatrix[M][M];

struct Matrix3x3
{
    typeMatrix items;
};

double findTheDeterminant3x3(double (& matrix)[M][M])
{
    double det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[0][2] * matrix[2][1];
    det = det - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[1][0] * matrix[0][1] * matrix[2][2] - matrix[0][0] * matrix[2][1] * matrix[1][2];

    return det;
};

double findTheAlgebraicComplements(double(&matrixIn)[M][M], int a, int b)
{
    int i1 = 0;
    int j1 = 0;
    double mat[M - 1][M - 1];

    for (int i = 0; i < M - 1; i++)
    {
        if (i == b)
        {
            i1 = i1 + 1;
        };
        for (int j = 0; j < M - 1; j++)
        {
            if (j == a)
            {
                j1 = j1 + 1;
            };
            mat[i][j] = matrixIn[i1][j1];
            j1 = j1 + 1;
        };
        j1 = 0;
        i1 = i1 + 1;
    };

    double det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    det = det * pow(-1, b+a);

    return det;
};

Matrix3x3 findInverseMatrix(double(&matrixIn)[M][M], double det)
{
    Matrix3x3 matrixOut;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrixOut.items[i][j] = findTheAlgebraicComplements(matrixIn, i, j) / det;
            if (matrixOut.items[i][j] == -0)
            {
                matrixOut.items[i][j] = 0;
            }
        }
    };

    return matrixOut;
};

int main(int argc, char* argv[]) {
    bool wasError = false;
    double matrixIn[M][M];

    Matrix3x3 matrixOut;
    if (argc != 2)
    {
        std::cout << "Invalid input format";
        return 0;
    }

    std::string file = argv[1];
    std::ifstream fileIn;
    fileIn.open(file);

    if (!(fileIn.is_open()))
    {
        std::cout << "������ �������� �����!" << std::endl;
        return 0;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fileIn >> matrixIn[i][j];
        };
        std::string str;
        std:: getline(fileIn, str);
    };

    double det = findTheDeterminant3x3(matrixIn);

    if (det == 0)
    {
        std::cout << "�� ���������� �������� �������" << std::endl;
        return 0;
    };

    matrixOut = findInverseMatrix(matrixIn, det);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << std::fixed << std::setprecision(3) << matrixOut.items[i][j];
            std::cout << " ";
        };
        std::cout << "\n\n";
    };

    //�������� ������
    fileIn.close();

    return 0;
}
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
  void clearScreen()
    {
        system("cls");
        cout << endl;
    }
template <typename T>
void showMatrix(T **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

void transpose()
{
    cout << "enter rows and coloumn of matrix\n";
    int p, q;
    cin >> p >> q;

    float **in1 = new float *[p];
    for (int i = 0; i < p; i++)
    {
        in1[i] = new float[q];
        for (int j = 0; j < q; j++)
        {
            in1[i][j] = 0;
        }
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << "entering 1st matrix\n";
            showMatrix(in1, p, q);
            cout << "enter element of 1st matrix\n";
            float ent;
            cin >> ent;
            in1[i][j] = ent;

            clearScreen();
        }
    }

    float **in2 = new float *[q];
    for (int i = 0; i < q; i++)
    {
        in2[i] = new float[p];
        for (int j = 0; j < p; j++)
        {
            in2[i][j] = 0;
        }
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            in2[j][i] = in1[i][j];
        }
    }

    cout << "transpose of the matrix: \n";
    showMatrix(in2, q, p);

    free(*in1);
    free(*in2);
}

void matrixMultiplication()
{
    cout << "enter rows and coloumn of first matrix\n";
    int p, q;
    cin >> p >> q;

    cout << "enter rows and coloumn of second matrix\n";
    int n, m;
    cin >> n >> m;

    // checking compatibility of matrices
    if (q != n)
    {
        cout << "matrix dimensions incompatible.... terminating program...";
        exit(1);
    }

    // allocating 1st input matrix array
    float **in1 = new float *[p];
    for (int i = 0; i < p; i++)
    {
        in1[i] = new float[q];
        for (int j = 0; j < q; j++)
        {
            in1[i][j] = 0;
        }
    }

    // allocating 2nd input matrix array
    float **in2 = new float *[n];
    for (int i = 0; i < n; i++)
    {
        in2[i] = new float[m];
        for (int j = 0; j < m; j++)
        {
            in2[i][j] = 0;
        }
    }

    // allocating output matrix array
    float **arr = new float *[p];
    for (int i = 0; i < p; i++)
    {
        arr[i] = new float[m];
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << "entering 1st matrix\n";
            showMatrix(in1, p, q);
            cout << "enter element of 1st matrix\n";
            float ent;
            cin >> ent;
            in1[i][j] = ent;

            clearScreen();
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "1st array : \n";
            showMatrix(in1, p, q);
            cout << "entering 2nd array\n";
            showMatrix(in2, n, m);
            cout << "enter element of 2nd matrix\n";
            float ent;
            cin >> ent;
            in2[i][j] = ent;

            clearScreen();
        }
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < m; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += in1[i][k] * in2[k][j];
            }
            arr[i][j] = sum;
        }
    }
    cout << "matrix multiplication of\n";
    showMatrix(in1, p, q);
    cout << "X\n";
    showMatrix(in2, n, m);
    cout << "is\n";
    showMatrix(arr, p, m);

    free(*in1);
    free(*in2);
    free(*arr);
}

float determinant(float **matrix, int size)
{
    if (size == 1)
    {
        return matrix[0][0];
    }
    if (size == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    float det = 0;
    float **submatrix = new float *[size - 1];

    for (int i = 0; i < size - 1; i++)
    {
        submatrix[i] = new float[size - 1];
    }

    for (int i = 0; i < size; i++)
    {
        int subi = 0;
        for (int j = 1; j < size; j++)
        {
            int subj = 0;
            for (int k = 0; k < size; k++)
            {
                if (k == i)
                    continue;
                submatrix[subi][subj] = matrix[j][k];
                subj++;
            }
            subi++;
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix, size - 1);
    }
    for (int i = 0; i < size - 1; i++)
    {
        delete[] submatrix[i];
    }
    delete[] submatrix;

    return det;
}

void dets()
{
    int size;
    cout << "Enter the size of matrix\n";
    cin >> size;
    float **matrix = new float *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new float[size];
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "entering matrix\n";
            showMatrix(matrix, size, size);
            cout << "enter element of 1st matrix\n";
            float ent;
            cin >> ent;
            matrix[i][j] = ent;

            clearScreen();
        }
    }

    cout << "determinant of\n";
    showMatrix(matrix, size, size);
    float res = determinant(matrix, size);
    cout << res << endl;

    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void mat()
{
    cout << "1.Matrix multiplication\n2.Matrix transpose\n3.Determinant\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        matrixMultiplication();
        break;
    case 2:
        transpose();
        break;
    case 3:
        dets();
        break;
    default:
        break;
    }
}

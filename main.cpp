#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
namespace oper
{
    void clearScreen()
    {
        system("cls");
        cout << endl;
    }

    namespace settings
    {
        void initialize_settings(vector<bool> &setting)
        {
            setting.push_back(true); // running = true .setting[0] = true
            setting.push_back(true); // settings::angle::radian = true&degree = false . setting[1]
        }

        void do_settings(vector<bool> &setting)
        {
            cout << "1.ANGLE" << endl; // choices for settings menu
            int n;
            cin >> n;
            switch (n)
            {
            case 1: // for 1.angle
                cout << "Degree(d) or radian(r)?";
                char c;
                cin >> c;
                if (c == 'd' || c == 'D')
                {
                    setting[1] = false;
                    cout << "angle set to degree\n";
                }
                else if (c == 'r' || c == 'R')
                {
                    setting[1] = true;
                    cout << "angle set to radian\n";
                }
                break;

            default:
                break;
            }
        }

    }

    namespace arithmatic
    {
        void arithmatics()
        {

            cout << "ARITHMATIC:\n";
            float a, b;
            char c;
            cin >> a >> c >> b;
            switch (c)
            {
            case '+':
                cout << a + b << endl;
                break;

            case '-':
                cout << a - b << endl;
                break;

            case '*':
                cout << a * b << endl;
                break;

            case '/':
                cout << a / b << endl;
                break;

            case '^':
                cout << pow(a, b) << endl;
                break;

            default:
                cout << "enter valid input" << endl;
                break;
            }
        }
    }

    namespace matrix
    {
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

                    oper::clearScreen();
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

                    oper::clearScreen();
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

                    oper::clearScreen();
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

    }

    namespace Nbase
    {

    }

    int menu()
    {
        cout << "1.Arithmatic\t2.Matrix\n3.BASE-N\t4.Exponential\n5.Trignometric\t6.Equation Solving\n7.Polar and rectangular\t8.setting\n9.exit\n";
        int i;
        cin >> i;
        return i;
    }

    // *core of calculator*
    void calc(int i, vector<bool> &setting)
    {
        switch (i)
        {
        case 1:
            oper::arithmatic::arithmatics();
            break;
        case 2:
            oper::matrix::mat();
            break;
        case 3:
            cout << "work in progress";
            break;
        case 4:
            cout << "work in progress";
            break;
        case 5:
            cout << "work in progress";
            break;
        case 6:
            cout << "work in progress";
            break;
        case 7:
            cout << "work in progress";
            break;
        case 8:

            oper::settings::do_settings(setting);
            break;
        case 9:
            //  exit
            break;
        default:
            cout << "enter valid response";
            break;
        }
    }

    void runtime_check(vector<bool> &setting)
    {
        char n;
        cout << "Continue?(y/n): ";
        cin >> n;
        if (n == 'n')
        {
            setting[0] = false;
        }
    }
}

using namespace oper;

int main()
{

    vector<bool> setting;

    oper::settings::initialize_settings(setting);

    while (setting[0])
    {
        oper::clearScreen();
        cout << "hello" << endl;
        int i = menu();
        calc(i, setting);
        oper::runtime_check(setting);
    }

    return 0;
}
#include <bits/stdc++.h>
#include <windows.h>
#include "modules\inline.h"
#include "modules\nBaseConverter_v1_5.c"
#include "modules\matrixModule.cpp"
using namespace std;
namespace oper
{
    void clearScreen()
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("@cls||clear");
        #endif
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
            arith();
        }
    }

    namespace matrix
    {
        void launchMatrix(){
            mat();
        }
    }

    namespace Nbase
    {
        void nBaseLaunch(){
             nBasemain();
        }
       
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
            oper::matrix::launchMatrix();
            break;
        case 3:
            oper::Nbase::nBaseLaunch();
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
            setting[0]=false;
            cout<<"Program EXIT";
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
        if(setting[0])
        oper::runtime_check(setting);
    }

    return 0;
}
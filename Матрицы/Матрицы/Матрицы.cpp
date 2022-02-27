#include <iostream>
#include <thread>

using namespace std;

void Multy(int const n, double A[4][4], double B[4][4], double C[4][4])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void MultyThread(double A[4][4], double B[4][4], double C[4][4], int a, int b, int c, int d)
{
    for (int i = a; i < b; i++)
        for (int j = c; j < d; j++)
        {
            for (int k = 0; k < 4; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main()
{
    int const n = 4;
    double A[n][n] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    double B[n][n] = { {16,15,14,13}, {12,11,10,9}, {8,7,6,5}, {4,3,2,1} };
    double C[n][n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout <<"\t"<< A[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\t * \n" <<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\t" << B[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\t = \n" << endl;
    //Multy(n, A, B, C);
    thread t1(MultyThread, A, B, C, 0, 2, 0, 2);
    t1.join();
    thread t2(MultyThread, A, B, C, 0, 2, 2, 4);
    t2.join();
    thread t3(MultyThread, A, B, C, 2, 4, 0, 2);
    t3.join();
    thread t4(MultyThread, A, B, C, 2, 4, 2, 4);
    t4.join();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\t" << C[i][j] << " ";
        cout << "\n";
    }
    
}
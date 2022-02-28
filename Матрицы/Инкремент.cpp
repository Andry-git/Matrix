#include <iostream>
#include <thread>
#include <time.h>

using namespace std;
int a = 0;
void Inkr()
{
    a++;
}

int main()
{
    clock_t start, stop;
    int const n = 100000;
    thread D[n];
    start = clock();
    for (int i = 0; i < n; i++)
    {
        D[i] = thread(Inkr);
    }
    for (int i = 0; i < n; i++)
    {
        D[i].join();
    }
    stop = clock();
    cout << a << endl;
    cout << printf("Loop required %f seconds", (stop - start) / CLK_TCK) << endl;
}
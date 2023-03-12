#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#include <windows.h>
double PCFreq = 0.0;
__int64 CounterStart = 0;

int const  MAXN = 1000000;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    StartCounter();
    double arr[MAXN];
    int n = MAXN ; 
    // cout << n ;
    for (int i = 1; i <= 10; i++)
    {
        string fileName = "test" + to_string(i) + ".txt";
        ifstream fi(fileName);
        for (int i = 0; i < n; i++)
            fi >> arr[i];
        auto start = GetCounter();
        sort(arr, arr+n );
        auto end = GetCounter();
        cout << "The runtime of testcase " << i << " is: " << (double) ( end-start) << endl;
        fi.close();
    }

    return 0;
}

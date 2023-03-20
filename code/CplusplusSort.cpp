#include <bits/stdc++.h>
#include <chrono>
using namespace std;
int const  MAXN = 1000000;
double arr[MAXN + 5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = MAXN;

    for (int i = 1; i <= 10; i++)
    {
        string fileName = "test" + to_string(i) + ".txt";
        ifstream fi(fileName);
        for (int i = 0; i < n; i++)
            fi >> arr[i];
        auto start = std::chrono::high_resolution_clock::now();
        sort(arr, arr+n );
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        chrono::milliseconds d = chrono::duration_cast< chrono::milliseconds >( elapsed );
        cout << elapsed.count() << endl ; 
        fi.close();
    }

    return 0;
}

#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
int const MAXN = 1000000;
double arr[MAXN + 5];
int partition(double arr[], int low, int high)
{
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
        quickSort(arr, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        chrono::milliseconds d = chrono::duration_cast<chrono::milliseconds>(elapsed);
        cout << elapsed.count() << endl;
        fi.close();
    }

    return 0;
}

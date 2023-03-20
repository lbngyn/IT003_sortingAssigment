#include <bits/stdc++.h>
#include <chrono>
using namespace std;
const int MAXN = 1e6;
double arr[MAXN + 5];

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(double arr[], int N, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(double arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
        heapSort(arr, n);
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        chrono::milliseconds d = chrono::duration_cast< chrono::milliseconds >( elapsed );
        cout << elapsed.count() << endl ;
        fi.close();
    }

    return 0;
}

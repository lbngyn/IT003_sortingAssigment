Skip to content
Search or jump to…
Pull requests
Issues
Codespaces
Marketplace
Explore
 
@lbngyn 
lbngyn
/
IT003_sortingAssigment
Public
Cannot fork because you own this repository and are not a member of any organizations.
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
IT003_sortingAssigment/code/HeapSort.cpp
@lbngyn
lbngyn Add files via upload
Latest commit 74f65d0 38 minutes ago
 History
 1 contributor
72 lines (60 sloc)  1.58 KB

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
const int MAXN = 1e6;

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

    double arr[MAXN + 5];
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
        for ( int i=0 ; i<n ; i++ ) cout << arr[i] << " " ; 
        cout << endl; 
        fi.close();
    }

    return 0;
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
IT003_sortingAssigment/HeapSort.cpp at main · lbngyn/IT003_sortingAssigment

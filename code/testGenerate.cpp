#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const int MAXN = 1e6;

double generate()
{
    return (static_cast<double>((double)rand() + rand() / (double)RAND_MAX));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    double min_val = 0.0;
    double max_val = 1000000.0;

    for (int i = 1; i <= 8; i++) // 8 random test cases
    {
        string fileName = "test" + to_string(i) + ".txt";
        ofstream fo(fileName);
        for (int j = 0; j < MAXN; j++)
            fo <<setprecision(2) << fixed << generate() << " ";
        fo.close();
    }

    {
        string fileName = "test" + to_string(9) + ".txt";
        ofstream fo(fileName);
        for (int j = 0; j < MAXN; j++)
            fo << setprecision(2) << fixed << (min_val += (static_cast<double>(rand()) / (double)RAND_MAX)) << " ";
        fo.close();
    }

    {
        string fileName = "test" + to_string(10) + ".txt";
        ofstream fo(fileName);
        for (int j = 0; j < MAXN; j++)
            fo << setprecision(2) <<fixed << (max_val -= (static_cast<double>((double) rand()) / (double)RAND_MAX)) << " " ;
        fo.close();
    }
}

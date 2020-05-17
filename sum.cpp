#include <iostream>

using namespace std;

int main()
{
    long long n, sum;
    string s;
    cin >> n;
    sum = 0;
    for (long i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum;
}
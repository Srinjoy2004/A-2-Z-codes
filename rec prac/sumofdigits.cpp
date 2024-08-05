#include <iostream>
using namespace std;
int sumofdigits(int n)
{

    if (n == 0)
        return 0;

    int a = n % 10;

    return sumofdigits(n / 10) + a;
}
int main()
{

    int n = 545;
    cout << sumofdigits(n) << endl;
    return 0;
}
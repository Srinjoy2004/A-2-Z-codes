#include <iostream>
using namespace std;

int sum = 0;

void fun1(int n)
{
    if (n == 0)
        return;

    int rem = n % 10;
    sum = sum * 10 + rem;
    fun1(n / 10);
}

int main()
{
    fun1(1234);
    cout << sum << endl;
    return 0;
}

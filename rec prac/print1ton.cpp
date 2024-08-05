#include <iostream>
using namespace std;
void printn(int n)
{
    if (n == 0)
        return;
    printn(n - 1);
    cout << n << endl;
}
int main()
{
    printn(5);
    return 0;
}

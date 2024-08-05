#include <iostream>
using namespace std;
int prod(int n)
{
    if (n <=1)
        return 1;
    return n * prod(n - 1);
}
int main()
{
    int res = prod(5);
    cout << res << endl;
    return 0;
}
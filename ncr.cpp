//striver approach

#include <iostream>
using namespace std;

int main()
{
    int res = 1;
    int n = 7;
    int r = 2;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    cout << res;
    return 0;
}


//srinjoy approach

#include <iostream>
using namespace std;

int main()
{
    int res = 1;
    int n = 7;
    int r = 2;
    int r_copy = r;

    for (int i = n; i > n - r; i--)
    {
        res = (res * n) / r_copy;
        r_copy--;
    }
    cout << res;
    return 0;
}
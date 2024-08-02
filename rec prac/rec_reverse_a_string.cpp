#include <iostream>
using namespace std;
void solve(string s, int i)
{
    if (i >= s.length())
    {
        return;
    }
    solve(s, i + 1);
    cout << s[i] << endl;
}

int main()
{
    string s = "abcd";
    solve(s, 0);

    return 0;
}
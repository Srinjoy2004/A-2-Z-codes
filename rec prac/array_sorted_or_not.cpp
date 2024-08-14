#include <iostream>
#include <vector>
using namespace std;
int check(const vector<int> &arr, int i)
{
    if (i == arr.size() - 1)
        return 1;
    if (arr[i] < arr[i+1])
    {
        i++;
        
        check(arr, i);
    }
    else if (arr[i] > arr[i+1])
    {
        return -1;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int res = check(arr, 0);
    cout<< res;
    return 0;
}



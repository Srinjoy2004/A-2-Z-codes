#include <iostream>
#include <vector>
using namespace std;
int linearSearch(const vector<int> &arr, int i, int target)
{
    if (i == arr.size() - 1)
        return -1;
    if (arr[i] == target)
    {
        return i ;

       
    }
    else if (arr[i] != target)
    {
        i++;
        linearSearch(arr, i,target);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int res = linearSearch(arr, 0,4);
    cout << res;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number " << endl;
    cin >> n;
    int flag = 0;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            flag++;
            break;
        }
    }
    if (flag>0) cout<<"element "<<n<<" found";
    else
    cout<<"element "<<n<<" not found ";
    return 0;
}
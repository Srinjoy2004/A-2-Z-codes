#include<iostream>
using namespace std;
int reversenum(int n)
{
        if (n == 0)
        return 0;

    int a = n % 10;

    return sumofdigits(n / 10) + a;
}

int main(){
    
    return 0;
}
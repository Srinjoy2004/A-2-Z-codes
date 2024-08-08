#include <iostream>
using namespace std;
int reverseNumber(int n, int rev)
{
    if (n == 0)
        return rev;

    int rem = n % 10;
    rev = rev * 10 + rem;
    return reverseNumber(n / 10, rev);
}
bool isPalindrome(int n)
{
  
    int reversed = reverseNumber(n, 0);
 
    return (n == reversed);
}
int main()
{
    int number = 12321; 

    if (isPalindrome(number))
        cout << number << " is a palindrome." << endl;
    else
        cout << number << " is not a palindrome." << endl;

    return 0;
}

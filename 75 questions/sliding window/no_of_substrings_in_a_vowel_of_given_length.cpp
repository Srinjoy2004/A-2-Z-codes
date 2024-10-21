//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    bool is_vowel(char ch) {
        ch = std::tolower(ch); // Convert the character to lowercase
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        int l = 0;
        int r = k - 1;
        int c = 0;
        for (int i = l; i <= r; i++) {
            if (is_vowel(s[i]) == true)
                c++;
        }
        int maxi = INT_MIN;
        maxi = max(maxi, c);
        while (r <= s.size()-1) {
            if (is_vowel(s[l]) == true)
                c--;
            l++;
            r++;

            if (is_vowel(s[r]) == true)
                c++;
            maxi = max(maxi, c);
        }
        return maxi;
    }
};
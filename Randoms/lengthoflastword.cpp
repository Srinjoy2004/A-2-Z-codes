//https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int n1 = n;
        int c = 0;
        int blank = 0;
        if (s[n - 1] == ' ') {
            while (s[n1 - 1] == ' ') {
                blank++;
                n1--;
            }
        }
        for (int i = n - blank - 1; i >= 0; i--) {
            if (s[i] != ' ')
                c++;
            else
                break;
        }
        return c;
    }
};
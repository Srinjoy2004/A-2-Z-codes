//https://leetcode.com/problems/remove-k-digits/description/

class Solution {
    public:
        string removeKdigits(string num, int k) {
            string result = ""; // it will act as stack only
            int n = num.length();
            // if (k == n)
            //     return "0";
            for (int i = 0; i < n; i++) {
                while (result.length() > 0 && result.back() > num[i] && k > 0) {
                    result.pop_back();
                    k--; // basically we are poping
                }
                if (result.length() > 0 || num[i] != '0') // avoiding leading zero
                    result.push_back(num[i]);
            }
            while (result.length() > 0 && k > 0) {
                result.pop_back();
                k--;
            }
              if(result == "") {
                return "0";
            }
            return result;
        }
    };
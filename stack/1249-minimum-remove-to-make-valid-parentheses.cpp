class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string result = "";
        int c = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                c++;
                // result = result + s[i];
                result.push_back(s[i]);
            } else if (s[i] == ')') {
                if (c > 0) {
                    c--;
                    // result = result + s[i];
                    result.push_back(s[i]);
                }
            } else
                // result = result + s[i];
                result.push_back(s[i]);
        }

        string result_final = "";

        for (int i = result.size() - 1; i >= 0; i--) {
            if (c > 0 && result[i] == '(') {
                c--;
            } else {
                // result_final = result[i] + result_final;
                result_final.push_back(result[i]);
            }
        }
        reverse(begin(result_final), end(result_final));
        return result_final;
    }
};
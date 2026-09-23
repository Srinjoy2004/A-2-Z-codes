class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i <= n - 1; i++) {
            if (s[i] != '*')
                st.push(s[i]);
            else
                st.pop();
        }
        
        int st_size = st.size();
        string res (st_size,' ') ;
        for (int i = st_size - 1; i >= 0; i--) {

            res[i] = st.top() ;
            st.pop();
        }

        return res;
    }
};
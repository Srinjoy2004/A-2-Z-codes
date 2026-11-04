//https://leetcode.com/problems/build-an-array-with-stack-operations/description/


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // ISSUE 2 FIX: Pre-allocate max possible size for result so result[k++] works
        vector<string> result(2 * n); 
        
        // ISSUE 1 FIX: Pre-allocate size n for build so build[i] works
        vector<int> build(n);
        
        stack<int> st;
        int c = 1;
        for (int i = 0; i < n; i++) {
            build[i] = c++;
        }
        
        int j = 0;
        int k = 0;
        for (int i = 0; i < build.size(); i++) {
            // Early exit condition: stop if we have matched all elements in target
            if (j >= target.size()) break;

            st.push(build[i]);
            result[k++] = "Push";
            
            if (!st.empty() && st.top() != target[j]) {
                st.pop();
                result[k++] = "Pop";
            }
            
            // STACK SAFETY FIX: Ensure stack is not empty before calling .top()
            if (!st.empty() && st.top() == target[j])
                j++;
        }
        
        // Resize result down to the actual number of operations performed (k)
        result.resize(k);
        return result;
    }
};
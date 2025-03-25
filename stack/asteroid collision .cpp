//https://leetcode.com/problems/asteroid-collision/

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> st;
            for (int i = 0; i < asteroids.size(); i++) {
                while (st.empty() == false && asteroids[i] < 0 && st.top() > 0) {
                    int sum = asteroids[i] + st.top();
                    if (sum < 0)
                        st.pop();
                    else if (sum > 0)
                        asteroids[i] = 0;
                    else {
                        st.pop();
                        asteroids[i] = 0;
                    }
                }
                if (asteroids[i] != 0) {
                    st.push(asteroids[i]);
                }
            }
    
            int s = st.size();
            int i = s - 1;
            vector<int> result(s);
            while (st.empty() == false) {
                result[i] = st.top();
                st.pop();
                i--;
            }
            return result;
        }
    };
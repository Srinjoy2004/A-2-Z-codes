//https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int c = 0;

        unordered_map<string, int> myMap;
        for (int i = 0; i < arr.size(); i++) {
            myMap[arr[i]]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (myMap[arr[i]] == 1) {
                c++;
            }
            if (c == k) {

                return arr[i];
                break;
            }
        }
        return "";
    }
};

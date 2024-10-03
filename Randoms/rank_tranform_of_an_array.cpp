//https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02

//done by own but took a lot time

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> myset;
        unordered_map<int, int> myMap;
       
        for (int i = 0; i <arr.size(); i++) {

            myset.insert(arr[i]);
        }
        

        vector<int> myVector(myset.begin(), myset.end());

        for (int i = 0; i < myVector.size(); i++) {
            myMap.insert({myVector[i], 1 + i});
        }

        for (int i = 0; i < arr.size(); i++) {
            if (myMap.find(arr[i]) != myMap.end()) {
                arr[i] = myMap[arr[i]];
            }
        }
        return arr;
    }
};

/*
set(sorts all element and stores uniques element to get a single ranks for an element who is appearing for more than one time ) -> vector (as in set we cant access an element on the basis of index we are converting it to vector) -> hashmap (to store {element,rank} and pass it to vector)

*/
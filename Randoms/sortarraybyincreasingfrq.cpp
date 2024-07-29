//https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (const auto& entry : freqMap) {
            minHeap.push({entry.second, -entry.first});
        }

        vector<int> result;

        while (!minHeap.empty()) {
            int freq = minHeap.top().first;
            int num = -minHeap.top().second;
            minHeap.pop();
            for (int i = 0; i < freq; ++i) {
                result.push_back(num);
            }
        }

        return result;
    }
};

//method 2 using lambda func

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return mpp[a] != mpp[b] ? mpp[a] < mpp[b] : a > b;
        });
        return nums;
    }
};
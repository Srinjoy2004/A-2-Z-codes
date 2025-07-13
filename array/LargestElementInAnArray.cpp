//https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1


//bruteforce
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        return (arr[arr.size()-1]);
    }
};




//optimal
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max =arr[0];
        int n=arr.size();
        for (int i=1;i<n;i++)
        {
            if (max<arr[i]) 
               max=arr[i];
        }
        return max;
    }
};

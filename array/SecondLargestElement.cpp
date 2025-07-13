//https://www.geeksforgeeks.org/problems/second-largest3735/1

//bruteforce

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if (n < 2) return -1;
        for( int i=n-2;i>=0;i--)
        {
            if(arr[i]<arr[n-1])
            {
                return (arr[i]);
                break;
                
            }
        }
        return -1;
        

   }
};

//better

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(largest<arr[i]) largest=arr[i];
            
        }
        int slargest=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<largest && arr[i]>slargest)
            {
                slargest=arr[i];
            }
        }
        return slargest;
    }
};


//optimal

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int largest=arr[0];
        int slargest=-1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
                
            }
            
            else if(arr[i]<largest &&arr[i]>slargest){
                slargest=arr[i];
        }
        }
        return slargest;
    }
};
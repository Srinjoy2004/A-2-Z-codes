//https://www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM

bool ispossible(vector<int> &stalls,int dist,int cows)
{
    int count_cow=1,last_stall=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-last_stall>=dist)
        {
            count_cow++;
            last_stall=stalls[i];
        }

    }
    if(count_cow>=cows) 
          return true;

    else
           return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ispossible(stalls,mid,k)==true)
        {
            low=mid+1;
        }else 
        high =mid-1;
    }
    return high;

    
}
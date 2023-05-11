//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long FirstOccurence(vector<long long>arr,long long key)
    {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e)
        {
            if(arr[mid]==key)
            {   ans=mid;
                e=mid-1;
               
            }
            if(key<arr[mid])//left mai jao
            { 
                e=mid-1;
            }
            if(key>arr[mid]) //right mai jao 
            {
            s=mid+1;
            }
        mid=s+(e-s)/2;  //updating mid element
        
        }
        return ans;
        
    }
    
     long LastOccurence(vector<long long>arr,long long key)
    {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e)
        {
            if(arr[mid]==key)
            {   ans=mid;
                 s=mid+1;
               
            }
            if(key<arr[mid])//left mai jao
            { 
                e=mid-1;
            }
            if(key>arr[mid]) //right mai jao 
            {
            s=mid+1;
            }
            mid=s+(e-s)/2;  //updating mid element
        
        }
            return ans;
        
    }
    
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair<long,long>ans;
      long p1=FirstOccurence(v,x);
      long p2=LastOccurence(v,x);
      ans.first=p1;
      ans.second=p2;
      return ans;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
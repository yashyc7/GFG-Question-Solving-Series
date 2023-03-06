//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int firstOccurence(int arr[], int n, int key)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        { 
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int LastOccurence(int arr[], int n, int key)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}vector<int> find(int arr[], int n , int x )
{
   vector<int>ans;
   int first=firstOccurence(arr,n,x);
   int second=LastOccurence(arr,n,x);
   ans.push_back(first);
   ans.push_back(second);
   return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends


pair<long long, long long> getMinMax(long long arr[], int n) {
    
    pair<long long,long long>ans;
    
    long long min=arr[0];
    long long max=arr[0];
    
    
    for( int i=0;i<n;i++)  //for the small element 
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }  
    
    for( int i=0;i<n;i++)  //for the small element 
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    
    ans.first=min;
    ans.second=max;
    return ans;
    
}
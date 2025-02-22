#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i =0; i< n; i++){
        int a;
        cin >> arr[i];
    }
    int maxnum = 0;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        int len = 1;
        for(int u = 0; u<i; u++){
            if(arr[u]<arr[i]){
                dp[i] = max(dp[i], dp[u]+1);
            }
        }
        maxnum = max(dp[i], maxnum);
    }
    cout<<maxnum;
}
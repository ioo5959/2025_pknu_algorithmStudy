#include<bits/stdc++.h>
using namespace std;

int n;
long long dist[100005];
long long oil[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> dist[i];
    }
    for(int i=0; i<n; i++){
        cin >> oil[i];
    }
    // 초기화 
    long long curoil = oil[0]*dist[0];
    long long cur = oil[0];
    long long maxoil=0;
    for(int i = 1; i<n-1; i++){
        if(cur<=oil[i]){
            curoil += cur*dist[i];
            oil[i]=cur;
        }
        else if(cur>oil[i]){
            curoil += oil[i]*dist[i];
            cur = oil[i];
        }
        maxoil = max(curoil, maxoil);
    }
    cout<<maxoil;
}
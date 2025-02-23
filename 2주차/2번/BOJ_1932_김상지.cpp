#include<bits/stdc++.h>
using namespace std;

int n;
int arr[500][500];
int total[500][500];

//재귀
int func(int a, int b){
    int maxsum=0;
    if(a == n-1){
        return arr[a][b];
    }
    if(total[a][b] != -1) return total[a][b];
    
    int left = func(a+1, b);
    int right = func(a+1, b+1);
    return total[a][b] = arr[a][b] + max(left, right);
    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    //-1로 초기화 
    memset(total, -1, sizeof(total));

    cout<<func(0, 0);
}
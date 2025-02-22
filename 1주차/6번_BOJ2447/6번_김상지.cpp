#include<bits/stdc++.h>
using namespace std;
char board[2200][2200] = { };

void write(int x, int y, int n){
    for(int i =x; i<x+n; i++){
        for(int j =y; j<y+n; j++){
            board[i][j]='*';
        }
    }
    n = n/3;
    for(int i =x+n; i<x+2*n; i++){
        for(int j=y+n; j<y+2*n; j++){
            board[i][j]=' ';
        }
    }
}

void func(int x, int y, int n){
    if(n==1){
        return;
    }
    write(x, y, n);
    n = n/3;
    for(int i =0; i<3; i++){
        for(int j =0; j<3; j++){
            if(i == 1 && j == 1) continue;
            func(x+i*n, y+j*n, n);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    func(0,0,n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    
    vector<int> seqA(n);
    for (int i = 0; i<n; i++){
        seqA[i] = 0;
    }

    for( int i = 0; i<n; i++){
        cin >> seqA[i];
    }
    
    vector<int> dp(n,1); // {1,1,1,1, , ,}

    for(int i = 1; i<n; i++){ //현 위치 i 기점, 0 인덱스는 기본 저장 - 1부터 시작
        for(int j = 0; j<i; j++){
            if(seqA[j] < seqA[i]){
                dp[i] = max(dp[i], dp[j]+1); //증가 수열이 될 때에만 최장 길이 업뎃
            }

        }

    }
    
    int length = *max_element(dp.begin(), dp.end());
    cout << length;
    



    return 0;
}
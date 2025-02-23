#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(){
    int n,m;

    cin >> n >> m;
    
    vector<vector<int>> map(n, vector<int>(m));
    srand(time(0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            map[i][j] = rand() % 3;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << map[i][j] <<" ";
        }
        cout << endl;
    }

    vector<pair<int, int>> empty_position;
    vector<pair<int, int>> virus_position;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 0) empty_position.push_back({i,j});
            if(map[i][j] == 2) virus_position.push_back({i,j});
        }

    }

    vector<int> install_wall(empty_position.size(), 0);
    for (int i = 0; i<3; i++) install_wall[i] = 1;

    sort(install_wall.begin(), install_wall.end());

    



    return 0;
}

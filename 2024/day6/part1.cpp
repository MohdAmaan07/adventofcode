#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("sample.txt");
    string line;
    vector<string> v;
    while(getline(file, line)) v.push_back(line);
    int pos[2];
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            if(v[i][j] == '^'){
                pos[0] = i, pos[1] = j;
                break;
            } 
        }
    }
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int nx = pos[0], ny = pos[1];
    v[nx][ny] = 'X';
    int d = 0;
    set<pair<int,int>> vis;
    while(true){
        vis.insert({nx, ny});
        int x = dir[d][0], y = dir[d][1];
        int next_x = nx + x;
        int next_y = ny + y;
        if(next_x < 0 || next_x >= v.size() || next_y < 0 || next_y >= v[0].size()) break;
        if(v[next_x][next_y] == '#') d = (d + 1) % 4;   
        else {
            nx = next_x;
            ny = next_y;
            v[nx][ny] = 'X';
        }
    }
    cout << vis.size() << endl;
    file.close();
    return 0;
}
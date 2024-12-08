#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("sample.txt");
    string line;
    vector<string> v;
    long long int ans = 0;
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

    int h = v.size(), w = v[0].size();

    auto check = [&](int start_x, int start_y){
        int nx = start_x, ny = start_y, d = 0;
        bool vis[h * w * 4] = {false};
        while(true){
            int hash = (nx * w + ny) * 4 + d;
            if(vis[hash]) return true;
            vis[hash] = true;
            int next_x = nx + dir[d][0];
            int next_y = ny + dir[d][1];
            if(next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) return false;
            if(v[next_x][next_y] == '#') d = (d + 1) % 4;   
            else {
                nx = next_x;
                ny = next_y;
            }
        }
    };

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            if(v[i][j] == '.' && !(i == pos[0] && j == pos[1])){
                v[i][j] = '#';
                if(check(pos[0], pos[1])) ans++;
                v[i][j] = '.';
            }
        }
    }
    
    cout << ans << endl;
    file.close();
    return 0;
}
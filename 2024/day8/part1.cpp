#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("sample.txt");
    long long ans = 0;
    string line;
    vector<string> s;
    while(getline(file, line)) s.push_back(line);
    unordered_map<char, vector<pair<int,int>>> mp;
    for(int i = 0; i < s[0].size(); i++){
        for(int j = 0; j < s.size(); j++){
           if(s[i][j] != '.') mp[s[i][j]].push_back({i,j});
        }
    }

    for(auto [_, v] : mp){
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                int x1 = 2 * v[j].first - v[i].first;
                int y1 = 2 * v[j].second - v[i].second;
                int x2 = 2 * v[i].first - v[j].first;
                int y2 = 2 * v[i].second - v[j].second;
                if(x1 >= 0 && x1 < s.size() && y1 >= 0 && y1 < s[0].size()){
                    if(s[x1][y1] == '.') ans++;
                }
                if(x2 >= 0 && x2 < s.size() && y2 >= 0 && y2 < s[0].size()){
                    if(s[x2][y2] == '.') ans++;
                }
            }
        }
    }
    cout << ans << endl;
    file.close();
    return 0;
}
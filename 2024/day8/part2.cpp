#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("sample.txt");
    string line;
    vector<string> s;
    while (getline(file, line)) s.push_back(line);
    unordered_map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[0].size(); j++) {
            if (s[i][j] != '.') mp[s[i][j]].push_back({i, j});
        }
    }
    set<pair<int, int>> antinodes;
    for (auto& p : mp) {
        char c = p.first;
        auto& v = p.second;
        if (v.size() <= 1) continue;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            antinodes.insert(v[i]);
            for (int j = i + 1; j < n; j++) {
                int x1 = v[i].first, y1 = v[i].second;
                int x2 = v[j].first, y2 = v[j].second;
                int dx = x2 - x1, dy = y2 - y1;
                int gcd = __gcd(abs(dx), abs(dy));
                dx /= gcd;
                dy /= gcd;
                int x = x1, y = y1;
                while (true) {
                    x += dx;
                    y += dy;
                    if (x < 0 || x >= s.size() || y < 0 || y >= s[0].size()) break;
                    antinodes.insert({x, y});
                }
                x = x1;
                y = y1;
                while (true) {
                    x -= dx;
                    y -= dy;
                    if (x < 0 || x >= s.size() || y < 0 || y >= s[0].size()) break;
                    antinodes.insert({x, y});
                }
            }
        }
    }
    cout << antinodes.size() << endl;
    file.close();
    return 0;
}
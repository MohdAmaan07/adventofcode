#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s, char delim) {
    vector<int> res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        res.push_back(stoi(item));
    }
    return res;
}

bool is_inc(vector<int>& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] < s[i + 1] && (s[i + 1] - s[i]) > 0 && (s[i + 1] - s[i]) < 4) 
            continue;
        else 
            return false;
    }
    return true;
}

bool is_dec(vector<int>& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] > s[i + 1] && (s[i] - s[i + 1]) > 0 && (s[i] - s[i + 1]) < 4) 
            continue;
        else 
            return false;
    }
    return true;
}

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    string lvl;
    long long ans = 0;
    while (getline(file, lvl)) {
        vector<int> v = split(lvl, ' ');
        if (is_inc(v) || is_dec(v)) ans++;
        else{
            for (int i = 0; i < v.size(); i++) {
                vector<int> tmp = v;
                tmp.erase(tmp.begin() + i);
                if (is_inc(tmp) || is_dec(tmp)) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    file.close();
    return 0;
}

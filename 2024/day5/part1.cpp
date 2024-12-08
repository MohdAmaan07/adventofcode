#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> seq, unordered_map<int, vector<int>>& mp){
    unordered_set<int> seen;
    for (int i = 0; i < seq.size(); i++) {
        for (int j = i + 1; j < seq.size(); j++) {
            if (seen.find(seq[j]) != seen.end() || find(mp[seq[j]].begin(), mp[seq[j]].end(), seq[i]) != mp[seq[j]].end()) {
                return false;
            }
        }
        seen.insert(seq[i]);
    }
    return true;
}

int main(){
    ifstream file("sample.txt");
    long long ans = 0;
    string line;
    unordered_map<int, vector<int>> mp;
    bool flag = false;
    vector<vector<int>> s;
    while(getline(file, line)){
        if(line == "") flag = true;
        if(!flag){
            int x = stoi(line.substr(0, line.find("|"))), y = stoi(line.substr(line.find("|")+1));
            mp[x].push_back(y);
        }
        else{
            if(line == "") continue;
            vector<int> temp;
            stringstream ss(line);
            string word;
            while (!ss.eof()) {
                getline(ss, word, ',');
                temp.push_back(stoi(word));
            }
            s.push_back(temp);
        }
    }

    for (const auto seq : s) {
        bool valid = check(seq, mp);
        if(valid) ans += seq[seq.size() / 2];
    }
    
    cout << ans << endl;
    file.close();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("sample.txt");
    long long ans = 0;
    string line;
    vector<string> s;
    while(getline(file, line)) s.push_back(line);
    
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[0].size(); j++){
            if(s[i][j] == 'X' || s[i][j] == 'S'){
                if(j + 3 < s[0].size()){
                    string tmp = "";
                    for(int k = j; k < j + 4; k++) tmp += s[i][k];
                    if(tmp == "XMAS" || tmp == "SAMX") ans++;
                }
                if(i + 3 < s.size()){
                    string tmp = "";
                    for(int k = i; k < i + 4; k++) tmp += s[k][j];
                    if(tmp == "XMAS" || tmp == "SAMX") ans++;
                }
                if(i + 3 < s.size() && j + 3 < s[0].size()){
                    string tmp = "";
                    for(int k = 0; k < 4; k++) tmp += s[i + k][j + k];
                    if(tmp == "XMAS" || tmp == "SAMX") ans++;
                }
                if(i + 3 < s.size() && j - 3 >= 0){
                    string tmp = "";
                    for(int k = 0; k < 4; k++) tmp += s[i + k][j - k];
                    if(tmp == "XMAS" || tmp == "SAMX") ans++;
                }
            }
        }
    }

    cout << ans << endl;
    file.close();
    return 0;
}
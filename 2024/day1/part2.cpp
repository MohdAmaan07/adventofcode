#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    vector<ll> v1, v2;
    ifstream file("sample.txt");
    unordered_map<ll, int> mp;
    ll x, y;
    while(file >> x >> y){
        v1.push_back(x);
        v2.push_back(y);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v2.size(); i++) mp[v2[i]]++;
    int ans = 0;
    for(int i = 0; i < v1.size(); i++) ans += v1[i] * mp[v1[i]];
    cout << ans;
    file.close();
    return 0;
}
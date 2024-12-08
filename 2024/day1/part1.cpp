#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    vector<ll> v1, v2;
    ifstream file("sample.txt");
    ll x, y;
    while(file >> x >> y){
        v1.push_back(x);
        v2.push_back(y);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = 0;
    for(int i = 0; i < v1.size(); i++) ans += abs(v1[i] - v2[i]);
    cout << ans;
    file.close();
    return 0;
}
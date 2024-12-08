#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long int>& nums, long long int target, long long int curr, int i){
    if(i >= nums.size()) return curr == target;
    return (check(nums, target, curr + nums[i], i + 1)) || (check(nums, target, curr * nums[i], i + 1)) || check(nums, target, stoll(to_string(curr) + to_string(nums[i])), i + 1);
}

int main(){
    ifstream file("sample.txt");
    long long int ans = 0;
    string line;
    while(getline(file, line)){
        long long int res = stoll(line.substr(0, line.find(":")));
        string value = line.substr(line.find(":") + 1);
        vector<long long int> val;
        string num;
        stringstream ss(value);
        while(ss >> num) val.push_back(stoi(num));
        if(check(val, res, 0, 0)) ans += res;
    }

    cout << ans << endl;
    file.close();
    return 0;
}
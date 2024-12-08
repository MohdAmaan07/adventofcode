#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("sample.txt");

    string expr;
    long long ans = 0;
    regex pattern(R"(mul\(\d+,\d+\))");
    while (getline(file, expr)) {
        vector<string> v;
        sregex_iterator begin(expr.begin(), expr.end(), pattern), end;
        while (begin != end) {
            v.push_back(begin->str());
            begin++;
        }
        for(int i = 0; i < v.size(); i++) {
            string tmp = v[i];
            string a = tmp.substr(4, tmp.find(',') - 4);
            string b = tmp.substr(tmp.find(',') + 1, tmp.size() - tmp.find(',') - 2);
            ans += stoi(a) * stoi(b);
        }
    }
    cout << ans;
    file.close();
    return 0;
}

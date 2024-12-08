#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("sample.txt");

    string expr;
    long long ans = 0;
    regex pattern(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");

    bool flag = true; 
    while (getline(file, expr)) {
        sregex_iterator begin(expr.begin(), expr.end(), pattern), end;
        while (begin != end) {
            smatch match = *begin++;
            string s = match.str();

            if (s == "do()"){
                flag = true; 
                continue;
            } 
            else if (s == "don't()"){
                flag = false; 
            } 
            if (flag){ 
                int a = stoi(s.substr(4, s.find(',') - 4)); 
                int b = stoi(s.substr(s.find(',') + 1, s.size() - s.find(',') - 2)); 
                ans += a * b; 
            }
        }
    }
    cout << ans;
    file.close();
    return 0;
}

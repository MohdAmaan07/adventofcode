    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        ifstream file("sample.txt");
        long long ans = 0;
        string line;
        vector<string> s;
        while(getline(file, line)) s.push_back(line);
        
        for(int i = 0; i < s.size() - 2; i++){
            for(int j = 0; j < s[0].size() - 2; j++){
            vector<vector<char>> mat(3, vector<char>(3));
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++) mat[k][l] = s[i + k][j + l];
                }
                string tmp1 = "";
                string tmp2 = "";
                for(int k = 0; k < 3; k++){
                    tmp1 += mat[k][k];
                    tmp2 += mat[k][2 - k];
                }
                if((tmp1 == "MAS" || tmp1 == "SAM") && (tmp2 == "MAS" || tmp2 == "SAM")) ans++;
            }
        }
        
        cout << ans << endl;
        file.close();
        return 0;
    }
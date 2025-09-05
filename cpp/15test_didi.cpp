#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

const string group1 = "qwertasdfgzxcv";
const string group2 = "yuiophjklbnm";

int getCost(char a, char b) {
    if (tolower(a) == tolower(b)) return 0;
    bool inGroup1a = group1.find(tolower(a)) != string::npos;
    bool inGroup1b = group1.find(tolower(b)) != string::npos;
    if (inGroup1a && inGroup1b) return 1;
    bool inGroup2a = group2.find(tolower(a)) != string::npos;
    bool inGroup2b = group2.find(tolower(b)) != string::npos;
    if (inGroup2a && inGroup2b) return 1;
    return 2;
}

int minEditDistance(const string& source, const string& target) {
    int m = source.size();
    int n = target.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i * 3;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j * 3;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = getCost(source[i - 1], target[j - 1]);
            dp[i][j] = min({
                dp[i - 1][j] + 3,
                dp[i][j - 1] + 3,
                dp[i - 1][j - 1] + cost
            });
        }
    }
    return dp[m][n];
}

int main() {
    string input;
    getline(cin, input);
    vector<string> tokens;
    size_t start = 0;
    size_t end = input.find(' ');
    while (end != string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(' ', start);
    }
    tokens.push_back(input.substr(start));
    
    if (tokens.size() < 2) {
        return 0;
    }
    
    string target = tokens[0];
    vector<string> candidates;
    for (size_t i = 1; i < tokens.size(); i++) {
        candidates.push_back(tokens[i]);
    }
    
    vector<pair<int, int>> scores;
    for (size_t i = 0; i < candidates.size(); i++) {
        int score = minEditDistance(target, candidates[i]);
        scores.push_back({score, i});
    }
    
    stable_sort(scores.begin(), scores.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    
    int count = 0;
    for (size_t i = 0; i < scores.size() && count < 3; i++) {
        if (count > 0) cout << " ";
        cout << candidates[scores[i].second];
        count++;
    }
    cout << endl;
    
    return 0;
}
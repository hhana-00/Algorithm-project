#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//LCD with DIVIDE AND CONQURE
struct LCSResult {
    int length;
    string sequence;
};

LCSResult lcsDivideAndConquer(const string& X, const string& Y, int m, int n) {
    if (m == 0 || n == 0) {
        return { 0, "" };
    }

    if (X[m - 1] == Y[n - 1]) {
        LCSResult dcresult = lcsDivideAndConquer(X, Y, m - 1, n - 1);
        dcresult.length += 1;
        dcresult.sequence.push_back(X[m - 1]);
        return dcresult;
    }
    else {
        LCSResult lcs1 = lcsDivideAndConquer(X, Y, m, n - 1);
        LCSResult lcs2 = lcsDivideAndConquer(X, Y, m - 1, n);

        if (lcs1.length > lcs2.length) {
            return lcs1;
        }
        else {
            return lcs2;
        }
    }
}

LCSResult lcs(const string& X, const string& Y) {
    return lcsDivideAndConquer(X, Y, X.length(), Y.length());
}

//USING BRUTE FORCE
vector<string> generateSubsequences(const string& s) {
    int n = s.length();
    vector<string> subsequences;

    for (int i = 1; i < (1 << n); i++) {
        string subsequence;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subsequence += s[j];
            }
        }
        subsequences.push_back(subsequence);
    }
    return subsequences;
}

string findLCSBruteForce(const string& str1, const string& str2) {
    vector<string> subsequences1 = generateSubsequences(str1);
    vector<string> subsequences2 = generateSubsequences(str2);

    string longestCommon = "";
    for (const string& sub1 : subsequences1) {
        for (const string& sub2 : subsequences2) {
            if (sub1 == sub2 && sub1.length() > longestCommon.length()) {
                longestCommon = sub1;
            }
        }
    }
    return longestCommon;
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

//LCD USING DYNAMIC PROGRAMMING
void lcsDP(const string& first, const string& second, int& length, string& dpresult) {
    int first_length = first.length();
    int second_length = second.length();

    vector<vector<int>> dp(first_length + 1, vector<int>(second_length + 1, 0));

    for (int i = 1; i <= first_length; i++) {
        for (int j = 1; j <= second_length; j++) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string lcsDP_str = "";
    int i = first_length, j = second_length;
    while (i > 0 && j > 0) {
        if (first[i - 1] == second[j - 1]) {
            lcsDP_str += first[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                j--;
            }
            else {
                i--;
            }
        }
    }

    reverse(lcsDP_str.begin(), lcsDP_str.end());

    length = dp[first_length][second_length];
    dpresult = lcsDP_str;
}

int main() {
    // LCD with DIVIDE AND CONQURE
    string X, Y;
    cout << "Enter first string for DC: ";
    cin >> X;
    cout << "Enter second string DC: ";
    cin >> Y;

    LCSResult dcresult = lcs(X, Y);
    cout << "Length of LCS of DC: " << dcresult.length << endl;
    cout << "LCS of DC: " << dcresult.sequence << endl;

    // Brute force input
       // Brute force input
    cout << "\n=== Brute Force LCS Calculation ===" << endl;
    cout << "Please enter two strings to find their Longest Common Subsequence:" << endl;

    string str1, str2;
    cout << "\nEnter first string: ";
    getline(cin >> ws, str1);  

    cout << "Enter second string: ";
    getline(cin, str2);

    // Compute LCS
    string bfresult = findLCSBruteForce(str1, str2);

    // Output results
    cout << "\nResults:" << endl;
    cout << "First string: " << str1 << endl;
    cout << "Second string: " << str2 << endl;
    cout << "Longest Common Subsequence: " << bfresult << endl;
    cout << "Length of LCS: " << bfresult.length() << endl;

    // LCD USING DYNAMIC PROGRAMMING
    string first;
    string second;

    cout << "Enter your first string DP: ";
    cin >> first;
    cout << "Enter your second string DP: ";
    cin >> second;

    int length;
    string dpresult;

    lcsDP(first, second, length, dpresult);

    cout << "Length of LCS of DP: " << length << endl;
    cout << "LCS string of DP: " << dpresult << endl;

    return 0;
}
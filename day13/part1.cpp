#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenize(string s) {
    s = s.substr(1, s.length() - 2);

    vector<string> tokens;
    string token = "";

    int i = 0;

    while (i < s.length()) {
        if (s[i] == '[') { // List
            int imbalance = 1;
            int start = i;
            while (imbalance > 0) {
                i++;
                if (s[i] == '[') imbalance++;
                if (s[i] == ']') imbalance--;
            }
            token = s.substr(start, i - start + 1);
            i++;
        }
        else if (s[i] != ']') { // Integer
            while (isdigit(s[i])) {
                token += s[i];
                i++;
            }
        }
        tokens.push_back(token);
        token = "";
        i++;
    }

    return tokens;
}

bool ordered(string packetA, string packetB) {
    vector<string> tokensA = tokenize(packetA);
    vector<string> tokensB = tokenize(packetB);

    for (int i = 0; i < tokensA.size(); i++) {
        if (i >= tokensB.size()) return false;

        string A = tokensA[i];
        string B = tokensB[i];

        if (A[0] == '[' && B[0] == '[') {
            if (!ordered(A, B)) return false;
        }
        else if (A[0] == '[' && B[0] != '[') {
            B = "[" + B + "]";
            if (!ordered(A, B)) return false;
        }
        else if (A[0] != '[' && B[0] == '[') {
            A = "[" + A + "]";
            if (!ordered(A, B)) return false;
        }
        else {
            if (stoi(A) < stoi(B)) return true;
            if (stoi(A) > stoi(B)) return false;
        }
    }

    return true;
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string line;

    int index = 1;
    int sum = 0;

    while (getline(file, line)) {
        vector<string> tokens = tokenize(line);

        string packetA = line;
        getline(file, line);
        string packetB = line;
        getline(file, line);
        if (ordered(packetA, packetB)) sum += index;

        index++;
    }

    cout << sum << endl;

    return 0;
}

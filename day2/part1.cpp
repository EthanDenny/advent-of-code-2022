#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    ifstream file("input.txt");

    char ch;
    char prev_ch;
    int score = 0;

    while (file.get(ch)) {
        if (ch == 'A' || ch == 'B' || ch == 'C') {
            prev_ch = ch;
        }
        if (ch == 'X' || ch == 'Y' || ch == 'Z') {
            score += ch - 87; // X = 1, Y = 2, Z = 3
            if (prev_ch + 23 == ch) { // Draw
                score += 3;
            }
            else if (prev_ch + 24 == ch || prev_ch + 21 == ch) { // Win
                score += 6;
            }
        }
    }

    file.close();

    cout << "The final score is " << score << endl;

    return 0;
}

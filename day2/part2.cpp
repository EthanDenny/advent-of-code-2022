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
        if (ch == 'X') { // Lose
            if (prev_ch == 'A') score += 3;
            else score += prev_ch - 65;
        }
        if (ch == 'Y') { // Draw
            score += prev_ch - 64;
            score += 3;
        }
        if (ch == 'Z') { // Win
            if (prev_ch == 'C') score += 1;
            else score += prev_ch - 63;
            score += 6;
        }
    }

    file.close();

    cout << "The final score is " << score << endl;

    return 0;
}

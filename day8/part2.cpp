#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int num_of_rc = 0; // Number of rows and columns

int calculateScenicScore(string forest, int i) {
    int top = i - num_of_rc;
    int bottom = i + num_of_rc;
    int left = i - 1;
    int right = i + 1;

    int top_score = 0;
    while (top >= 0) {
        top_score++;
        if (forest[top] >= forest[i]) break;
        top -= num_of_rc;
    }

    int bottom_score = 0;
    while (bottom < forest.length()) {
        bottom_score++;
        if (forest[bottom] >= forest[i]) break;
        bottom += num_of_rc;
    }

    int left_score = 0;
    while (left % num_of_rc < i % num_of_rc && left >= 0) {
        left_score++;
        if (forest[left] >= forest[i]) break;
        left--;
    }

    int right_score = 0;
    while (right % num_of_rc > i % num_of_rc) {
        right_score++;
        if (forest[right] >= forest[i])  break;
        right++;
    }

    return top_score * bottom_score * left_score * right_score;
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string forest = "";

    string line;
    while (getline(file, line)) {
        forest += line;
        num_of_rc++;
    }
    file.close();

    int highest_score = 0;
    
    for (int i = 0; i < forest.length(); i++) {
        int score = calculateScenicScore(forest, i);
        if (score > highest_score) highest_score = score;
    }

    cout << highest_score << endl;

    return 0;
}

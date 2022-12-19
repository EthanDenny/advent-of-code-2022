#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_RC 99 // Number of rows and columns

string forest;
int visible_trees;
int visibility[NUM_OF_RC*NUM_OF_RC] = {}; // For debugging

void checkVisible(int pos, int* highest) {
    int n = forest[pos] - 48; // Convert from char to int
    if (n > *highest) {
        *highest = n;
        visibility[pos] = 1;
    }
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string line;
    while (getline(file, line)) {
        forest += line;
    }

    for (int i = 1; i < NUM_OF_RC - 1; i++) {
        int top = 0;
        int highest_tree_top = -1;
        while (top < NUM_OF_RC - 1) {
            checkVisible(i + top*NUM_OF_RC, &highest_tree_top);
            top++;
        }

        int bottom = NUM_OF_RC - 1;
        int highest_tree_bottom = -1;
        while (bottom > 0) {
            checkVisible(i + bottom*NUM_OF_RC, &highest_tree_bottom);
            bottom--;
        }

        int left = 0;
        int highest_tree_left = -1;
        while (left < NUM_OF_RC - 1) {
            checkVisible(i*NUM_OF_RC + left, &highest_tree_left);
            left++;
        }

        int right = NUM_OF_RC - 1;
        int highest_tree_right = -1;
        while (right > 0) {
            checkVisible(i*NUM_OF_RC + right, &highest_tree_right);
            right--;
        }
    }

    file.close();

    visible_trees = NUM_OF_RC * 4 - 4;

    for (int i = 1; i < NUM_OF_RC - 1; i++) {
        for (int j = 1; j < NUM_OF_RC - 1; j++) {
            visible_trees += visibility[i*NUM_OF_RC + j];
        }
    }

    cout << visible_trees << endl;

    return 0;
}

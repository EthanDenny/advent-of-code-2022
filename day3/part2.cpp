#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int getPriority(char c) {
    if (c > 96) {
        return c - 96; // a = 1, b = 2, ... z = 26
    }
    else {
        return c - 64 + 26; // A = 27, B = 28, ... Z = 52
    }
}

char findCommonItem(string rucksacks[3]) {
    bool firstHasItem[53] = {}; // 0 = ignored, 1-26 = a-z, 27-52 = A-Z
    bool secondHasItem[53] = {};

    for (int i = 0; i < rucksacks[0].length(); i++) {
        char item = rucksacks[0][i];
        int priority = getPriority(item);
        
        firstHasItem[priority] = true;
    }

    for (int i = 0; i < rucksacks[1].length(); i++) {
        char item = rucksacks[1][i];
        int priority = getPriority(item);
        
        secondHasItem[priority] = true;
    }

    for (int i = 0; i < rucksacks[2].length(); i++) {
        char item = rucksacks[2][i];
        int priority = getPriority(item);

        if (firstHasItem[priority] && secondHasItem[priority]) {
            return priority;
        }
    }
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string rucksacks[3];
    int prioritySum = 0;

    while (getline(file, rucksacks[0]) &&
           getline(file, rucksacks[1]) &&
           getline(file, rucksacks[2])) {
        prioritySum += findCommonItem(rucksacks);
    }

    file.close();

    cout << "The sum of the common items' priorities is " << prioritySum << "." << endl;

    return 0;
}

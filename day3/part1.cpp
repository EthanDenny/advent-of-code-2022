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

char findCommonItem(string rucksack) {
    int half = rucksack.length() / 2;
    
    string leftCompartment = rucksack.substr(0, half);
    string rightCompartment = rucksack.substr(half, half);

    bool hasItem[52] = {};

    for (int i = 0; i < half; i++) {
        char item = leftCompartment[i];
        int priority = getPriority(item);
        
        hasItem[priority] = true;
    }

    for (int i = 0; i < half; i++) {
        char item = rightCompartment[i];
        int priority = getPriority(item);
        
        if (hasItem[priority]) {
            return priority;
        }
    }
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string rucksack;
    int prioritySum = 0;

    while (getline(file, rucksack)) {
        prioritySum += findCommonItem(rucksack);
    }

    file.close();

    cout << "The sum of the common items' priorities is " << prioritySum << "." << endl;

    return 0;
}

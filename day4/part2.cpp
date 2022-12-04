#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool rangeContained(string pairs) {
    int cursor;
    int min1;
    int max1;
    int min2;
    int max2;

    cursor = pairs.find('-');
    min1 = stoi(pairs.substr(0, cursor));
    pairs = pairs.substr(cursor+1, pairs.size());

    cursor = pairs.find(',');
    max1 = stoi(pairs.substr(0, cursor));
    pairs = pairs.substr(cursor+1, pairs.size());

    cursor = pairs.find('-');
    min2 = stoi(pairs.substr(0, cursor));
    pairs = pairs.substr(cursor+1, pairs.size());

    max2 = stoi(pairs);

    return (min1 <= max2 && min2 <= max1) || (min2 <= max1 && min1 <= max2);
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string assignmentPairs;
    int sum = 0;

    while (getline(file, assignmentPairs)) {
        if (rangeContained(assignmentPairs)) {
            sum += 1;
        }
    }

    file.close();

    cout << sum << " assignment pairs overlap." << endl;

    return 0;
}

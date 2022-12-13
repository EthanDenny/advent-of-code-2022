#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    ifstream file("input.txt");

    int x = 1;
    int cycles = 0;
    int sum = 0;

    string line;
    while (getline(file, line)) {
        cycles++;
        if ((cycles - 20) % 40 == 0 && cycles <= 220) sum += x * cycles;
        if (line[0] == 'a') {
            cycles++;
            if ((cycles - 20) % 40 == 0 && cycles <= 220) sum += x * cycles;
            x += stoi(line.substr(5, 3));
        }
    }

    file.close();

    cout << sum << endl;

    return 0;
}

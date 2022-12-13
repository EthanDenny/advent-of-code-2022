#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void draw(int cycles, int pos) {
    if (abs(cycles % 40 - pos) <= 1) cout << '#';
    else cout << '.';
    if ((cycles + 1) % 40 == 0) cout << endl;
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    int x = 1;
    int cycles = 0;

    string line;
    while (getline(file, line)) {
        draw(cycles, x);
        cycles++;
        if (line[0] == 'a') {
            draw(cycles, x);
            cycles++;
            x += stoi(line.substr(5, 3));
        }
    }

    file.close();

    return 0;
}

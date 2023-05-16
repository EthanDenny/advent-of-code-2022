#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos {
    int x;
    int y;
};

bool operator == (pos const &a, pos const &b) {
    return (a.x == b.x && a.y == b.y);
}

vector<pos> impassable;

string getPos(string line) {
    cout << line.substr(0, line.find(','));
    cout << "  ";
    cout << line.substr(line.find(',') + 1, line.find(" ") - 1);
    cout << endl;
    return line;
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string line;

    while (getline(file, line)) {
        while (line.find('-') != string::npos) {line = getPos(line); break;}
    }

    return 0;
}

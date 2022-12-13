#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define ROPE_LENGTH 10

struct pos {
    int x = 0;
    int y = 0;
};

vector<pos> visited_positions;

void updatePos(pos* new_pos) {
    for (int j = 0; j < visited_positions.size(); j++) {
            if ((*new_pos).x == visited_positions[j].x && (*new_pos).y == visited_positions[j].y) {
                return;
        }
    }
    visited_positions.push_back(*new_pos);
}

float distance(pos a, pos b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void moveTowards(pos* head, pos* tail) {
    if (distance(*head, *tail) >= 2) {
        if ((*head).x > (*tail).x) (*tail).x++;
        if ((*head).x < (*tail).x) (*tail).x--;
        if ((*head).y > (*tail).y) (*tail).y++;
        if ((*head).y < (*tail).y) (*tail).y--;
    }
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    pos rope[ROPE_LENGTH];

    visited_positions.push_back(rope[0]);

    string line;
    while (getline(file, line)) {
        int command = line[0];
        int n = stoi(line.substr(2, 2));

        for (int i = 0; i < n; i++) {
            if (command == 'L') rope[0].x--;
            if (command == 'R') rope[0].x++;
            if (command == 'U') rope[0].y--;
            if (command == 'D') rope[0].y++;

            for (int i = 0; i < ROPE_LENGTH - 1; i++) {
                moveTowards(&rope[i], &rope[i+1]);
            }
            updatePos(&rope[ROPE_LENGTH - 1]);
        }
    }

    file.close();

    cout << visited_positions.size() << endl;

    return 0;
}

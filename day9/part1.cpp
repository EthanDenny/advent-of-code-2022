#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos {
    int x = 0;
    int y = 0;
};

vector<pos> visited_positions;

void updatePos(pos* head_pos, pos* tail_pos) {
    *tail_pos = *head_pos;

    for (int j = 0; j < visited_positions.size(); j++) {
        if ((*tail_pos).x == visited_positions[j].x && 
            (*tail_pos).y == visited_positions[j].y) {
            return;
        }
    }
    
    visited_positions.push_back(*tail_pos);
}

void process(string s, pos* head_pos, pos* tail_pos) {
    int n = stoi(s.substr(2, 2));\
    for (int i = 0; i < n; i++) {
        if (s[0] == 'L') {
            if ((*head_pos).x < (*tail_pos).x) updatePos(head_pos, tail_pos);
            (*head_pos).x -= 1;
        }
        if (s[0] == 'R') {
            if ((*head_pos).x > (*tail_pos).x) updatePos(head_pos, tail_pos);
            (*head_pos).x += 1;
        }
        if (s[0] == 'U') {
            if ((*head_pos).y < (*tail_pos).y) updatePos(head_pos, tail_pos);
            (*head_pos).y -= 1;
        }
        if (s[0] == 'D') {
            if ((*head_pos).y > (*tail_pos).y) updatePos(head_pos, tail_pos);
            (*head_pos).y += 1;
        }
    }
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    pos head_pos;
    pos tail_pos;

    visited_positions.push_back(tail_pos);

    string line;
    while (getline(file, line)) {
        process(line, &head_pos, &tail_pos);
    }

    file.close();

    cout << visited_positions.size() << endl;

    return 0;
}

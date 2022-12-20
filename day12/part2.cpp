#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int x;
    int y;
};

bool operator == (pos const &a, pos const &b) {
    return (a.x == b.x && a.y == b.y);
}

vector<vector<int>> hill;
vector<pos> visited;

int getLocation(pos position) {
    return hill[position.y][position.x];
}

bool canMove(pos from, pos to) {
    int from_height = getLocation(from);
    int to_height = getLocation(to);
    return (to_height <= from_height) || (to_height == from_height + 1);
}

bool hasVisited(pos p) {
    for (pos v : visited) {
        if (v == p) return true;
    }
    return false;
}

vector<pos> explore(pos position) {
    int hill_height = hill.size();
    int hill_width = hill[0].size();
    pos next_pos;
    vector<pos> unexplored;

    if (hasVisited(position)) return unexplored;

    if (position.y < hill_height - 1) { // Can explore up
        next_pos = position;
        next_pos.y++;
        if (canMove(position, next_pos) && !hasVisited(next_pos)) {
            unexplored.push_back(next_pos);
        }
    }
    if (position.y > 0) { // Can explore down
        next_pos = position;
        next_pos.y--;
        if (canMove(position, next_pos) && !hasVisited(next_pos)) {
            unexplored.push_back(next_pos);
        }
    }
    if (position.x > 0) { // Can explore left
        next_pos = position;
        next_pos.x--;
        if (canMove(position, next_pos) && !hasVisited(next_pos)) {
            unexplored.push_back(next_pos);
        }
    }
    if (position.x < hill_width - 1) { // Can explore right
        next_pos = position;
        next_pos.x++;
        if (canMove(position, next_pos) && !hasVisited(next_pos)) {
            unexplored.push_back(next_pos);
        }
    }

    visited.push_back(position);
    return unexplored;
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    char ch;

    vector<int> temp;
    int x = 0;
    int y = 0;

    vector<pos> starts;
    pos end;
    
    while (file.get(ch)) {
        if (ch == '\n') {
            hill.push_back(temp);
            temp.clear();

            x = 0;
            y++;
        }
        else {
            int height;

            if (ch == 'a' || ch =='S') {
                pos start;
                start.x = x; start.y = y;
                starts.push_back(start);
                height = 1;
            }
            else if (ch == 'E') {
                end.x = x; end.y = y;
                height = 27;
            }
            else {
                height = ch - 96;
            }

            temp.push_back(height);

            x++;
        }
    }

    int min_steps = INT_MAX;

    for (pos start : starts) {
        queue<pos> unexplored;
        unexplored.push(start);

        int steps = 0;
        bool found_end = false;
        while (!found_end) {
            steps++;
            queue<pos> unexplored_temp;

            if (unexplored.empty()) break;

            while (!unexplored.empty()) {
                pos explore_next = unexplored.front();
                unexplored.pop();

                for (pos p : explore(explore_next)) {
                    if (p == end) found_end = true;
                    unexplored_temp.push(p);
                }
            }

            unexplored = unexplored_temp;
        }

        if (found_end && steps < min_steps) min_steps = steps;
        visited.clear();
    }

    cout << min_steps << endl;

    return 0;
}

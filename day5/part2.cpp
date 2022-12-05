#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<stack<char>> stacks;

void fillStack(string crates) {
    stack<char> s;
    for (int i = 0; i < crates.length(); i++) {
        s.push(crates[i]);
    }
    stacks.push_back(s);
}

void parseInstructions(string line) {
    int cursor;
    int amount;
    int from;
    int to;

    line = line.substr(5, line.length());

    cursor = line.find(' ');
    amount = stoi(line.substr(0, cursor));
    line = line.substr(cursor+6, line.length());

    cursor = line.find(' ');
    from = stoi(line.substr(0, cursor));
    line = line.substr(cursor+4, line.length());

    to = stoi(line);

    from--; // Instructions start at 1, data structures start at 0
    to--;

    stack<char> temp_stack;

    for (int i = 0; i < amount; i++) {
        char temp = stacks[from].top();
        stacks[from].pop();
        temp_stack.push(temp);
    }

    for (int i = 0; i < amount; i++) {
        char temp = temp_stack.top();
        temp_stack.pop();
        stacks[to].push(temp);
    }
}

int main(int argc, char** argv) {
    fillStack("SLW");
    fillStack("JTNQ");
    fillStack("SCHFJ");
    fillStack("TRMWNGB");
    fillStack("TRLSDHQB");
    fillStack("MJBVFRHL");
    fillStack("DWRNJM");
    fillStack("BZTFHNDJ");
    fillStack("HLQNBFT");

    ifstream file("input.txt");

    string line;
    int sum = 0;

    while (getline(file, line)) {
        parseInstructions(line);
    }

    file.close();

    cout << "The crate on top of each stack is: ";
    
    for (int i = 0; i < stacks.size(); i++) {
        cout << stacks[i].top();
    }

    cout << endl;

    return 0;
}

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Operation {
    public:
        Operation() {}

        Operation(char _op) {
            op = _op;
            uses_old = true;
        }

        Operation(char _op, int _second_op) {
            op = _op;
            second_operand = _second_op;
        }
    
        int getResult(int old) {
            if (uses_old) second_operand = old;
            if (op == '+') return old + second_operand;
            else if (op == '*') return old * second_operand;
            else throw invalid_argument("Expected op to be '+' or '*'");
        }
    
    private:
        char op;
        int second_operand;
        bool uses_old = false;
};

class Monkey {
    public:
        Monkey(queue<int> _items, Operation _oper, int _divisible_by, int _true_monkey, int _false_monkey) {
            items = _items;
            oper = _oper;
            divisible_by = _divisible_by;
            true_monkey = _true_monkey;
            false_monkey = _false_monkey;
        }

        void catchItem(int item) {
            items.push(item);
        }

        int getBusiness() {
            return business;
        }

        bool hasItem() {
            return !items.empty();
        }

        void inspectItem(vector<Monkey>* monkeys) {
            int item = items.front();
            items.pop();

            int new_item = oper.getResult(item);
            new_item /= 3;

            int catcher = test(new_item);
            (*monkeys)[catcher].catchItem(new_item);

            business++;
        }

        int test(int n) {
            return (n % divisible_by == 0) ? true_monkey : false_monkey;
        }

    private:
        queue<int> items;
        Operation oper;
        int divisible_by;
        int true_monkey;
        int false_monkey;
        int business = 0;
};

string right(string s, int n) {
    return s.substr(n, s.length());
}

bool parseMonkey(ifstream* file, vector<Monkey>* monkeys) {
    queue<int> items;
    Operation oper;
    int divisible_by;
    int true_monkey;
    int false_monkey;

    string line;
    if (!getline(*file, line)) return false;

    getline(*file, line);
    string item_str = right(line, 18);
    int comma = item_str.find(',');
    while (comma != -1) {
        int item = stoi(item_str.substr(0, comma));
        items.push(item);
        item_str = right(item_str, comma+1);
        comma = item_str.find(',');
    }
    int item = stoi(item_str.substr(0, comma));
    items.push(item);

    getline(*file, line);
    if (line[25] != 'o') {
        oper = Operation(line[23], stoi(right(line, 25)));
    }
    else {
        oper = Operation(line[23]);
    }

    getline(*file, line);
    divisible_by = stoi(right(line, 21));

    getline(*file, line);
    true_monkey = stoi(right(line, 29));

    getline(*file, line);
    false_monkey = stoi(right(line, 30));

    Monkey monkey = Monkey(items, oper, divisible_by, true_monkey, false_monkey);
    (*monkeys).push_back(monkey);

    getline(*file, line);

    return true;
}

void processRound(vector<Monkey>* monkeys) {
    for (int i = 0; i < (*monkeys).size(); i++) {
        Monkey* monkey = &((*monkeys)[i]);
        while ((*monkey).hasItem()) {
            (*monkey).inspectItem(monkeys);
        }
    }
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    vector<Monkey> monkeys;

    while (parseMonkey(&file, &monkeys));
    for (int i = 0; i < 20; i++) processRound(&monkeys);

    int naughty = 0;
    int very_naughty = 0;

    for (Monkey monkey : monkeys) {
        if (monkey.getBusiness() >= very_naughty) {
            naughty = very_naughty;
            very_naughty = monkey.getBusiness();
        }
    }

    cout << naughty * very_naughty << endl;
    
    return 0;
}

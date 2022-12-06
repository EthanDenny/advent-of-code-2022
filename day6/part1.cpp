#include <fstream>
#include <iostream>

using namespace std;

bool allDifferent(char letters[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && letters[i] == letters[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char** argv) {
    ifstream file("input.txt");

    char ch;
    int i = 3;
    char letters[4] = {};
    
    file.get(letters[1]);
    file.get(letters[2]);
    file.get(letters[3]);

    while (file.get(ch)) {
        i++;
        
        letters[0] = letters[1];
        letters[1] = letters[2];
        letters[2] = letters[3];
        letters[3] = ch;

        if (allDifferent(letters)) {
            break;
        }
    }

    cout << i << endl;

    return 0;
}

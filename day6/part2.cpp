#include <fstream>
#include <iostream>

using namespace std;

bool allDifferent(char letters[14]) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
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
    int i = 13;
    char letters[14] = {};
    
    for (int j = 1; j < 14; j++) {
        file.get(letters[j]);
    }

    while (file.get(ch)) {
        i++;
        
        for (int j = 0; j < 14; j++) {
            letters[j] = letters[j+1];
        }
        letters[14] = ch;

        if (allDifferent(letters)) {
            break;
        }
    }

    cout << i << endl;

    return 0;
}

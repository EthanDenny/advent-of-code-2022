#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string line;
    int total = 0;
    int max = 0;

    while (getline(file, line)) {
        if (line != "") {
            total += stoi(line);
        }
        else {
            if (total > max) max = total;
            total = 0;
        }
    }

    file.close();

    cout << "The elf with the most calories is carrying " << max << " calories." << endl;

    return 0;
}

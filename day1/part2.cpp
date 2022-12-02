#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    ifstream file("input.txt");

    string line;
    int total = 0;
    int max1, max2, max3 = 0;

    while (getline(file, line)) {
        if (line != "") {
            total += stoi(line);
        }
        else {
            if (total > max1) {
                max3 = max2;
                max2 = max1;
                max1 = total;
            }
            else if (total > max2) {
                max3 = max2;
                max2 = total;
            }
            else if (total > max3) {
                max3 = total;
            }

            total = 0;
        }
    }

    file.close();
    
    cout << "The three elves with the most calories are collectively carrying " << (max1 + max2 + max3) << " calories." << endl;

    return 0;
}

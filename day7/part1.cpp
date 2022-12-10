#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
        
int main(int argc, char** argv) {
    ifstream file("input.txt");

    string line;
    string curr_path;

    map<string, int> directories; // path, size
    vector<string> directory_paths;
    directory_paths.push_back("/");

    while (getline(file, line)) {
        if (line[0] == '$') {
            if (line[2] == 'c') {
                if (line[5] == '/') {
                    curr_path = "/";
                }
                else if (line[5] == '.') {
                    int index = curr_path.find_last_of('/');
                    index = curr_path.substr(0, index).find_last_of('/');
                    curr_path = curr_path.substr(0, index+1);
                }
                else {
                    curr_path += line.substr(5, line.length());
                    curr_path += '/';
                    directory_paths.push_back(curr_path);
                }
            }
        }
        else if (line[0] != 'd') {
            int index = line.find(' ');
            string digits = line.substr(0, index);
            int size = stoi(digits);

            int i = 0;
            string path;

            while (i < curr_path.length()) {
                string sub_path = curr_path.substr(i, curr_path.length());
                i += sub_path.find('/') + 1;
                directories[curr_path.substr(0, i)] += size;
            }
        }
    }

    int sum = 0;
    for (string s : directory_paths) {
        int size = directories[s];
        if (size <= 100000) sum += size;
    }
    cout << sum << endl;

    return 0;
}

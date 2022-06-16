#include "functions.hpp"
#include <string>
#include <iostream>
using namespace std;

string argument_file(int argc, char* argv[]) {
    string input = "";
    for(int i = 0; i < argc; i++) {
        input = argv[i];
        if(input.find("questions.txt") == -1) continue;
        else return argv[i];
    }
    return "No such file found!";
}

void print_vec(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i != vec.size() - 1) cout << " ";
    }
}
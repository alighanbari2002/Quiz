#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Exam.hpp"
#include "functions.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Exam exam;
    string file_path = argument_file(argc, argv);
    ifstream file(file_path);
    exam.recieve_exam(file);
    exam.answering_exam();
    exam.report();
    return 0;
}

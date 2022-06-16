#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

#include <string>
#include <vector>

const std::string INPUT_NAME = "questions.txt";
const std::string HASHTAG = "#";
const std::string CORRECT_ANSWER = "correct";
const std::string WRONG_ANSWER = "wrong";
const std::string NO_ANSWER = "no_answer";
const std::string FINISH_EXAM = "finish_exam";

std::string argument_file(int argc, char* argv[]);

void print_vec(std::vector<int>);

#endif
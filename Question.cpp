#include "Question.hpp"
#include "functions.hpp"
#include <string>
using namespace std;


Question::Question() {
    my_answer_status = NO_ANSWER;
    static int num = 1;
    no = num;
    num++;
}

bool Question::is_correct() {
    return my_answer_status == CORRECT_ANSWER;
}
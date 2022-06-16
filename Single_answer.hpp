#ifndef _SINGLE_ANSWER_HPP_
#define _SINGLE_ANSWER_HPP_

#include "Question.hpp"
#include <string>
#include <fstream>

class Single_answer :public Question {
public:
    Single_answer();
    virtual void get_question_data(std::ifstream&); 
    virtual void submit_answer(std::string datas);
    virtual void check_answer();
    virtual void to_string_status();

private:
    int correct_answer;
    int my_answer;
};

#endif

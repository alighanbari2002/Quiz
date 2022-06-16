#ifndef _MULTIPLE_ANSWER_HPP_
#define _MULTIPLE_ANSWER_HPP_

#include "Question.hpp"
#include <vector>
#include <fstream>

class Multiple_answer :public Question {
public:
    Multiple_answer();
    virtual void get_question_data(std::ifstream&); 
    virtual void submit_answer(std::string datas);
    virtual void check_answer();
    virtual void to_string_status();

private:
    std::vector<int> correct_answers;
    std::vector<int> my_answers;
};

#endif

#ifndef _SHORT_ANSWER_HPP_
#define _SHORT_ANSWER_HPP_

#include "Question.hpp"
#include <fstream>
#include <string>

class Short_answer :public Question {
public:
    Short_answer();
    virtual void get_question_data(std::ifstream&); 
    virtual void submit_answer(std::string datas);
    virtual void check_answer();
    virtual void to_string_status();

private:
    std::string correct_answer;
    std::string my_answer;
};

#endif


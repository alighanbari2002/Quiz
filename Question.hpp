#ifndef _QUESTION_HPP_
#define _QUESTION_HPP_

#include <vector>
#include <string>
#include <fstream>

class Question {
public:
    Question();
    bool is_correct();
    virtual void get_question_data(std::ifstream&) = 0;
    virtual void submit_answer(std::string) = 0;
    virtual void check_answer() = 0;
    virtual void to_string_status() = 0;

protected:
    int no;
    std::string my_answer_status;
};

#endif

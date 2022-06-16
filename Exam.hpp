#ifndef _EXAM_HPP_
#define _EXAM_HPP_

#include "Question.hpp"
#include <string>
#include <vector>
#include <fstream>

class Exam {
public:
    void recieve_exam(std::ifstream&);
    void answering_exam();
    void calculate_grade();
    void report();
    
private:
    std::vector<Question*> questions;
    double grade;
};

#endif

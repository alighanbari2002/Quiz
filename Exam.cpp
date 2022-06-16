#include "Exam.hpp"
#include "functions.hpp"
#include "Question.hpp"
#include "Single_answer.hpp"
#include "Multiple_answer.hpp"
#include "Short_answer.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


enum Type_of_questions {
    single_answer, 
    multiple_answer,
    short_answer
};
static const char *enum_str[] =
        {"single_answer", "multiple_answer", "short_answer"};

void Exam::recieve_exam(ifstream& file) {
    string question_type; 
    while(getline(file, question_type)) {
        if(question_type == enum_str[single_answer]) {
            Single_answer *_single = new Single_answer();
            questions.push_back(_single);
        }
        else if(question_type == enum_str[multiple_answer]) {
            Multiple_answer *_multiple = new Multiple_answer();
            questions.push_back(_multiple);
        }
        else {
            Short_answer *_short = new Short_answer();
            questions.push_back(_short);
        }
        questions.back()->get_question_data(file);
    }
    file.close();
}

void Exam::answering_exam() {
    string tempStr; int question_no;
    while(cin >> tempStr && tempStr != FINISH_EXAM) {
        cin >> tempStr;
        question_no = stoi(tempStr) - 1;
        getline(cin, tempStr);
        tempStr = tempStr.substr(1);
        questions[question_no]->submit_answer(tempStr);
        questions[question_no]->check_answer();
        cout << endl;
    }
    this->calculate_grade();
}

void Exam::calculate_grade() {
    int all_questions_count, correct_answers_count = 0;
    all_questions_count = questions.size();
    for(int i = 0; i < all_questions_count; i++)
        if(questions[i]->is_correct())
            correct_answers_count++;
    grade = (double)100.0 * correct_answers_count / all_questions_count;
}

void Exam::report() {
    int i;
    for(i = 0; i < questions.size(); i++) {
        questions[i]->to_string_status();
        cout << endl;
    }
    double result; int temp_grade;
    temp_grade = grade * 10;
    result = (double)temp_grade / 10;
    cout << "final grade: " << result;
    if((temp_grade / 10) == (int)result)
        cout <<".0" << endl;
    for(i = 0; i < questions.size(); i++)
        delete questions[i];
}
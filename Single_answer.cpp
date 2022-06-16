#include "Single_answer.hpp"
#include "functions.hpp"
#include "Question.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;


Single_answer::Single_answer() 
    :Question()
{
}

void Single_answer::get_question_data(ifstream& file) {
    int answer_flag = 1, num_of_waste_strs = 2;
    string tempStr;
    while(getline(file, tempStr) && tempStr != HASHTAG) {
        num_of_waste_strs--;
        if(num_of_waste_strs == 0 && answer_flag == 1) {
            num_of_waste_strs = stoi(tempStr) + 1;
            answer_flag = 0;
        }
        else if(num_of_waste_strs == 0 && answer_flag == 0) {
            correct_answer = stoi(tempStr);
        }       
    }
}

void Single_answer::submit_answer(string datas) {
    istringstream iss(datas); string answer;
    while(getline(iss, answer, ' ')) {
         my_answer = stoi(answer);
    }
}

void Single_answer::check_answer() {
    if(my_answer == correct_answer)
        my_answer_status = CORRECT_ANSWER;
    else
        my_answer_status = WRONG_ANSWER;
    cout << my_answer_status << " answer.";
}

void Single_answer::to_string_status() {
    if(my_answer_status == CORRECT_ANSWER)
        cout << no << " correct";
    else if(my_answer_status == WRONG_ANSWER)
        cout << no << " wrong | correct answer: " << correct_answer << ", your answer: " << my_answer;
    else
        cout << no << " no_answer | correct answer: " << correct_answer;
}
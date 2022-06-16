#include "Multiple_answer.hpp"
#include "Question.hpp"
#include "functions.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;


Multiple_answer::Multiple_answer() 
    :Question()
{
}

void Multiple_answer::get_question_data(ifstream& file) {
    int answer_flag = 1, num_of_waste_strs = 2;
    string tempStr;
    while(getline(file, tempStr) && tempStr != HASHTAG) {
        num_of_waste_strs--;
        if(num_of_waste_strs == 0 && answer_flag == 1) {
            num_of_waste_strs = stoi(tempStr) + 1;
            answer_flag = 0;
        }
        else if(num_of_waste_strs == 0 && answer_flag == 0) {
            istringstream iss(tempStr); string num_str; int num;
            while(getline(iss, num_str, ' ')) {
                num = stoi(num_str);
                correct_answers.push_back(num);
            }
        }       
    }
}

void Multiple_answer::submit_answer(string datas) {
    istringstream iss(datas); string answer; int num;
    while(getline(iss, answer, ' ')) {
        num = stoi(answer);
        my_answers.push_back(num);
    }
}

void Multiple_answer::check_answer() {
    vector<int> correct_answers_sorted = correct_answers;
    vector<int> my_answers_sorted = my_answers;
    sort(correct_answers_sorted.begin(), correct_answers_sorted.end());
    sort(my_answers_sorted.begin(), my_answers_sorted.end());
    if(correct_answers_sorted == my_answers_sorted)
        my_answer_status = CORRECT_ANSWER;
    else
        my_answer_status = WRONG_ANSWER;
    cout << my_answer_status << " answer.";
}

void Multiple_answer::to_string_status() {
    if(my_answer_status == CORRECT_ANSWER)
        cout << no << " correct";
    else if(my_answer_status == WRONG_ANSWER) {
        cout << no << " wrong | correct answer: " ; 
        print_vec(correct_answers);
        cout << ", your answer: ";
        print_vec(my_answers);
    }
    else {
        cout << no << " no_answer | correct answer: " ; 
        print_vec(correct_answers);
    }
}
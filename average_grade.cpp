// Copyright (c) 2021 Ryan Walsh All rights reserved
//
// Created by Ryan Walsh
// Created on January 17 2021
// this program accepts marks from user and calculates the average of the marks
// after "-1" is entered

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <array>

int averaging_marks(std::list<int> marks) {
    // averaging marks
    int sum = 0;
    int average;

    for (int counter : marks) {
        sum += counter;
    }
    if (marks.size() == 0) {
        average = 0;
    } else {
        average = sum / marks.size();
    }
    return average;
}


int main() {
    // this program accepts marks from user and calculates the average of the
    // marks after "-1" is entered
    std::list<int> marks;
    std::string mark_from_user_string;
    int mark_from_user = 0;
    int averaged_mark;

    std::cout << "Please enter 1 mark at a time. Enter -1 at the end."
    << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Make sure all marks you enter are between 0 to 100."
    << std::endl;
    // input
    while (true) {
        try {
            while (mark_from_user != -1) {
                std::cout << "Enter a mark(0-100):";
                std::cin >> mark_from_user_string;
                mark_from_user = stoi(mark_from_user_string);
                if (mark_from_user < -1 || mark_from_user > 100) {
                    std::cout << "The mark must be between 0 and 100"
                    << std::endl;
                    std::cout << "" << std::endl;
                } else {
                    marks.push_back(mark_from_user);
                }
             }
            marks.pop_back();
            std::cout << "" << std::endl;
            break;
        }catch (std::invalid_argument) {
            std::cout << "Please enter a valid number." << std::endl;
            std::cout << "" << std::endl;
        }
    }

    averaged_mark = averaging_marks(marks);

    std::cout << "Your entered marks" << std::endl;
    std::cout << "" << std::endl;
    std::string fmt ="[";
    for (int counter : marks) {
        std::cout << fmt << counter << "";
        fmt = ", ";
    }
    std::cout << "]";
    std::cout << "" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "The average mark is " << averaged_mark << "%" << std::endl;
}

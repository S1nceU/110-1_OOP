#ifndef STUDENT_H
#define STUDENT_H

#include <numeric>   // std::accumulate
#include <stdexcept> // std::out_of_range, std::range_error
#include <string>
#include <vector>

#include "school_member.h"

class Student : public SchoolMember
{
public:
    Student(int const id, std::string const &name, std::string const &department = "Mechanical & Electrical Engineering") : SchoolMember(id, name, department)
    {

    }

    void addScore(double const score)
    {
        _scores.push_back(score);
    }

    double getScore(int const number_of_test /*從1開始*/) const
    {   
        int s = _scores.size();
        int there = 0;
        if(number_of_test > s){
            throw std::out_of_range("ERROR: NO_SUCH_NUMBER_OF_TEST");
        }
        else if (number_of_test <= 0){
            throw std::out_of_range("ERROR: NO_SUCH_NUMBER_OF_TEST"); 
        }
        else{
            int cou = number_of_test - 1;
            return _scores[cou];
        }
    }

    double scoreAverage() const
    {
        int s = _scores.size();
        if (s == 0){
            throw std::range_error("ERROR: NO_SCORE");
        }
        double ans = 0;
        double all = 0;
        for(int i = 0;i < s;i++){
            all += _scores[i];
        }
        ans = all / s;
        return ans;
    }
    std::string re(Student s){
        return "student";
    }
private:
    // store student's hw scores
    std::vector<double> _scores;
};

#endif

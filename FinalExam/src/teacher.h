#ifndef TEACHER_H
#define TEACHER_H

#include <algorithm> // std::find_if
#include <stdexcept> // std::domain_error, std::range_error
#include <string>
#include <vector>

#include "school_member.h"
#include "student.h"

class Teacher : public SchoolMember
{
public:
    Teacher(int const id, std::string const &name, std::string const &department = "Mechanical & Electrical Engineering") : SchoolMember(id, name, department)
    {
    }

    // Don't have to handle duplicate ids.
    void addStudent(Student const &stu)
    {
        if(this->department() != stu.department()){
            throw std::domain_error("ERROR: NOT_IN_THE_SAME_DEPARTMENT");
        }
        _studentList.push_back(stu);
    }

    Student getStudentById(int const id) const
    {
        int judge = 0;
        int who = 0;
        int s = _studentList.size();
        for(int i = 0;i < s;i++){
            if(_studentList[i].id() == id){
                judge = 1;
                who = i;
            }
        }
        if (judge == 0){
            throw std::range_error("ERROR: STUDENT_NOT_EXIST");
        }
        else{
            return _studentList[who];
        }
        // If you don't know how to use the capture clause, which is the [],
        // you can use a functor and set the id into it before passing.

    }
    std::string re(Student s){
        return "student";
    }

private:
    std::vector<Student> _studentList;
};

#endif

#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>

#include "school_member.h"

class School
{
public:
    School() = default;

    void addSchoolMember(SchoolMember *const member)
    {
        _memList.push_back(member);
    }

    template <typename Condition>
    std::vector<SchoolMember *> getSchoolMemberWithCondition(Condition cond)
    {
        std::vector<SchoolMember *> school_member_in_cond;
        for (SchoolMember *sch : _memList)
        {
            if (cond(sch))
            {
                school_member_in_cond.push_back(sch);
            }
        }
        return school_member_in_cond;
    }

private:
    std::vector<SchoolMember*> _memList;
    School(School const &o){
        for(SchoolMember* i : o._memList){
            _memList.push_back(new SchoolMember(*i));
        }
    }
    School& operator=(School const &o){
        if(this!=&o){
            for(SchoolMember* i : o._memList){
                _memList.push_back(new SchoolMember(*i));
            }
        }
        return *this;
    }
};

#endif

//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
using namespace std;

#ifndef __DOMESTIC_HPP__
#define __DOMESTIC_HPP__

#include "student.hpp"

class Domestic: public Student
{
    public:
        //default constructors
        Domestic(); //left blank intentionally
        Domestic(string set_firstname, string set_lastname, string set_province, float set_cgpa, int set_research_score);
        Domestic(string set_province, float set_cgpa, int set_research_score);

        void set_province(string prov); 
        string get_province() const;

        friend string compare_province(const Student& stu1, const Student& stu2);

    private:
        string province;
};


#endif



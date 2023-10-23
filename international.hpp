//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
using namespace std;

#ifndef __INTERNATIONAL_HPP__
#define __INTERNATIONAL_HPP__

#include "student.hpp"

class International: public Student
{
    public:
        //default constructors
        International(); //left blank intentionally
        International(string set_firstname, string set_lastname, string set_country, float set_cgpa, int set_research_score);
        International(string set_firstname, string set_lastname, string set_country, float set_cgpa, int set_research_score,
                      int set_toefl_reading, int set_toefl_listening, int set_toefl_speaking, int set_toefl_writing);
        International(string set_firstname, string set_lastname, string set_country, float set_cgpa, int set_research_score,
                      int set_toefl_reading, int set_toefl_listening, int set_toefl_speaking, int set_toefl_writing, int set_toefl_total);

        //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
        
        //set functions****************************
        void set_country(string con);
        void set_toefl_reading(int readscore);
        void set_toefl_listening(int listenscore);
        void set_toefl_speaking(int speakscore);
        void set_toefl_writing(int writescore);
        void set_toefl_total(int read, int listen, int speak, int write);

        //get functions****************************
        string get_country() const;
        int get_toefl_reading() const;
        int get_toefl_listening() const;
        int get_toefl_speaking() const;
        int get_toefl_writing() const;
        int get_toefl_total() const;

    private:
        string country;
        int toefl_reading;
        int toefl_listening;
        int toefl_speaking;            
        int toefl_writing;
        int toefl_total;
};


#endif



//header file student.hpp to declare your classes
#include <string> //you will have to use string in c++
using namespace std;

#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

    struct node
    {
        string first_name;
        string last_name;
        float cgpa;
        int research_score;
        int id; //NOT YET IMPLEMENTED
            
        //domestic
        string province;

        //international
        string country;
        int toefl_reading;
        int toefl_listening;
        int toefl_speaking;
        int toefl_writing;

        node *next;

    };
    //vector<student_info>;

    class Linkedlist 
    {
        public:
            //constructor
            Linkedlist(); //sets head and tail to null
            //Linkedlist(Linkedlist list); //setting next to null

            node *head; //renamed struct student_info to node
            node *tail;
            
            
            
    };

    class Student 
    {
        public:
            //Constructors---------------------------------------------------
            Student(); 
            Student(string set_firstname, string set_lastname, float set_cgpa, int set_research_score); //general
            Student(string set_firstname, string set_lastname, float set_cgpa, int set_research_score, int set_id);
            //Student(string set_firstname, string set_lastname, string set_province, float set_cgpa, int set_research_score); //domestic

            //set functions---------------------------------------------------
            void set_firstname(string fname);
            void set_lastname(string lnamne);
            void set_cgpa(float cgpaa);
            void set_research_score(int rscore);
            void set_id(int i); 
            //void set_province();



            //get functions---------------------------------------------------
            string get_firstname() const;
            string get_lastname() const;
            float get_cgpa() const;
            int get_research_score() const;
            int get_id() const; 

            //compares cgpa, researchscore, firstname and/or last name---------------------------------------------------
            //returns string of "=", "<", or ">"
            friend string compare_CGPA(const Student& stu1, const Student& stu2);
            friend string compare_ResearchScore(const Student& stu1, const Student& stu2);
            friend string compare_FirstName(const Student& stu1, const Student& stu2); 
            friend string compare_LastName(const Student& stu1, const Student& stu2); 

            friend bool operator <(const Student& stu1, const Student& stu2); //compares research score
            friend bool operator >(const Student& stu1, const Student& stu2); // compare rscore
            friend bool operator ==(const Student& stu1, const Student& stu2); //check if rscore is equal
            //friend bool operator ===(const Student& stu1, const Student& stu2); //checks if 

            //friend bool operator <(const Student& stu1, const Student& stu2);
            //Precondition: stu1 and stu2 have been given values.
            // this one is only for research score
            //Returns the if stu1 reserch score is less than stu2 reseach score.

        protected:
            string first_name;
            string last_name;
            float cgpa;
            int research_score;            
            int id; //NOT YET IMPLEMENTED
    };


#endif

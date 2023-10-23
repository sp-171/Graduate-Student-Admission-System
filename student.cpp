//student.cpp to implement your classes
#include "student.hpp"
//#include "domestic.hpp"

//Constructors---------------------------------------------------
Student::Student()
{
    //left empty on purpose
} 

Student::Student(string set_firstname, string set_lastname, float set_cgpa, int set_research_score)
{
    first_name = set_firstname;
    last_name = set_lastname;
    cgpa = set_cgpa;
    research_score = set_research_score;
}

Linkedlist::Linkedlist()
{
    head = nullptr;
    tail = nullptr;
}

//setting functions------------------------------------------------------------
void Student::set_firstname(string fname)
{
    first_name = fname;
    return;
}
void Student::set_lastname(string lname)
{
    last_name = lname;
    return;   
}
void Student::set_cgpa(float cgpaa)
{
    cgpa = cgpaa;
    return;
}
void Student::set_research_score(int rscore)
{
    research_score = rscore;
    return;
}
void Student::set_id(int i)
{
    id = i;
    return;
}

//getting functions------------------------------------------------------------
string Student::get_firstname() const
{
    return first_name;
}
string Student::get_lastname() const
{
    return last_name;   
}
float Student::get_cgpa() const
{
    return cgpa;
}
int Student::get_research_score() const
{
    return research_score;
}
int Student::get_id() const
{
    return id;
}


//compare functions------------------------------------------------------------
string compare_CGPA(const Student& stu1, const Student& stu2)
{ 
    if (stu1.cgpa == stu2.cgpa)
        return "="; 

    else if(stu1.cgpa > stu2.cgpa)
        return ">";

    else if(stu1.cgpa < stu2.cgpa)
        return "<"; 

    else
        return "error in compare_cgpa";
}

string compare_ResearchScore(const Student& stu1, const Student& stu2)
{ 

    if (stu1.research_score == stu2.research_score)
        return "="; 

    else if(stu1.research_score > stu2.research_score)
        return ">"; 

    else if(stu1.research_score < stu2.research_score)
        return "<"; 

    else
        return "error in compare";
}

string compare_FirstName(const Student& stu1, const Student& stu2)
{ 
    if (stu1.first_name == stu2.first_name)
        return "="; 

    else if(stu1.first_name > stu2.first_name)
        return ">"; 

    else if(stu1.first_name < stu2.first_name)
        return "<"; 
    
    else
        return "error in compare";
}

string compare_LastName(const Student& stu1, const Student& stu2)
{ 
    if (stu1.last_name == stu2.last_name)
        return "="; 

    else if(stu1.last_name > stu2.last_name)
        return ">"; 

    else if(stu1.last_name < stu2.last_name)
        return "<"; 
    
    else
        return "error in compare";
}

bool operator <(const Student& stu1, const Student& stu2)
{
    return(stu1.research_score < stu2.research_score);
}

bool operator >(const Student& stu1, const Student& stu2)
{
    return(stu1.research_score < stu2.research_score);
}

bool operator ==(const Student& stu1, const Student& stu2)
{
    return(stu1.research_score == stu2.research_score);
}

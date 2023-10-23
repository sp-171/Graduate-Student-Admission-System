#include <iostream>
#include "domestic.hpp"
using namespace std;

Domestic::Domestic()
{
    //default constructor
    //left blank on purpose
}

Domestic::Domestic(string set_firstname, string set_lastname,string set_province, float set_cgpa, int set_research_score)
{
    //default constructor

    //originally 
    //string first_name = set_firstname
    first_name = set_firstname;
    last_name = set_lastname;
    province = set_province;
    cgpa = set_cgpa;
    research_score = set_research_score;
    
}
Domestic::Domestic(string set_province, float set_cgpa, int set_research_score)
{
    province = set_province;
    cgpa = set_cgpa;
    research_score = set_research_score;
}

void Domestic::set_province(string prov)
{
    string province = prov;
    return;
}

string Domestic::get_province() const
{
    return province;
}

string compare_province(const Domestic& stu1, const Domestic& stu2)
{ 
    if (stu1.get_province() == stu2.get_province())
        return "="; 

    else if(stu1.get_province() > stu2.get_province())
        return ">"; 

    else if(stu1.get_province() < stu2.get_province())
        return "<"; 
    
    else
        return "error in compare";
}


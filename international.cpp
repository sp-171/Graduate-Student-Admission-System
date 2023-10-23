#include <iostream>
#include "international.hpp"
using namespace std;

International::International()
{
    //default constructor
    //left blank on purpose
}
International::International(string set_firstname, string set_lastname, string set_country, float set_cgpa, int set_research_score)
{
    //default constructor
    first_name = set_firstname;
    last_name = set_lastname;
    cgpa = set_cgpa;
    research_score = set_research_score;

    string country = set_country;
}

International::International(string set_firstname, string set_lastname, string set_country, float set_cgpa, int set_research_score,
                      int set_toefl_reading, int set_toefl_listening, int set_toefl_speaking, int set_toefl_writing)
{
      //default constructor
    first_name = set_firstname;
    last_name = set_lastname;
    string country = set_country;
    cgpa = set_cgpa;
    research_score = set_research_score;

    toefl_reading = set_toefl_reading;
    toefl_listening = set_toefl_listening;
    toefl_speaking = set_toefl_speaking;
    toefl_writing = set_toefl_writing;


}

International::International(string set_firstname, string set_lastname, string set_country, float set_cgpa, int set_research_score,
                      int set_toefl_reading, int set_toefl_listening, int set_toefl_speaking, int set_toefl_writing, int set_toefl_total)
{
    //default constructor
    first_name = set_firstname;
    last_name = set_lastname;
    cgpa = set_cgpa;
    research_score = set_research_score;

    string country = set_country;
    toefl_reading = set_toefl_reading;
    toefl_listening = set_toefl_listening;
    toefl_speaking = set_toefl_speaking;
    toefl_writing = set_toefl_writing;
    
}

//set functions*****************************************************
void International::set_country(string con)
{
    string country = con;
    return;
}
void International::set_toefl_reading(int readscore)
{
    int toefl_reading = readscore;
    return;
}
void International::set_toefl_listening(int listenscore)
{
    int toefl_listening = listenscore;
    return;
}
void International::set_toefl_speaking(int speakscore)
{
    int toefl_speaking = speakscore;
    return;
}
void International::set_toefl_writing(int writescore)
{
    int toefl_writing = writescore;
    return;
}
void set_toefl_total(int read, int listen, int speak, int write)
{
    int toefl_total = read + listen + speak + write;
    return;
}
//get function*****************************************************
string International::get_country() const
{
    return country;
}
int International::get_toefl_reading() const
{
    return toefl_reading;
}
int International::get_toefl_listening() const
{
    return toefl_listening;
}
int International::get_toefl_speaking() const
{
    return toefl_speaking;
}
int International::get_toefl_writing() const
{
    return toefl_writing;
}
int International::get_toefl_total() const
{
    return toefl_total;
}


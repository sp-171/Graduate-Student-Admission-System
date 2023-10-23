//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector>
#include <iomanip>

#ifndef __STU_SORT_HPP__
#define __STU_SORT_HPP__

#include "student.hpp"
#include "domestic.hpp"
#include "international.hpp"


//**************innovation**********************//

//the user is allowed to update the score and cgpa of the student of given id
node* update_score(node* list_head, int id);
node* update_cgpa(node* list_head, int id);
node* update_scoreInternational(node* list_head, int id);
node* update_cgpaInternational(node* list_head, int id);
//********************************* BOTH ***********************************************

//returns entered cgpa with one decimal place
string float_1_dec(string name);

//return inputed string with first letter capital and the rest of the letter lowercase
string case_insensitive(string name);

//PRE CONDITION: Error handling must be done beforehand
node* delete_node(node* list_head, node* new_node, int dori);
//POST CONDITION: returns new or same list head without new_node if it/they did in fact exist

//PRE CONDITION: Error handling is done in the file
Linkedlist delete_node(Linkedlist list, int dori);
//POST CONDITION: returns list with removed nodes if they/it in fact exist

//given a list the function deletes the head and tail of the list and returns same list without those nodes 
Linkedlist delete_ht(Linkedlist list);
//********************************* DOMESTIC ********************************************

//PRE CONDITION: Error handling must be done beforehand, error checking is done in the file itself
//inserts a domestic student into the linked list when given a list head and a node with student information
node* insert_domestic(node *list_head, node *new_node);
//POST CONDITION: returns new or same list head with insert node(sorted via overall sort)

//overloaded insert same as above but this one is used for testing purposes
node* insert_domestic(node* list_head, string fname, string lname, string prov, string cgpa, string rscore);

//Opens domestic-stu.txt and insert each line in to a linked list via overall sorting
Linkedlist openandstore_domestic(); 

//prints linked list from beginning to end for domestic students
void printdomestic_LL(node* list_head);

//coverts entered province to all capital letter
string prov_to_upper(string name);

//gets first and last from user
//helper to delete_domestic
//error checking checking/handling is done in the function
node *delete_getinfo_domestic();

//helper print to print menu bar for domestic student(makes table cleaner)
void print_domestic_menu();

//helper print to print domestic students
void print_searched_domestic(node *found);

//creates and return a new node with user inputed information for domestic student
node *getinfo_domestic();
//POST CONDITION: error handling has been done


//********************************* INTERNATIONAL ********************************************

//PRE CONDITION: Error handling must be done beforehand, error checking is done in the file itself
//inserts a internation student into the linked list when given a list head and a node with student information
node* insert_international(node* list_head, node* new_node);
//POST CONDITION: returns new or same list head with insert node(sorted via overall sort)

//overloaded insert same as above but this one is used for testing purposes
node* insert_international(node* list_head, string fname, string lname, string country, string cgpa, string rscore, string toefl_r, string toefl_w, string toefl_s, string toefl_l);

//Opens international-stu.txt and insert each line in to a linked list via overall sorting
Linkedlist openandstore_international();

//prints linked list for international students from beginning to end
void printinternational_LL(Linkedlist list);

//creates and return a new node with user inputed information for domestic student
node *getinfo_international();
//POST CONDITION: error checking has been done, error handling needs to be done

//creates and return a new node with user inputed information for domestic student
node *delete_getinfo_international();
//POST CONDITION: error handling has been done

//helper print to print menu bar for international student(makes table cleaner)
void print_international_menu();

//helper print to print international students
void print_searched_international(node* found);

//**************************** SEARCH FUNCTIONS ************************************************

/* DOMESTIC */

//searches by id
void Search_id_domestic(Linkedlist list,int student_id);

//searches by cgpa 
void Search_cgpa_domestic(Linkedlist list, float cgpa);
void search_cgpa_domestic_helper(node* next_stu,int count, float cgpa_value);

//searches by score
void Search_score_domestic(Linkedlist list, int score);
void search_score_domestic_helper(node* next_stu,int count, int score);

//searches by name
void Search_name_domestic(Linkedlist list, string fname, string lname);
void search_name_domestic_helper(node* next_stu, int count, string fname, string lname);


/* INTERNATIONAL */

//searches by id 
void Search_id_international(Linkedlist list, int student_id);


//searches by cgpa
void Search_cgpa_international(Linkedlist list, float cgpa);
void search_cgpa_international_helper(node* next_stu,int count, float cgpa_value);

//searches by score
void Search_score_international(Linkedlist list, int score);
void search_score_international_helper(node* next_stu,int count,int score);

//searches by name
void Search_name_international(Linkedlist list, string fname, string lname);
void search_name_international_helper(node* next_stu, int count, string fname, string lname);

/* BOTH */
node* search_id_helper(node* next_stu, int student_id);

//**************************** MERGE FUNCTIONS ************************************************

//merges two lists into one
node *mergeLists(node* first,node* second);

//prints merged List
void printMerged(node *head);


//checks
void printSearchThreshold(node* head);


// search research and cgpa threshold
void searchcgpa_threshold(node* head, string threshold);
void searchresearch_threshold(node* head, string threshold);






















//***************INTERIM********************************
//******************************************************
vector<node> openandstore_domestic_struct();
vector<node> openandstore_international_struct();

void sort_by_researchscore_domestic();
void sort_by_researchscore_international();

void sort_by_cgpa_domestic();
void sort_by_cgpa_international();

void sort_by_firstname_domestic();
void sort_by_firstname_international();

void sort_by_lastname_domestic();
void sort_by_lastname_international();

void sort_overall_domestic();
void sort_overall_international();









#endif


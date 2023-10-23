// //main.cpp, put your driver code here,
// //you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include <vector>

#include "student.hpp"
#include "domestic.hpp"
#include "international.hpp"
#include "stu_sort.hpp"
#include "toefl.hpp"

bool merged = false;

void print_menu();
void print_menu_unit();

void unitTest_merge(Linkedlist List1, Linkedlist List2, Linkedlist List3);
void unitTest_CgpaThreshold(Linkedlist list_merged);
void unitTest_ResearchThreshold(Linkedlist list_merged);

void unitTest_SearchIdDomestic(Linkedlist list_domestic);
void unitTest_SearchIdInternational(Linkedlist list_international);

void unitTest_SearchCgpaInternational(Linkedlist list_international);
void unitTest_SearchCgpaDomestic(Linkedlist list_domestic);

void unitTest_SearchResearchDomestic(Linkedlist list_domestic);
void unitTest_SearchResearchInternational(Linkedlist list_international);

void unitTest_SearchNameDomestic(Linkedlist list_domestic);
void unitTest_SearchNameInternational(Linkedlist list_international);

void unitTest_InsertDomestic(Linkedlist list_domestic);
void unitTest_InsertInternational(Linkedlist list_international);


void unitTest_DeleteInternational(Linkedlist list_international);
void unitTest_DeleteDomestic(Linkedlist list_domestic);

int main()
{
    Linkedlist list_domestic = openandstore_domestic();
    Linkedlist list_international = openandstore_international();
    Linkedlist list_merged;

    char option = '0';
    char option2 = '0';
    char option3 = '0'; // used for exit confirmations
    char option4 = '0';
    char option5 = '0';

    string input;
    node *new_node_i = new node;

    do
    {
        // digit_d = true;
        // reseting option values
        option = '0';
        option2 = '0';
        option3 = '0';
        option4 = '0';
        option5 = '0';

        print_menu();
        cin >> option; // getting user input on what they want to do

        if (option == '0') // print domestic student
        {
            try
            {
                cout << "Printing Domestic students: ";
                printdomestic_LL(list_domestic.head);
            }
            catch (std::bad_alloc &ba)
            {
                std::cerr << "bad_alloc caught: " << ba.what();
            }
        }
        else if (option == '1') // print international students
        {
            cout << "Printing International students: ";
            printinternational_LL(list_international);
        }
        else if (option == '2') // insert student
        {
            cout << "Inserting a Student." << endl;
            cout << "Would you like to insert a Domestic(D) or International(I) student?" << endl;
            cin >> option2;

            if (option2 == 'D' || option2 == 'd')
            {
                try
                {
                    new_node_i = getinfo_domestic();
                    list_domestic.head = insert_domestic(list_domestic.head, new_node_i);
                }
                catch (std::bad_alloc &ba)
                {
                    std::cerr << "bad_alloc caught: " << ba.what();
                }
            }
            else if (option2 == 'I' || option2 == 'i')
            {
                try
                {
                    node *new_node = getinfo_international();
                    list_international.head = insert_international(list_international.head, new_node);
                }
                catch (std::bad_alloc &ba)
                {
                    std::cerr << "bad_alloc caught: " << ba.what();
                }
            }
            else
            {
                cout << "Invalid entry." << endl;
            }
        }
        else if (option == '3') // delete student
        {
            cout << "Deleting a Student." << endl;
            cout << "Would you like to delete a Domestic(D) or International(I) student?" << endl;
            cin >> option2;

            if (option2 == 'D' || option2 == 'd')
            {
                // node *new_node1 = delete_getinfo_domestic();
                // list_domestic.head = delete_node(list_domestic.head, new_node1,0);
                list_domestic = delete_node(list_domestic,0);
            }
            else if (option2 == 'I' || option2 == 'i')
            {
                // node *new_node2 = delete_getinfo_international();
                // list_international.head = delete_node(list_international.head, new_node2,1);
                list_international = delete_node(list_international,1);
            }
            else
            {
                cout << "Invalid entry." << endl;
            }
        }
        else if (option == '4') // search student
        {
            cout << "Searching for a Student." << endl;
            cout << "Would you like to search for a Domestic(D) or International(I) student?" << endl;
            cin >> option2;

            if (option2 == 'D' || option2 == 'd')
            {
                cout << "Which field do want to search for?" << endl;
                cout << "Application ID (I), CGPA (C), Research Score (R), Name (N) " << endl;
                cin >> option4;
                if (option4 == 'C' || option4 == 'c')
                {

                    float search_cgpa;
                    cout << "Searching Domestic Student by CGPA." << endl;
                    cout << "Enter CGPA you would like to search for:" << endl;

                    cin >> search_cgpa;
                    Search_cgpa_domestic(list_domestic, search_cgpa);
                }
                else if (option4 == 'I' || option4 == 'i')
                {

                    int search_id;
                    cout << "Searching Domestic Student by Application ID." << endl;
                    cout << "Enter Application ID you would like to search for:" << endl;

                    cin >> search_id;
                    Search_id_domestic(list_domestic, search_id);
                }
                else if (option4 == 'R' || option4 == 'r')
                {

                    int search_score;
                    cout << "Searching Domestic Student by Research Score." << endl;
                    cout << "Enter research_score you would like to search for:" << endl;
                    cin >> search_score;
                    Search_score_domestic(list_domestic, search_score);
                }
                else if (option4 == 'N' || option4 == 'n')
                {
                    string fname, lname;
                    cout << "Searching Domestic Student by Name." << endl;
                    cout << "Enter First Name:" << endl;
                    cin >> fname;
                    cout << "Enter Last name:" << endl;
                    cin >> lname;
                    Search_name_domestic(list_domestic, fname, lname);
                }
            }
            else if (option2 == 'I' || option2 == 'i')
            {
                cout << "Which field do want to search for?" << endl;
                cout << "Application ID (I), CGPA (C), Research Score (R), Name (N) " << endl;
                cin >> option4;

                if (option4 == 'C' || option4 == 'c')
                {
                    float search_cgpa;
                    cout << "Searching International Student by CGPA." << endl;
                    cout << "Enter CGPA you would like to search for:" << endl;
                    cin >> search_cgpa;

                    Search_cgpa_international(list_international, search_cgpa);
                }
                if (option4 == 'I' || option4 == 'i')
                {
                    int search_id;
                    cout << "Searching International Student by Application ID." << endl;
                    cout << "Enter Application ID you would like to search for:" << endl;
                    cin >> search_id;

                    Search_id_international(list_international, search_id);
                }
                if (option4 == 'R' || option4 == 'r')
                {
                    int search_score;
                    cout << "Searching International Student by Research Score." << endl;
                    cout << "Enter Research Score you would like to search for:" << endl;
                    cin >> search_score;
                    Search_score_international(list_international, search_score);
                }
                else if (option4 == 'N' || option4 == 'n')
                {
                    string fname, lname;
                    cout << "Searching International Student by Name." << endl;
                    cout << "Enter First Name:" << endl;
                    cin >> fname;
                    cout << "Enter Last name:" << endl;
                    cin >> lname;
                    Search_name_international(list_international, fname, lname);
                }
            }
            else
            {
                cout << "Invalid Entry." << endl;
            }
        }
        else if (option == '5') // Merging lists
        {
            cout << "Merging Domestic and International Student List." << endl;
            cout << "Printing Result." << endl;

            if(merged == false)
            {
                list_merged.head = mergeLists(list_international.head, list_domestic.head);
                printMerged(list_merged.head);
                merged = true;
            }
            else
            {
                printMerged(list_merged.head);
            }

        }
        else if (option == '6') //searching merged list
        {
            if (merged == true)
            {
                char choice = '0';
                string threshold;

                cout << "Would you like to search for minimum cgpa(C) or research value(R)?" << endl;
                cin >> choice;
                if ((choice == 'c') || (choice == 'C'))
                {
                    cout << "What is the minimum value you are searching for?" << endl;
                    cin >> threshold;

                    searchcgpa_threshold(list_merged.head, threshold);
                }
                else if ((choice == 'r') || (choice == 'R'))
                {
                    cout << "What is the minimum value you would like to search for the research score?" << endl;
                    cin >> threshold;

                    searchresearch_threshold(list_merged.head, threshold);
                }
                else
                {
                    cout << "Invalid Entry";
                }
            }
            else
            {
                cout << "Cannot Search merged list. List has not been merged." << endl;
            }
        }
        else if (option == '7') // delete head and tail
        {
            cout << "Deleting head and tail." << endl;
            cout << "Would you like to delete from the Domestic(D) or International(I) list?" << endl;
            cin >> option2;

            if (option2 == 'D' || option2 == 'd')
            {
                list_domestic = delete_ht(list_domestic);
                cout << "Head and tail has been deleted from the domestic list." << endl;
            }
            else if (option2 == 'I' || option2 == 'i')
            {
                list_international = delete_ht(list_international);
                cout << "Head and tail has been deleted from the international list." << endl;
            }
            else
            {
                cout << "Invalid Entry. Try again." << endl;
            }
        }
        else if (option == '8')
        {
            option5 = '0';
            char option6 = '0';

            print_menu_unit();
            cin >> option5;
            if ((option5 == 'a') || (option5 == 'A'))
            {
                unitTest_merge(list_international,list_domestic,list_merged); //merge
            }
            else if ((option5 == 'b') || (option5 == 'B'))
            {
                unitTest_CgpaThreshold(list_merged); //cgpa threshold
            }
            else if ((option5 == 'c') || (option5 == 'C')) //research threshold
            {
                unitTest_ResearchThreshold(list_merged);
            }
            else if ((option5 == 'd') || (option5 == 'd')) //searhc by application id
            {
                cout << "Would you like to test Domestic or International? " << endl;
                cin >> option6;
                
                if (option6 == 'd' || option6 == 'D')
                {
                    unitTest_SearchIdDomestic(list_domestic);
                }
                else if (option6 == 'i' || option6 == 'I')
                {
                    unitTest_SearchIdInternational(list_international);
                }
                else
                {
                    cout << " Invalid entry." << endl;
                }
            }
            else if ((option5 == 'e') || (option5 == 'E')) //serach by cgpa
            {
                cout << "Would you like to test Domestic or International? " << endl;
                cin >> option6;
                if (option6 == 'd' || option6 == 'D')
                {
                    unitTest_SearchCgpaDomestic(list_domestic);
                }
                else if (option6 == 'i' || option6 == 'I')
                {
                    unitTest_SearchCgpaInternational(list_international);
                }
                else
                {
                    cout << " Invalid entry." << endl;
                }
            }
            else if ((option5 == 'f') || (option5 == 'F')) //searhc by rscore
            {
                cout << "Would you like to test Domestic or International? " << endl;
                cin >> option6;
                if (option6 == 'd' || option6 == 'D')
                {
                    unitTest_SearchResearchDomestic(list_domestic);
                }
                else if (option6 == 'i' || option6 == 'I')
                {
                    unitTest_SearchResearchDomestic(list_international);
                }
                else
                {
                    cout << " Invalid entry." << endl;
                }
            }
            else if ((option5 == 'g') || (option5 == 'G')) //searhc by first and last name
            {
                cout << "Would you like to test Domestic or International? " << endl;
                cin >> option6;
                if (option6 == 'd' || option6 == 'D')
                {
                    unitTest_SearchNameDomestic(list_domestic);
                }
                else if (option6 == 'i' || option6 == 'I')
                {
                    unitTest_SearchNameInternational(list_international);
                }
                else
                {
                    cout << " Invalid entry." << endl;
                }
            }
            else if ((option5 == 'h') || (option5 == 'H')) //searhc by first and last name
            {
                cout << "Would you like to insert Domestic or International? " << endl;
                cin >> option6;
                if (option6 == 'd' || option6 == 'D')
                {
                    unitTest_InsertDomestic(list_domestic);
                }
                else if (option6 == 'i' || option6 == 'I')
                {
                   unitTest_InsertInternational(list_international);
                }
                else
                {
                    cout << " Invalid entry." << endl;
                }
            }
            else
            {
                cout << "Invalid Entry." << endl;
            }
        }

        else if(option == '9')
        {
            char opt = '0';
            char field= '0';
            int id;

            cout<<"Update cgpa(C) or research score(R)";
            cin>>field;

            cout<<"Interntaional(I) or domestic(D)?";
            cin>>opt;

            cout<<"Enter id";
            cin>>id;

            if(field == 'r' || field == 'R')
            {

                if(opt == 'd' || opt == 'D')
                {
                    list_domestic.head = update_score(list_domestic.head, id);
                }

                if(opt == 'i' || opt == 'I')
                {
                    list_international.head = update_scoreInternational(list_international.head, id);
                }

            }

            if(field == 'c' || field == 'C')
            {

                if(opt == 'd' || opt == 'D')
                {
                    list_domestic.head = update_cgpa(list_domestic.head, id);
                }

                if(opt == 'i' || opt == 'I')
                {
                    list_international.head = update_cgpaInternational(list_international.head, id);
                }

            }
            
        }
        else if ((option == 'e') || (option == 'E'))
        {
            cout << "Are you sure you want to exit the program?" << endl;
            cout << "Yes(Y) or No(N)" << endl;
            cin >> option3;

            if (option3 == 'y' || option3 == 3 == 'Y')
            {
                break;
            }
            else if (option3 == 'n' || option3 == 'N')
            {
                // do nohting and go back to menu
            }
            else
            {
                cout << "Invalid Entry. " << endl;
            }
        }
        else
        {
            cout << "Invaid Entry. Try again." << endl;
        }

    } while (option3 != 'y' || option != 'Y');

    return 0;
}

void print_menu()
{
    cout << endl;
    cout << endl;

    cout << "Please choose from one of the options below." << endl;
    cout << "0. Print List of Domestic Students. " << endl;
    cout << "1. Print List of International Students. " << endl;

    cout << "2. Insert a Student." << endl;
    cout << "3. Delete a Student." << endl;

    cout << "4. Search for a Student." << endl;
    cout << "5. Print Domestic and International Student merged list." << endl;

    cout << "6. Search Merged List." << endl;
    cout << "7. Deleting Head and Tail." << endl;

    cout << "8. Perform a unit test. " << endl;

    cout << "9. Update research score or cgpa."<<endl;

    cout << "E. Exit program." << endl;

    cout << endl;
    cout << endl;
}
void print_menu_unit(){
    cout << "Please choose one of the options below." << endl;
    cout << "A. Test Merge List." << endl;
    cout << "B. Test Cgpa Threshold." << endl;
    cout << "C. Test Research Threshold." << endl;
    cout << "D. Test Search by Application ID." << endl;
    cout << "E. Test Search by CGPA." << endl;
    cout << "F. Test Search by Research Score." << endl;
    cout << "G. Test Search by First and Last Name." << endl;
    cout << "H. Test Insert." << endl;
    cout << "I. Test Delete." << endl;

}


char ans = '0';
//merge list unit test
void unitTest_merge(Linkedlist list_international, Linkedlist list_domestic, Linkedlist list_merged){
    do{
        cout << endl << endl <<"This test will print out the merged list. " << endl;

        Linkedlist merged_list;

        char print = '0';

        cout << "Enter 'p' to print the merged list." << endl << endl;
        cin >> print;

        if (print == 'p' || print == 'P')
        {
            cout << "The results of the two linked lists are: ";
            if(merged == false)
            {
                list_merged.head = mergeLists(list_international.head, list_domestic.head);
                printMerged(list_merged.head);
                merged = true;
            }
            else
            {
                printMerged(list_merged.head);
            }

            cout << "Test Again?"
                 << "Type y for yes and n for no. " << endl;
            cin >> ans;
        }

    } while (ans == 'y' || ans == 'Y');
    
}

//threshold unit test
void unitTest_CgpaThreshold(Linkedlist list_merged){
    do{
        string threshold;

        if (merged == false)
        {
            cout << " Cannot perform unit test. Lists have not been merged." << endl;
            return;
        }

        cout << endl;

        char o = '0';

        cout << "Which option would you like to test? " << endl;
        cout <<"Search for Highest(H), Lowest(L), Average(A), Invalid(I) or Own(O) CGPA Threshold?";
        cin >> o;
        //highest cgpa
        if (o == 'h' || o == 'H')
        {
            cout << "Testing the highest Cgpa 4.3";
            searchcgpa_threshold(list_merged.head, "4.3");
        }
        //lowest cgpa
        else if (o == 'l' || o == 'L')
        {
            cout << "Testing the lower Cgpa 2.2:";
            searchcgpa_threshold(list_merged.head, "2.2");
        }
        //average cgpa
        else if (o == 'a' || o == 'A')
        {
            cout << endl;
            cout << "Testing an average Cgpa of 3.0: ";
            searchcgpa_threshold(list_merged.head, "3.0");
        }
        //invalid cgpa
        else if ((o == 'i' || o == 'I'))
        {
            cout << endl;
            cout << "Testing Invalid Cgpa: " << endl;
            searchcgpa_threshold(list_merged.head, "-3");
        }
        //own cgpa
        else if (o == 'o' || o == 'O')
        {
            cout << endl;
            cout << "Enter your own gpa to test: ";
            cin >> threshold;
            searchcgpa_threshold(list_merged.head, threshold);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << endl <<"Test Again?"
             << " Type y for yes and n for no: ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_ResearchThreshold(Linkedlist list_merged){
    string threshold;
    do
    {
        if (merged == false)
        {
            cout << " Cannot perform unit test. Lists have not been merged." << endl;
            return;
        }
        char o = '0';

        cout << "Which option would you like to test? " << endl;
        cout << "Search for Highest(H), Lowest(L), Average(A), Invalid(I) or Own(O) Research Score Threshold?";
        cin >> o;
        //highest research score
        if (o == 'h' || o == 'H')
        {
            cout << "Testing the highest Research Score 100";
            searchresearch_threshold(list_merged.head, "100");
        }
        //lowest research score
        else if (o == 'l' || o == 'L')
        {
            cout << "Testing the lower Research Score 70";
            searchresearch_threshold(list_merged.head, "70");
        }
        //average research score
        else if (o == 'a' || o == 'A')
        {
            cout << "Testing average Research Score:";
            searchresearch_threshold(list_merged.head, "80");
        }
        //invalid research score
        else if ((o == 'i' || o == 'I'))
        {
            cout << "Testing Invalid Research Score -3: " << endl;
            searchresearch_threshold(list_merged.head, "-3");
            cout << endl;
        }
        //own research score
        else if (o == 'o' || o == 'O')
        {
            cout << "Enter your own researchscore to test: ";
            cin >> threshold;
            searchresearch_threshold(list_merged.head, threshold);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << "Test Again?"
             << " Type y for yes and n for no. ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_SearchIdDomestic(Linkedlist list_domestic){
    int id;
    do{
        cout << endl;
        char o = '0';

        cout << "Which option would you like to test? " << endl;
        cout << "Search for High(H), Low(L), Average(A), Invalid(I) or Own(O) Student ID?" << endl;
        cin >> o;
        //top of list
        if (o == 'h' || o == 'H')
        {
            cout << "Testing Student near the top of list. ";
            cout << "Expected Student- Aurora Foster";
            Search_id_domestic(list_domestic, 20220095);
        }
        //bottom
        else if (o == 'l' || o == 'L')
        {
            cout << "Testing Student near the bottom of list. ";
            cout << "Expected Student- Emily Riveria";
            Search_id_domestic(list_domestic, 20220062);
        }
        //middle
        else if (o == 'a' || o == 'A')
        {
            cout << "Testing Student near the middle of list. ";
            cout << "Expected Student- Caleb Foster";
            Search_id_domestic(list_domestic, 20220046);
        }
        //non existing
        else if ((o == 'i' || o == 'I'))
        {
            cout << "Testing invalid ID: " << endl;
            Search_id_domestic(list_domestic, 20210001);
        }
        //own
        else if (o == 'o' || o == 'O')
        {
            cout << "Enter your own application id to search for: ";
            cin >> id;
            Search_id_domestic(list_domestic, id);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y'|| ans == 'Y');
}

void unitTest_SearchIdInternational(Linkedlist list_international){
    int id;
    do{
        cout << endl;
        char o = '0';

        cout << "Which option would you like to test? " << endl;
        cout << "Search for High(H), Low(L), Average(A), Invalid(I) or Own(O) Student ID?" << endl;
        cin >> o;

        //top
        if (o == 'h' || o == 'H')
        {
            cout << "Testing Student at the top of list, ";
            cout << "Expected Student- Tina Fang";
            Search_id_international(list_international, 20220121);
        }
        //bottom
        else if (o == 'l' || o == 'L')
        {
            cout << "Testing Student near bottom of list ";
            cout << "Expected Student- Mohammad Darbandi";
            Search_id_international(list_international, 20220150);
        }
        //middle
        else if (o == 'a' || o == 'A')
        {
            cout << "Testing Student near middle of list ";
            cout << "Expected Student- Eunjoo Yi";
            Search_id_international(list_international, 20220106);
        }
        //non existing
        else if ((o == 'i' || o == 'I'))
        {
            cout << "Testing Student that doesn't exist: ";
            Search_id_international(list_international, 20210001);
        }
        //own
        else if (o == 'o' || o == 'O')
        {
            cout << "Enter your own application id to search for: ";
            cin >> id;
            Search_id_international(list_international, id);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y'|| ans == 'Y');
}

void unitTest_SearchCgpaDomestic(Linkedlist list_domestic){
    float cgpa;
    do
    {
        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Search for High(H), Low(L), Average(A), Invalid(I) or Own(O) Dometic Student CGPA?" << endl;
        cin >> o;
        //high
        if (o == 'h' || o == 'H')
        {
            cout << "Testing Students with high cgpa: 4.1, ";
            Search_cgpa_domestic(list_domestic, 4.1);
        }
        //low
        else if (o == 'l' || o == 'L')
        {

            cout << "Testing Students with low cgpa: 2 ";
            Search_cgpa_domestic(list_domestic, 2);
        }
        //average
        else if (o == 'a' || o == 'A')
        {

            cout << "\nTesting Student with average cgpa: 3.1 ";
            Search_cgpa_domestic(list_domestic, 3.1);
        }
        //invalid
        else if ((o == 'i' || o == 'I'))
        {

            cout << "\nTesting with an invalid cgpa: -1 ";
            Search_cgpa_domestic(list_domestic, -1);
        }
        //own
        else if (o == 'o' || o == 'O')
        {

            cout << "\nEnter your own cgpa to search for: ";
            cin >> cgpa;
            Search_cgpa_domestic(list_domestic, cgpa);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_SearchCgpaInternational(Linkedlist list_international){
    float cgpa;
    do
    {
        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Search for High(H), Low(L), Average(A), Invalid(I) or Own(O) International Student CGPA?" << endl;
        cin >> o;
        //high
        if (o == 'h' || o == 'H')
        {
            cout << "Testing Students with high CGPA, ";
            Search_cgpa_international(list_international, 4.3);
        }
        //low
        else if (o == 'l' || o == 'L')
        {

            cout << "Testing Students with low CGPA";
            Search_cgpa_international(list_international, 2.9);
        }
        //average
        else if (o == 'a' || o == 'A')
        {

            cout << "\nTesting Student with Average CGPA. ";
            Search_cgpa_international(list_international, 3);
        }
        //invalid
        else if ((o == 'i' || o == 'I'))
        {

            cout << "\nTesting Student with invalid CGPA: ";
            Search_cgpa_international(list_international, -3);
        }
        //own
        else if (o == 'o' || o == 'O')
        {

            cout << "\nEnter your own cgpa to search for: ";
            cin >> cgpa;
            Search_cgpa_international(list_international, cgpa);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_SearchResearchDomestic(Linkedlist list_domestic)
{
    int score;
    do
    {
        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Search for High(H), Low(L), Average(A), Invalid(I) or Own(O) International Student CGPA?" << endl;
        cin >> o;
         
        //highest
        if (o == 'h' || o == 'H')
        {
            cout << "Testing Students with highest research score: 100 ";
            cout << "Expected Students- Aurora Foster, Dylan Barnes, & Elizabeth Cooper";
            Search_score_domestic(list_domestic, 100);
        }
        //lowest
        else if (o == 'l' || o == 'L')
        {
            cout << "Testing Students with low research score: 70 ";
            cout << "Expected Students - Liam Edwards, Violet Simmons, Emily Riveria";
            Search_score_domestic(list_domestic, 70);
        }
        //average
        else if (o == 'a' || o == 'A')
        {
            cout << "\nTesting Student with average reseach score: 80 ";
            Search_score_domestic(list_domestic, 80);
        }
        //invalif
        else if ((o == 'i' || o == 'I'))
        {
            cout << "\nTesting with an invalid research score: -9 ";
            Search_score_domestic(list_domestic, -9);
        }
        //user input
        else if (o == 'o' || o == 'O')
        {
            cout << "\nEnter your own research score to search for: ";
            cin >> score;
            Search_score_domestic(list_domestic, score);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_SearchResearchInternational(Linkedlist list_international)
{
    int score;
    do
    {
        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Search for High(H), Low(L), Average(A), Invalid(I) or Own(O) International Student CGPA?" << endl;
        cin >> o;
        //highest
        if (o == 'h' || o == 'H')
        {
            cout << "Testing Students with high research score: 100 ";
            cout << "Expected Student- Tina Fang";
            Search_score_international(list_international, 100);
        }
        //lowest
        else if (o == 'l' || o == 'L')
        {
            cout << "Testing Students with low research score";
            cout << "Expected Student- Chen Li & Mohammad Darbandi";
            Search_score_international(list_international, 70);
        }
        //average
        else if (o == 'a' || o == 'A')
        {
            cout << "\nTesting Student with average score: 80 ";
            Search_score_international(list_international, 80);
        }
        //invalid
        else if ((o == 'i' || o == 'I'))
        {
            cout << "\nTesting Student with invalid research score: -3 ";
            Search_score_international(list_international, -3);
        }
        //own
        else if (o == 'o' || o == 'O')
        {

            cout << "\nEnter your own research score to search for: ";
            cin >> score;
            Search_score_international(list_international, score);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_SearchNameDomestic(Linkedlist list_domestic)
{
    do
    {
        string fname;
        string lname;
        //top
        cout << "Testing Student near top of list. ";
        cout << "Expected Student - Aurora Foster";
        Search_name_domestic(list_domestic, "Aurora", "Foster");
        cout << endl;

        //bottom
        cout << "Testing Student near bottom of list. ";
        cout << "Expected Student - Emily Riveria";
        Search_name_domestic(list_domestic, "Emily", "Rivera");
        cout << endl;

        //middle
        cout << "Testing Student near the middle of the list. ";
        cout << "Expected Student - Caleb Foster";
        Search_name_domestic(list_domestic, "Caleb", "Foster");
        cout << endl;

        //invalid
        cout << "Testing Student that doesn't of exist. ";
        Search_name_domestic(list_domestic, "Jasmeen", "Brar");
        cout << endl;
 
        //user input
        cout << "Enter the first name of the student you wish to test: ";
        cin >> fname;
        cout << "Now enter the last name: ";
        cin >> lname;
        Search_name_domestic(list_domestic, fname, lname);

        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

    } while (ans == 'y' || ans == 'Y');
}

void unitTest_SearchNameInternational(Linkedlist list_international){
   do{
       string fname;
       string lname;

        //top
       cout << "Testing Student at top of list. ";
       cout << "Expected Student - Ting Fang";
       Search_name_international(list_international, "Ting", "Fang");
       cout << endl;

        //bottom
       cout << "Testing Student at bottom of list. ";
       cout << "Expected Student - Mohammad Darbandi";
       Search_name_international(list_international, "Mohammad", "Darbandi");
       cout << endl;

       //middle
       cout << "Testing Student from the middle of the list. ";
       cout << "Expected Student - Eunjoo Yi";
       Search_name_international(list_international, "Eunjoo", "Yi");
       cout << endl;


       //doesn't exist
       cout << "Testing Student that doesn't of exist. ";
       Search_name_international(list_international, "Jasmeen", "Brar");
       cout << endl;

        //first name
       cout << "\nEnter the first name of the student you wish to test: ";
       cin >> fname;
       cout << "Now enter the last name: ";
       cin >> lname;
       Search_name_international(list_international, fname, lname);

       cout << endl;
       cout << "Test Again?"
            << " Type y for yes and n for no ";
       cin >> ans;
       cout << endl;

   }while (ans == 'y'|| ans == 'Y');

}

void unitTest_InsertDomestic(Linkedlist list_domestic){
    do{
        node* node_unit = new node;

        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Insert at Top(T), Bottom(B), Middle(M), or Own(O)?" << endl;
        cin >> o;

        //top
        if (o == 't' || o == 'T')
        {
            cout << "Inserting a student near the top of the list\n";
            cout << "Inserted Student information: ShahRukh Khan BC 4.3 100." << endl;
            insert_domestic(list_domestic.head, "ShahRukh", "Khan", "BC", "4.3", "100");
            printdomestic_LL(list_domestic.head);
        }

        //bottom
        else if (o == 'b' || o == 'B')
        {
            cout << "Inserting a student near the bottom of the list\n";
            cout << "Inserted Student information: Kajol Devgn BC 0 0." << endl;
            insert_domestic(list_domestic.head, "Kajol", "Devgn", "BC", "0", "0");
            printdomestic_LL(list_domestic.head);
        }

        //middle
        else if (o == 'M' || o == 'm')
        {
            cout << "Inserting a student near middle of list\n";
            insert_domestic(list_domestic.head, "Amitabh", "Bachchan", "BC", "3.0", "86");
            cout << "Inserted Student information: Amitabh Bachan BC 3.0 86." << endl;
            printdomestic_LL(list_domestic.head);
        }

        //user input
        else if ((o == 'o' || o == 'O'))
        {
            cout << "Enter your own student to test\n";
            node_unit = getinfo_domestic();
            insert_domestic(list_domestic.head, node_unit);
            printdomestic_LL(list_domestic.head);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }

        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

   }while (ans == 'y'|| ans == 'Y');

}

void unitTest_InsertInternational(Linkedlist list_international){
    do{
        node* node_unit = new node;

        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Insert at Top(T), Bottom(B), Middle(M), Invalid(I), or Own(O)?" << endl;
        cin >> o;

        //top
        if (o == 't' || o == 'T')
        {
        cout << "Inserting a student near the top of the list";
        cout << "Student information: Taylor Swift Canada 4.33 100 25 25 25 25." << endl;
        insert_international(list_international.head, "Taylor", "Swift", "Canada", "4.33","100","25","25","25","25");
        printinternational_LL(list_international);
        }

        //bottom
        else if (o == 'b' || o == 'B')
        {
        cout << "Inserting a student near the bottom of the list";
        cout << "Student information: Selena Gomez India 0 0 0 0 0 0." << endl;
        insert_international(list_international.head, "Selena", "Gomez", "India", "0","0","25","25","25","25");
        printinternational_LL(list_international);
        }

        //middle
        else if (o == 'M' || o == 'm')
        {
        cout << "Inserting a student near middle of list";
        cout << "Student information: Justin Bieber Korea 3.1 86 21 21 27 29." << endl;
        insert_international(list_international.head, "Justin", "Bieber", "Korea", "3.1", "86", "21","21","21","21");
        printinternational_LL(list_international);
        }

        //invalid
        else if (o == 'I' || o == 'i')
        {
        cout << "Inserting invalid student.";
        cout << "Student information: Justin Bieber Turkey 3.1 86 21 21 21 21." << endl;
        insert_international(list_international.head, "Justin", "Bieber", "Turkey", "3.1", "86", "21","21","21","21");
        printinternational_LL(list_international);
        }

        //own
        else if ((o == 'o' || o == 'O'))
        {
        cout << "Enter your own student to test\n";
        node_unit = getinfo_international();
        insert_international(list_international.head, node_unit);
        printinternational_LL(list_international);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }


        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

   }while (ans == 'y'|| ans == 'Y');

}

void unitTest_DeleteInternational(Linkedlist list_international){
    do{
        node* node_unit = new node;

        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Insert at Top(T), Bottom(B), Middle(M), Invalid(I), or Own(O)?" << endl;
        cin >> o;
        //top
        if (o == 't' || o == 'T')
        {
            node_unit->first_name = "Mostafa";
            node_unit->last_name = "Lankarani";
            cout << "Delete a student near the top of the list";
            cout << "Student information: Mostafa Lankarani" << endl;
            delete_node(list_international.head, node_unit,1);
            printinternational_LL(list_international);
        }
        //bottom
        else if (o == 'b' || o == 'B')
        {
            node_unit->first_name = "Chen";
            node_unit->last_name = "Li";
            cout << "Delete a student near the bottom of the list";
            cout << "Student information: Chen Li." << endl;
            delete_node(list_international.head, node_unit,1);
            printinternational_LL(list_international);
        }
        //middle
        else if (o == 'M' || o == 'm')
        {
            node_unit->first_name = "Eunjoo";
            node_unit->last_name = "Yi";
            cout << "Delete a student near the middle of the list";
            cout << "Student information: Eunjoo Yi" << endl;
            delete_node(list_international.head, node_unit,1);
            printinternational_LL(list_international);
        }
        //invalid
        else if (o == 'I' || o == 'i')
        {
            node_unit->first_name = "Jasmeen";
            node_unit->last_name = "Brar";
            cout << "Deleting invalid student.";
            cout << "Student information: Jasmeen Brar." << endl;
            delete_node(list_international.head, node_unit,1);
            printinternational_LL(list_international);
        }
        //user input
        else if ((o == 'o' || o == 'O'))
        {
            cout << "Enter your own student to test\n";
            node_unit = getinfo_international();
            delete_node(list_international.head, node_unit,1);
            printinternational_LL(list_international);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }


        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

   }while (ans == 'y'|| ans == 'Y');

}



void unitTest_DeleteDomestic(Linkedlist list_domestic){
    do{
        node* node_unit = new node;

        char o = '0';
        cout << "Which option would you like to test? " << endl;
        cout << "Insert at Top(T), Bottom(B), Middle(M), Invalid(I), or Own(O)?" << endl;
        cin >> o;

        //top
        if (o == 't' || o == 'T')
        {
            node_unit->first_name = "Elizabeth";
            node_unit->last_name = "Cooper";
            cout << "Delete a student near the top of the list";
            cout << "Student information: Elizabeth Cooper" << endl;
            delete_node(list_domestic.head, node_unit,0);
            printdomestic_LL(list_domestic.head);
        }
        //bottom
        else if (o == 'b' || o == 'B')
        {
            node_unit->first_name = "Liam";
            node_unit->last_name = "Edwards";
            cout << "Delete a student near the bottom of the list";
            cout << "Student information: Liam Edwards." << endl;
            delete_node(list_domestic.head, node_unit,0);
            printdomestic_LL(list_domestic.head);
        }
        //middle
        else if (o == 'M' || o == 'm')
        {
            node_unit->first_name = "Caleb";
            node_unit->last_name = "Foster";
            cout << "Delete a student near the middle of the list";
            cout << "Student information: Lucus Cook" << endl;
            delete_node(list_domestic.head, node_unit,0);
            printdomestic_LL(list_domestic.head);
        }
        //non existing
        else if (o == 'I' || o == 'i')
        {
            node_unit->first_name = "Jasmeen";
            node_unit->last_name = "Brar";
            cout << "Deleting invalid student.";
            cout << "Student information: Jasmeen Brar." << endl;
            delete_node(list_domestic.head, node_unit,0);
            printdomestic_LL(list_domestic.head);
        }
        //user input
        else if ((o == 'o' || o == 'O'))
        {
            cout << "Enter your own student to test\n";
            node_unit = getinfo_international();
            delete_node(list_domestic.head, node_unit,0);
            printdomestic_LL(list_domestic.head);
        }
        else
        {
            cout << "Invalid entry." << endl;
        }


        cout << endl;
        cout << "Test Again?"
             << " Type y for yes and n for no ";
        cin >> ans;
        cout << endl;

   }while (ans == 'y'|| ans == 'Y');

}


















//******************************************************
//***************INTERIM********************************
//******************************************************
// int main()
// {
//  char option = ' ';

//      while(option != 'e')
//     {
//         print_menu(); //printing all options
//         cin >> option;  //getting user input on what they want to do

//         if (option == '0') //cgpa
//         {
//             cout << "Printing Domestic students sorted by CGPA: " <<endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_cgpa_domestic();

//             cout << "\n\n\n";
//         }
//         else if (option == '1') //research
//         {
//             cout << "Printing International students sorted by CGPA: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_cgpa_international();

//             cout << "\n\n\n";
//         }
//         else if(option == '2')
//         {
//             cout << "Printing Domestic students sorted by RESEARCH SCORE: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_researchscore_domestic();

//             cout << "\n\n\n";
//         }
//         else if(option == '3')
//         {
//             cout << "Printing International students sorted by RESEARCH SCORE: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_researchscore_international();

//             cout << "\n\n\n";

//         }
//         else if (option == '4') //first
//         {
//             cout << "Printing Domestic students sorted by FIRST NAME: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_firstname_domestic();

//             cout << "\n\n\n";
//         }
//         else if(option =='5')
//         {
//             cout << "Printing International students sorted by FIRST NAME: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_firstname_international();

//             cout << "\n\n\n";

//         }
//         else if (option == '6') //last
//         {
//             cout << "Printing Domestic students sorted by LAST NAME: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_lastname_domestic();

//             cout << "\n\n\n";
//         }
//         else if(option == '7')
//         {
//             cout << "Printing International students sorted by LAST NAME: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_by_lastname_international();

//             cout << "\n\n\n";
//         }
//         else if (option == '8') //overall domestic
//         {
//             cout << "Overall sorted Domestic students: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_overall_domestic();

//             cout << "\n\n\n";
//         }
//         else if (option == '9') //overall international
//         {
//             cout << "Overall sorted International students: " << endl;
//             cout << "---------------------------------------------------------------------" << endl;
//             sort_overall_international();

//             cout << "\n\n\n";
//         }
//         else if (option == 'e' || option == 'E') //overall international
//         {
//             cout << "Program exited." << endl;
//             break;
//         }
//         else
//         {
//             cout << "Invalid entry. Try again" << endl << endl;
//         }

//     }

//     return 0;
// }

// void print_menu()
// {
//     cout << "Please choose from one of the options below." << endl;
//     cout << "0. Sort Domestic students by CGPA. " << endl;
//     cout << "1. Sort International students by CGPA. " << endl;

//     cout << "2. Sort Domestic students by RESEARCH SCORE" << endl;
//     cout << "3. Sort International students by RESEARCH SCORE" << endl;

//     cout << "4. Sort Domestic students by FIRST NAME" << endl;
//     cout << "5. Sort International students by FIRST NAME" << endl;

//     cout << "6. Sort Domestic students by LAST NAME" << endl;
//     cout << "7. Sort International students by LAST NAME" << endl;

//     cout << "8. Overall Sorting for Domestic students." << endl;
//     cout << "9. Overall sorting for International students. " << endl;

//     cout << "e. Exit program." << endl;
// }

//***************************CODE GIVEN TO US **********************************************************************
// void print_domestic()
// {

// /*I provide example code here to help you read the input
//  *data from a file, so that you can focus on creating
//  *and manipulating classes and objects
//  */
//   //Read the domestic-stu.txt file and exit if failed
//   string line;
//   ifstream domesticFile("domestic-stu.txt");
//   if(!domesticFile.is_open()) {
//     cout << "Unable to open file domestic-stu.txt" << endl;
//     exit(1);
//   }

//   //Read the first line of domestic-stu.txt, which specifies
//   //the file format. And then print it out to the screen
//   getline(domesticFile, line);
//   cout << "File format: " << line << endl;

//   /*Keep reading the rest of the lines in domestic-stu.txt.
//    *In the example code here, I will read each data separated
//    *by a comma, and then print it out to the screen.
//    *In your lab assignment 1, you should use these read data
//    *to initialize your DomesticStudent object. Then you can
//    *use get and set functions to manipulate your object, and
//    *print the object content to the screen
//    */
//   int stu_count = 1;
//   while( getline(domesticFile, line) ) {
//     /*process each line, get each field separated by a comma.
//      *We use istringstream to handle it.
//      *Note in this example code here, we assume the file format
//      *is perfect and do NOT handle error cases. We will leave the
//      *error and exception handling of file format to Lab Assignment 4
//      */
//     istringstream ss(line);

//     string firstName, lastName, province, s_cgpa, s_researchScore;
//     float cgpa;
//     int researchScore;

//     //get firstName separated by comma
//     getline(ss, firstName, ',');

//     //get lastName separated by comma
//     getline(ss, lastName, ',');

//     //get province separated by comma
//     getline(ss, province, ',');

//     //get cpga separated by comma, and convert string to float
//     getline(ss, s_cgpa, ',');
//     cgpa = atof(s_cgpa.c_str());

//     //get researchScore separated by comma, and convert it to int
//     getline(ss, s_researchScore, ',');
//     researchScore = atoi(s_researchScore.c_str());

//     //print the student info to the screen
//     cout << "Domestic student " << stu_count << " " << firstName << " "
// 	 << lastName << " from " << province << " province has cgpa of "
// 	 << cgpa << ", and research score of " << researchScore << endl;

//     stu_count++;
//   }

//   //close your file
//   domesticFile.close();

// }

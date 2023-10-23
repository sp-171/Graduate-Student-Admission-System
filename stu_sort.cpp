//stu_sort.cpp to implement your sorting functions
#include <vector>
#include <string>

#include "stu_sort.hpp"
using namespace std;

// Global variable ID
int ID = 20220200;
int mis_spell = 1;

bool digit_d = true;
bool digit_i = true;

bool alpha_d = true;
bool alpha_i = true;

bool delete_d = true;
bool delete_i = true;
using namespace std;



//**************************innovation********************************//
node* update_score(node* list_head, int id)
{

    node* new_node = search_id_helper(list_head, id);
    node* copy_node = new node;

    if(new_node == nullptr){
        cout<<"The student does not exist."<<endl;
        return list_head;
    }

    else{
        //the student exists
        ///delete that student from the list
    
        //cout<<"Current Research score:\n";
        //cout<<new_node->research_score;

        //copying the info into the other node
        copy_node->first_name = new_node->first_name;
        copy_node->last_name = new_node->last_name;
        copy_node->cgpa = new_node->cgpa;
        copy_node->province = new_node->province;
        copy_node->id = new_node->id;

        //deleting the student
        list_head = delete_node(list_head,new_node,0);


        int update_score;
        cout<<"Enter updated score:"<<endl;
        cin>>update_score;

        //updating research score
        copy_node->research_score = update_score;

        //inserting the student with updated info
        list_head = insert_domestic(list_head,copy_node);

        cout<<"****Updated****";

        return list_head;
    }

}

node* update_cgpa(node* list_head, int id)
{

    node* new_node = search_id_helper(list_head, id);
    node* copy_node = new node;

    if(new_node == nullptr){
        cout<<"The student does not exist."<<endl;
        return list_head;
    }

    else{
        //the student exists
        ///delete that student from the list

        //cout<<"Current Cgpa:\n";
        //cout<<new_node->cgpa;
        
        //copying the node
        copy_node->first_name = new_node->first_name;
        copy_node->last_name = new_node->last_name;
        copy_node->research_score = new_node->research_score;
        copy_node->province = new_node->province;
        copy_node->id = new_node->id;

        //deleting the student with old info
        list_head = delete_node(list_head,new_node, 0);

        float update_cgpa;
        cout<<"Enter updated cgpa:"<<endl;
        cin>>update_cgpa;
        copy_node->cgpa = update_cgpa;

        //inserting the student with new updated info
        list_head = insert_domestic(list_head,copy_node);

        cout<<"****Updated****";

        return list_head;
    }

}

// international update 
node* update_scoreInternational(node* list_head, int id)
{

    node* new_node = search_id_helper(list_head, id);
    node* copy_node = new node;

    if(new_node == nullptr){
        cout<<"The student does not exist."<<endl;
        return list_head;
    }

    else{
        //the student exists
        ///delete that student from the list

        cout<<"Current Research score:\n";
        cout<<new_node->research_score;
        
        copy_node->first_name = new_node->first_name;
        copy_node->last_name = new_node->last_name;
        copy_node->cgpa = new_node->cgpa;
        copy_node->country = new_node->country;
        copy_node->id = new_node->id;
        copy_node->toefl_listening = new_node->toefl_listening;
        copy_node->toefl_reading = new_node->toefl_reading;
        copy_node->toefl_speaking = new_node->toefl_speaking;
        copy_node->toefl_writing = new_node->toefl_writing;


        list_head = delete_node(list_head,new_node,1);

        int update_score;
        cout<<"Enter updated score:"<<endl;
        cin>>update_score;
        copy_node->research_score = update_score;

        list_head = insert_international(list_head,copy_node);

        cout<<"****Updated****";

        return list_head;
    }

}

//international update
node* update_cgpaInternational(node* list_head, int id)
{

    node* new_node = search_id_helper(list_head, id);
    node* copy_node = new node;

    if(new_node == nullptr){
        cout<<"The student does not exist."<<endl;
        return list_head;
    }

    else{
        //the student exists
        ///delete that student from the list

        cout<<"Current Cgpa:\n";
        cout<<new_node->cgpa;
          
        copy_node->first_name = new_node->first_name;
        copy_node->last_name = new_node->last_name;
        copy_node->research_score = new_node->research_score;
        copy_node->country = new_node->country;
        copy_node->id = new_node->id;
        copy_node->toefl_listening = new_node->toefl_listening;
        copy_node->toefl_reading = new_node->toefl_reading;
        copy_node->toefl_speaking = new_node->toefl_speaking;
        copy_node->toefl_writing = new_node->toefl_writing;


        list_head = delete_node(list_head,new_node, 1);

        float update_cgpa;
        cout<<"Enter updated cgpa:"<<endl;
        cin>>update_cgpa;
        copy_node->cgpa = update_cgpa;

        list_head = insert_international(list_head,copy_node);

        cout<<"****Updated****";

        return list_head;
    }

}
//*********************************BOTH***********************************************

string float_1_dec(string name)
{
    int i = 3;
    // char c = name[i];
    // cout << name << endl;
    if (name[i] == '0' || name[i] == '1' || name[i] == '2' || name[i] == '3' || name[i] == '4')
    {
        //cout << "el if -3 " << endl;
        name[3] = '\0';
    }
    else if ((name[2] == '5' || name[2] == '6' || name[2] == '7' || name[2] == '8' || name[2] == '9') && (name[i] == '\0'))
    {
        //cout << "els if -2 " << endl;
        if (name[2] == '9' && name[0] != '.')
        {
            name[2] = '0';
            name[0] = name[0] + 1;
        }
        else if (name[0] == '.')
        {
            //cout << name << "dot loop" << endl;
            name[4] = name[3];
            name[3] = name[2];
            name[2] = name[1];
            name[1] = name[0];
            name[0] = '0';

            if (name[i] == '0' || name[i] == '1' || name[i] == '2' || name[i] == '3' || name[i] == '4')
            {
                name[3] = '\0';
            }
            else if ((name[2] == '5' || name[2] == '6' || name[2] == '7' || name[2] == '8' || name[2] == '9') && (name[i] == '\0'))
            {
                if (name[2] == '9')
                {
                    name[2] = '0';
                    name[0] = name[0] + 1;
                }
                else
                {
                    name[2] = name[2] + 1;
                    name[3] = '\0';
                }
            }
            else if (name[i] == '5' || name[i] == '6' || name[i] == '7' || name[i] == '8' || name[i] == '9')
            {
                //cout << name << endl;
                if (name[2] == '9')
                {
                    // cout << "its 9" << endl;
                    name[2] = '0';
                    name[0] = name[0] + 1;
                    name[3] = '\0';
                    cout << name << "1" << endl;
                }
                else
                {
                    name[2] = name[2] + 1;
                    name[3] = '\0';
                    //cout << name << "2" << endl;
                }
            }
        }
        else
        {
            name[2] = name[2] + 1;
            name[3] = '\0';
        }
    }
    else if (name[i] == '5' || name[i] == '6' || name[i] == '7' || name[i] == '8' || name[i] == '9')
    {
        //cout << "else if -1 " << endl;
        if (name[2] == '9' && name[0] != '.')
        {
            // cout << "its 9" << endl;
            name[2] = '0';
            name[0] = name[0] + 1;
            name[3] = '\0';
        }
        else if (name[0] == '.' && name[2] == '9')
        {
            cout << name << "dot loop" << endl;
            name[4] = name[3];
            name[3] = name[2];
            name[2] = name[1];
            name[1] = name[0];
            name[0] = '0';

            if (name[i] == '0' || name[i] == '1' || name[i] == '2' || name[i] == '3' || name[i] == '4')
            {
                name[3] = '\0';
            }
            else if ((name[2] == '5' || name[2] == '6' || name[2] == '7' || name[2] == '8' || name[2] == '9') && (name[i] == '\0'))
            {
                if (name[2] == '9')
                {
                    name[2] = '0';
                    name[0] = name[0] + 1;
                }
                else
                {
                    name[2] = name[2] + 1;
                    name[3] = '\0';
                }
            }
            else if (name[i] == '5' || name[i] == '6' || name[i] == '7' || name[i] == '8' || name[i] == '9')
            {
                //cout << name << endl;
                if (name[2] == '9')
                {
                    // cout << "its 9" << endl;
                    name[2] = '0';
                    name[0] = name[0] + 1;
                    name[3] = '\0';
                    //cout << name << "1" << endl;
                }
                else
                {
                    name[2] = name[2] + 1;
                    name[3] = '\0';
                    //cout << name << "2" << endl;
                }
            }
        }
        else
        {
            name[2] = name[2] + 1;
            name[3] = '\0';
        }
    }

    // cout << name << "---------"<<endl;
    //cout << name << endl;
    return name;
}

string case_insensitive(string name)
{

    int i;
    for (i = 0; i < name.size(); i++)
    {
        char c = name[i];
        if (isupper(c))
            name[i] = tolower(c);
        else
        {
            name[i] = name[i];
        }
    }
    name[0] = toupper(name[0]);

    return name;
}

node *delete_node(node *list_head, node *new_node,int dori)
{
    Linkedlist list;
    list.head = list_head;

    //dori stands for domestic or international
    //helper to print the correct menu
    //0 is domestic
    //1 is international
    if (dori == 0)
    {
        print_domestic_menu();
    }
    else
    {
        print_international_menu();
    }

    delete_d = true;
    node *current = list.head;
    int found  = 0;

    while(current != nullptr)
    {
        if(current->first_name == new_node->first_name && current->last_name == new_node->last_name)
        {
            cout << "DELETED: " << endl;
            if(dori == 0)
            {
                print_searched_domestic(current);
            }
            else
            {
                print_searched_international(current);
            }
            if(current == list.head)
            {
                found++;
                //remove from head
                node *top = current;
                list.head = current->next;
                delete top;

                current = current->next;
            }
            else if(current == list.tail)
            {
                found++;
                //remove from tail
                //iterating to current -1
                node* curminus = list.head;
                while(curminus != current)
                {
                    current = current->next;
                }

                node *cur = current;
                curminus->next = nullptr;
                curminus = list.tail;

                current = current->next;
                delete cur;

            }
            else
            {
                found++;
                node* del = current;
                
                //need to interate to current -1
                node *curminus = list.head;
                while(curminus->next != current)
                {
                    curminus = curminus->next;
                }

                curminus->next = current->next;
                current = current->next;

                delete del;

            }
        }
        else
        {
            current = current->next;
        }

    }

    if(found == 0)
    {
        std::cout << "No match found." << endl;
    }
    //free(new_node);
    return list.head;
}

Linkedlist delete_node(Linkedlist list, int dori)
{
    node *current = list.head;
    node *new_node = delete_getinfo_domestic();
    int found = 0;

    // dori stands for domestic or international
    // helper to print the correct menu
    // 0 is domestic
    // 1 is international
    if (dori == 0)
    {
        print_domestic_menu();
    }
    else
    {
        print_international_menu();
    }

    while (current != nullptr && current->next != nullptr)
    {
        if ((list.head->first_name == new_node->first_name) && (list.head->last_name == new_node->last_name))
        {
            current = list.head;
            found++;
            //dori stands for domestic or international
            //helper to print the correct menu
            //0 is domestic
            //1 is international
            if (dori == 0)
            {
                print_searched_domestic(current);
            }
            else
            {
                print_searched_international(current);
            }
            // then remove from head
            list.head = current->next;
            cout << "DELETED" << endl;
            //print_searched_domestic(current);
            delete current;
            current = list.head;
        }
        else
        {
            if (((current->next)->first_name == new_node->first_name) && ((current->next)->last_name == new_node->last_name))
            {
                found++;

                cout << "DELETED " << endl;
                if (dori == 0)
                {
                    print_searched_domestic(current->next);
                }
                else
                {
                    print_searched_international(current->next);
                }
                //print_searched_domestic(current->next);

                node *current3 = current->next;

                current->next = current->next->next;
                delete current3;
            }
            else
            {
                current = current->next;
            }
        }
    }
    if (found == 0)
    {
        std::cout << "No match found." << endl;
    }
    free(new_node);
    return list;
}

Linkedlist delete_ht(Linkedlist list)
{

    node *current = list.head;

    node *tailminus = list.head;
    //iterating to tail-1 pointer the deleting it
    while(tailminus->next->next != nullptr)
    {
        tailminus = tailminus->next;
    }
    //cout << "this is tail-1 " << tailminus->first_name << endl;

    // remove from head
    list.head = current->next;
    delete current;

    // remove from tail
    tailminus->next = nullptr;
    delete tailminus->next;


    return list;
}

//*********************************DOMESTIC********************************************

node* insert_domestic(node *list_head, node *new_node)
{
    Linkedlist list;
    list.head = list_head;

    if (new_node->province == "NL" || new_node->province == "PE" || new_node->province == "NS" || new_node->province == "NB" || new_node->province == "QC" ||
        new_node->province == "ON" || new_node->province == "MB" || new_node->province == "SK" || new_node->province == "AB" || new_node->province == "BC" ||
        new_node->province == "YT" || new_node->province == "NT" || new_node->province == "NU")
    {
        if ((new_node->research_score >= 0 && new_node->research_score <= 100))
        {
            if (new_node->cgpa >= 0 && new_node->cgpa <= 4.33)
            {
                if (digit_d == true && alpha_d == true)
                {
                    if(list.head == nullptr)
                    {
                        list.head = new_node;
                        list.tail = new_node;
                        return list.head;
                    }
                    node *cur = list.head;

                    if (new_node->research_score > cur->research_score)
                    {
                        // add to head
                        new_node->next = cur;
                        list.head = new_node;
                    }
                    else if (new_node->research_score < cur->research_score)
                    {
                        if (cur->next == nullptr)
                        {
                            // add as second element
                            cur->next = new_node;
                            list.tail = new_node;
                        }
                        else
                        {
                            // when there is more than one element
                            // check for next element
                            while ((new_node->research_score < cur->research_score) && (cur->next != nullptr) && (new_node->research_score <= cur->next->research_score))
                            {
                                // first find correct place for cur
                                cur = cur->next;
                            }

                            // cout << cur->first_name << endl;
                            node *cur_minus1 = list.head;
                            while ((cur_minus1 != cur) && (cur_minus1->next != cur))
                            {
                                cur_minus1 = cur_minus1->next;
                            }
                            // cout << cur_minus1->first_name << endl;

                            if (cur->next == nullptr)
                            {
                                // add as second element
                                cur->next = new_node;
                                list.tail = new_node;
                            }
                            else if (new_node->research_score == cur->research_score)
                            {
                                // go to  the highest node with that rscore
                                node *top = cur;
                                int count = 1;

                                if (new_node->cgpa == top->cgpa)
                                {
                                    if (new_node->province == top->province)
                                    {
                                        // then insert check if province = then add after
                                        new_node->next = cur->next;
                                        cur->next = new_node;
                                    }
                                    else if (new_node->province < top->province)
                                    {
                                        // when ab<bc
                                        // then you add it before the top
                                        new_node->next = cur_minus1->next;
                                        cur_minus1->next = new_node;
                                    }
                                    else if (new_node->province > top->province)
                                    {
                                        // bc > ab
                                        // want to add after
                                        // need to iterate through all values of same rscore and cgpa and compare province
                                        node *iter3 = top;

                                        while ((new_node->research_score == iter3->research_score) && (new_node->cgpa == iter3->cgpa) && (new_node->cgpa < (iter3->next)->cgpa) && (new_node->province > iter3->province) && (new_node->province < (iter3->next)->province) && (iter3->next != nullptr))
                                        {
                                            iter3 = iter3->next;
                                        }
                                        // after finding correct node you want to add after
                                        new_node->next = iter3->next;
                                        iter3->next = new_node;
                                    }
                                    else
                                    {
                                        cout << "error in same province studd " << endl;
                                    }
                                }
                                else if (new_node->cgpa < top->cgpa)
                                {
                                    if (cur->next == nullptr)
                                    {
                                        // insert at end of list after cur
                                        cur->next = new_node;
                                        list.tail = new_node;
                                    }
                                    else
                                    {
                                        // want to insert after
                                        // iterating after all that have that same rscore
                                        node *iter = cur;

                                        if (iter->next == nullptr)
                                        {
                                            // add to tail
                                            iter->next = new_node;
                                            list.tail = new_node;
                                        }
                                        else
                                        {
                                            while (((iter->next != nullptr) && (new_node->research_score == (iter->next)->research_score) && (new_node->research_score == iter->research_score) && (new_node->cgpa < iter->cgpa) && (new_node->cgpa <= (iter->next)->cgpa)))
                                            {
                                                iter = iter->next;
                                            }
                                            // now at top of same rscore and cgpa
                                            // cout << iter->first_name << endl;

                                            if (new_node->cgpa == iter->cgpa)
                                            {
                                                if (new_node->province == iter->province)
                                                {
                                                    // then insert after
                                                    new_node->next = iter->next;
                                                    iter->next = new_node;
                                                }
                                                else if (new_node->province < iter->province)
                                                {
                                                    // new node to point before iter
                                                    node *before_iter = list.head;
                                                    while ((before_iter != iter) && (before_iter->next != iter))
                                                    {
                                                        before_iter = before_iter->next;
                                                    }
                                                    //cout << before_iter->first_name << endl;
                                                    // then insert before iter
                                                    new_node->next = before_iter->next;
                                                    before_iter->next = new_node;
                                                }
                                                else if (new_node->province > iter->province)
                                                {
                                                    // then you wnat to insert after
                                                    new_node->next = iter->next;
                                                    iter->next = new_node;
                                                }
                                            }
                                            else if (new_node->cgpa < iter->cgpa)
                                            {
                                                // then you wnt to insert after
                                                new_node->next = iter->next;
                                                iter->next = new_node;
                                            }
                                            else if (new_node->cgpa > iter->cgpa)
                                            {
                                                // then you want to insert before
                                                node *b4iter = list.head;
                                                while ((b4iter != iter) && (b4iter->next != iter))
                                                {
                                                    b4iter = b4iter->next;
                                                }
                                                new_node->next = b4iter->next;
                                                b4iter->next = new_node;
                                            }
                                        }
                                    }
                                }
                                else if (new_node->cgpa > top->cgpa)
                                {
                                    // then you want to insert before
                                    // finding top-1 pointer
                                    node *curminus = list.head;
                                    while ((curminus != top) && (curminus->next != top))
                                    {
                                        curminus = curminus->next;
                                    }

                                    // then inserts after
                                    new_node->next = curminus->next;
                                    curminus->next = new_node;
                                }
                                else
                                {
                                    cout << "error " << endl;
                                }
                            }
                            else
                            {
                                // inserting between two elements
                                // inserts after even if equal
                                new_node->next = cur->next;
                                cur->next = new_node;
                            }
                        }
                    }
                    else if (new_node->research_score == cur->research_score)
                    {
                        // if the newnode and head val are equal
                        if (new_node->cgpa == cur->cgpa)
                        {
                            node *top = cur;

                            node *cur_minus1 = list.head;
                            while ((cur_minus1 != cur) && (cur_minus1->next != cur))
                            {
                                cur_minus1 = cur_minus1->next;
                            }

                            if (new_node->province == top->province)
                            {
                                // then insert check if province = then add after
                                new_node->next = cur->next;
                                cur->next = new_node;
                            }
                            else if (new_node->province < top->province)
                            {
                                // when ab<bc
                                // then you add it before the top
                                new_node->next = cur_minus1;
                                list.head = new_node;
                            }
                            else if (new_node->province > top->province)
                            {
                                // bc > ab
                                // want to add after
                                // need to iterate through all values of same rscore and cgpa and compare province
                                node *iter3 = top;

                                while ((new_node->research_score == iter3->research_score) && (new_node->cgpa == iter3->cgpa) && (new_node->province > iter3->province) && (new_node->province < (iter3->next)->province) && (iter3->next != nullptr))
                                {
                                    iter3 = iter3->next;
                                }
                                // after finding correct node you want to add after
                                new_node->next = iter3->next;
                                iter3->next = new_node;
                            }
                            else
                            {
                                cout << "error is same cgap check for prov " << endl;
                            }
                        }
                        else if (new_node->cgpa < cur->cgpa)
                        {
                            // we need to iterate through all that have the same rscore
                            node *iterr = cur;
                            while ((new_node->research_score == iterr->research_score) && ((iterr->next)->research_score == cur->research_score) && (iterr->cgpa > new_node->cgpa) && ((iterr->next)->cgpa > new_node->cgpa))
                            {
                                iterr = iterr->next;
                            }
                            // then insert after
                            new_node->next = iterr->next;
                            iterr->next = new_node;
                        }
                        else if (new_node->cgpa > cur->cgpa)
                        {
                            if (cur == list.head)
                            {
                                // then add to head
                                new_node->next = list.head;
                                list.head = new_node;
                            }
                            else
                            {
                                // finding cur-1 value
                                // inserting as the top value for that research score
                                node *minus1 = list.head;
                                while ((minus1 != cur) && (minus1->next != cur))
                                {
                                    minus1 = minus1->next;
                                }
                                new_node->next = minus1->next;
                                minus1->next = new_node;
                            }
                        }
                        else
                        {
                            cout << "error is rscore == rscore " << endl;
                        }
                    }
                    else
                    {
                        cout << "error in rscore compare" << endl;
                    }

                    // node *print = list.head;
                    // while(print != nullptr)
                    // {
                    //     cout << print->first_name << endl;
                    //     print = print->next;
                    // }

                    // finding and setting list tail
                    node *tail = cur;
                    while (tail->next != nullptr)
                    {
                        tail = tail->next;
                    }
                    list.tail = tail;

                    cout << "Student has been inserted." << endl;
                }
                else if (digit_d == false || alpha_d == false)
                {
                    std::cout << endl
                              << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid entry. Entered a character instead of a digit or a digit instead of a character. Try again." << endl;
                    std::cout << "Student first and last name must be of alphabetical characters." << endl;
                    std::cout << "Valid provinces are NL,PE, NS,NB,QC,ON.MB,SK,AB,BC,YT,NT, and NU." << endl;
                    std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
                }
            }
            else
            {
                std::cout << endl
                          << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid CGPA entered. Try again." << endl;
                std::cout << "Valid provinces are NL,PE, NS,NB,QC,ON.MB,SK,AB,BC,YT,NT, and NU." << endl;
                std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
            }
        }
        else
        {
            std::cout << endl
                      << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid Research Score entered. Try again." << endl;
            std::cout << "Valid provinces are NL,PE, NS,NB,QC,ON.MB,SK,AB,BC,YT,NT, and NU." << endl;
            std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
        }
    }
    else
    {
        std::cout << endl
                  << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid Province entered. Try again." << endl;

        std::cout << "Valid provinces are NL,PE, NS,NB,QC,ON.MB,SK,AB,BC,YT,NT, and NU." << endl;
        std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
    }


    // finding and setting list tail
    node *tail = list.head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    list.tail = tail;
    tail->next = nullptr;

    // free(new_node);
    return list.head;
}

node* insert_domestic(node* list_head, string fname, string lname, string prov, string cgpa, string rscore)
{
    Linkedlist list;
    list.head = list_head;

    digit_d = true;
    alpha_d = true;

    node *new_node = new node;

    new_node->first_name = fname;
    new_node->first_name = case_insensitive(new_node->first_name);
    for (int i = 0; i < new_node->first_name.size(); i++)
    {
        if (!isalpha(new_node->first_name[i]))
        {
            alpha_d = false;
        }
    }

    new_node->last_name = lname;
    new_node->last_name = case_insensitive(new_node->last_name);
    for (int i = 0; i < new_node->last_name.size(); i++)
    {
        if (!isalpha(new_node->last_name[i]))
        {
            alpha_d = false;
        }
    }

    new_node->province = prov;
    // converting province to all capital letters
    new_node->province = prov_to_upper(new_node->province);

    // cgpa error checking
    //  checking if digit is inputed
    int count = 0;
    for (int i = 0; i < cgpa.size(); i++)
    {
        if (!isdigit(cgpa[i]))
        {
            if (cgpa[i] == '.')
            {
                count++;
                if (count > 1)
                {
                    digit_d = false;
                    break;
                }
            }
            else
            {
                digit_d = false;
            }
        }
    }
    cgpa = float_1_dec(cgpa);
    new_node->cgpa = atof(cgpa.c_str()); // converting to float

    // checking if digit is inputed
    for (int i = 0; i < rscore.size(); i++)
    {
        if (!isdigit(rscore[i]))
        {
            digit_d = false;
        }
    }
    new_node->research_score = atoi(rscore.c_str()); // convertign to int

    // using global id
    new_node->id = ID;
    ID++;

    list.head = insert_domestic(list.head,new_node);

    // free(new_node);
    return list.head;
}

Linkedlist openandstore_domestic()
{
    Linkedlist list; // linked list declaration

    string cgpaa; // variable declaration
    string researchscore;
    int lines = 0; // line counter

    // Read the domestic-stu.txt file and exit if failed
    ifstream infile("domestic-stu.txt");
    if (!infile.is_open())
    {
        std::cout << "Unable to open file domestic-stu.txt" << endl;
    }
    else if (infile.is_open())
    {
        string line;
        std::getline(infile, line);

        // for giving student an id
        int stu_id = 20220000;

        while (!infile.eof()) // while not end of file run this loop
        {
            // creating new node
            node *new_node = new node; // used only for creating a new node at the head
            
            digit_d = true;
            alpha_d = true;

            if (infile.eof())
            {
                break;
            }
            // error checking while getting line from file
            //  assigning values to variables
            std::getline(infile, new_node->first_name, ',');
            new_node->first_name = case_insensitive(new_node->first_name);
            for (int i = 0; i < new_node->first_name.size(); i++)
            {
                if (!isalpha(new_node->first_name[i]))
                {
                    alpha_d = false;
                }
            }

            std::getline(infile, new_node->last_name, ',');
            new_node->last_name = case_insensitive(new_node->last_name);
            for (int i = 0; i < new_node->last_name.size(); i++)
            {
                if (!isalpha(new_node->last_name[i]))
                {
                    alpha_d = false;
                }
            }

            std::getline(infile, new_node->province, ',');
            new_node->province = prov_to_upper(new_node->province);
            std::getline(infile, cgpaa, ','); // getting cgpa as string

            digit_d = true;
            // checking if digit is inputed
            int count = 0;
            for (int i = 0; i < cgpaa.size() - 1; i++)
            {
                if (!isdigit(cgpaa[i]))
                {
                    if (cgpaa[i] == '.')
                    {
                        count++;
                        if (count > 1)
                        {
                            digit_d = false;
                        }
                    }
                    else
                    {
                        digit_d = false;
                    }
                }
            }
            cgpaa = float_1_dec(cgpaa);       // rounding to 1 dec
            new_node->cgpa = atof(cgpaa.c_str()); // converting string to float

            std::getline(infile, researchscore, '\n');              // getting rscore as string
            new_node->research_score = atoi(researchscore.c_str()); // converting string to int
            // checking if digit is inputed
            for (int i = 0; i < researchscore.size(); i++)
            {
                if (!isdigit(researchscore[i]))
                {
                    digit_d = false;
                }
            }

            new_node->id = stu_id;
            stu_id++;

            list.head = insert_domestic(list.head,new_node);
        }
    }

    // finding and setting list tail
    node *tail = list.head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    list.tail = tail;

    infile.close();
    return list;
} // end func

void printdomestic_LL(node* list_head)
{
    int stu_count = 1;

    std::cout << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    std::cout.width(7); std::cout << left << "Count";
    std::cout.width(12); std::cout << left << "ID";
    std::cout.width(15); std::cout << left << "First Name";
    std::cout.width(15); std::cout << left << "Last Name";
    std::cout.width(12); std::cout << left << "Province";
    std::cout.width(8); std::cout << left << "CGPA";
    std::cout.width(13); std::cout << left << "Research Score";
    std::cout << endl;
    std::cout << "-----------------------------------------------------------------------------------" << endl;

    node *current = list_head;
        while(current != nullptr)
        {
            std::cout.width(7); std::cout << left << stu_count;
            std::cout.width(12); std::cout << left << current->id;
            std::cout.width(15); std::cout << left << current->first_name;
            std::cout.width(15); std::cout << left << current->last_name;
            std::cout.width(12); std::cout << left << current->province;
            std::cout.width(8); std::cout << left << current->cgpa;
            std::cout.width(13); std::cout << left << current->research_score;
            std::cout << endl;

            current = current->next;
            stu_count++;
        }
    free(current);
    cout << "-----------------------------------------------------------------------------------" << endl;
}

string prov_to_upper(string name)
{
    for (int i = 0; i < name.size(); i++)
    {
        char c = name[i];
        if (islower(c))
            name[i] = toupper(c);
        else
        {
            name[i] = name[i];
        }
    }
    return name;
}

node *getinfo_domestic()
{
    digit_d = true;
    alpha_d = true;

    node *new_n = new node;

    cout << "Enter student first name: " << endl;
    cin >> new_n->first_name;
    new_n->first_name = case_insensitive(new_n->first_name);
        for (int i = 0; i < new_n->first_name.size(); i++)
    {
        if (!isalpha(new_n->first_name[i]))
        {
            alpha_d = false;
        }
    }
    
    cout << "Enter student last name: " << endl;
    cin >> new_n->last_name;
    new_n->last_name = case_insensitive(new_n->last_name);
        for (int i = 0; i < new_n->last_name.size(); i++)
    {
        if (!isalpha(new_n->last_name[i]))
        {
            alpha_d = false;
        }
    }

    cout << "Enter student province: " << endl;
    cin >> new_n->province;
    // converting province to all capital letters
    new_n->province = prov_to_upper(new_n->province);

    cout << "Enter student CGPA: " << endl;
    // storing float value
    string cgpa;
    cin >> cgpa;

    digit_d = true;
    // checking if digit is inputed
    int count = 0;
    for (int i = 0; i < cgpa.size() - 1; i++)
    {
        if (!isdigit(cgpa[i]))
        {
            if (cgpa[i] == '.')
            {
                count++;
                if (count > 1)
                {
                    digit_d = false;
                }
            }
            else
            {
                digit_d = false;
            }
        }
    }
    cgpa = float_1_dec(cgpa);            // rounding to 1 dec
    new_n->cgpa = atof(cgpa.c_str()); // converting string to float
    cout << "Enter student research score: " << endl;
    string rscore;
    cin >> rscore;

    // checking if digit is inputed
    for (int i = 0; i < rscore.size(); i++)
    {
        if (!isdigit(rscore[i]))
        {
            digit_d = false;
        }
    }

    new_n->research_score = atoi(rscore.c_str()); // convertign to int

    // using global id
    new_n->id = ID;
    ID++;

    return new_n;
}

node *delete_getinfo_domestic()
{
    node *new_n = new node;

    cout << "Enter student first name: " << endl;
    cin >> new_n->first_name;
    new_n->first_name = case_insensitive(new_n->first_name);

    cout << "Enter student last name: " << endl;
    cin >> new_n->last_name;
    new_n->last_name = case_insensitive(new_n->last_name);

    return new_n;
}

void print_searched_domestic(node *found)
{
    // if found, print the stu_info
    std::cout.width(12);
    std::cout << left << found->id;
    std::cout.width(15);
    std::cout << left << found->first_name;
    std::cout.width(15);
    std::cout << left << found->last_name;
    std::cout.width(12);
    std::cout << left << found->province;
    std::cout.width(8);
    std::cout << left << setprecision(1) << fixed << found->cgpa;
    std::cout.width(13);
    std::cout << left << found->research_score;
    std::cout << endl;
}

void print_domestic_menu()
{
    std::cout << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    std::cout.width(12);
    std::cout << left << "ID";
    std::cout.width(15);
    std::cout << left << "First Name";
    std::cout.width(15);
    std::cout << left << "Last Name";
    std::cout.width(12);
    std::cout << left << "Province";
    std::cout.width(8);
    std::cout << left << "CGPA";
    std::cout.width(13);
    std::cout << left << "Research Score";
    std::cout << endl;
    std::cout << "-----------------------------------------------------------------------------------" << endl;
}

//*********************************INTERNATIONAL********************************************

node* insert_international(node* list_head, node* new_node)
{
    Linkedlist list;
    list.head = list_head;

    int toefl_total = new_node->toefl_listening + new_node->toefl_reading + new_node->toefl_speaking + new_node->toefl_writing;

    if (new_node->country == "Canada" || new_node->country == "China" || new_node->country == "India" || new_node->country == "Iran" || new_node->country == "Korea")
    {
        if ((new_node->research_score >= 0 && new_node->research_score <= 100))
        {
            if (new_node->cgpa >= 0 && new_node->cgpa <= 4.33)
            {

                if ((toefl_total > 93) && (new_node->toefl_listening >= 20) && (new_node->toefl_reading >= 20) &&
                    (new_node->toefl_speaking >= 20) && (new_node->toefl_writing >= 20))
                {
                    if (digit_i == true && alpha_i == true)
                    {
                        if(list.head == nullptr)
                        {
                            // setting new node as head and tail
                            list.head = new_node;
                            list.tail = new_node;
                            return list.head;
                        }
                        node *cur = list.head;

                        if (new_node->research_score > cur->research_score)
                        {
                            // add to head
                            new_node->next = cur;
                            list.head = new_node;
                        }
                        else if (new_node->research_score < cur->research_score)
                        {
                            if (cur->next == nullptr)
                            {
                                node *cur_minus1 = list.head;
                                while ((cur_minus1 != cur) && (cur_minus1->next != cur))
                                {
                                    cur_minus1 = cur_minus1->next;
                                }

                                if (cur->research_score == new_node->research_score)
                                {
                                    if (cur->cgpa == new_node->cgpa)
                                    {
                                        if (cur->country == new_node->country)
                                        {
                                            // insert at the end
                                            cur->next = new_node;
                                        }
                                        else if (cur->country < new_node->country)
                                        {
                                            // want to insert before
                                            new_node->next = cur;
                                            cur_minus1->next = new_node;
                                        }
                                        else if (cur->country > new_node->country)
                                        {
                                            // insert after
                                            cur->next = new_node;
                                        }
                                    }
                                    else if (cur->cgpa < new_node->cgpa)
                                    {
                                        // insert before
                                        new_node->next = cur;
                                        cur_minus1->next = new_node;
                                    }
                                    else if (cur->cgpa > new_node->cgpa)
                                    {
                                        // insert after
                                        cur->next = new_node;
                                    }
                                }
                                else if (cur->research_score > new_node->research_score)
                                {
                                    // insert after
                                    cur->next = new_node;
                                }
                                else if (cur->research_score < new_node->research_score)
                                {
                                    // insert before
                                    new_node->next = cur;
                                    cur_minus1->next = new_node;
                                }
                            }
                            else
                            {
                                // when there is more than one element
                                // check for next element
                                while ((new_node->research_score < cur->research_score) && (cur->next != nullptr) && (new_node->research_score <= cur->next->research_score))
                                {
                                    // first find correct place for cur
                                    cur = cur->next;
                                }
                                node *cur_minus1 = list.head;
                                while ((cur_minus1 != cur) && (cur_minus1->next != cur))
                                {
                                    cur_minus1 = cur_minus1->next;
                                }

                                if (cur->next == nullptr)
                                {
                                    if (cur->research_score == new_node->research_score)
                                    {
                                        if (cur->cgpa == new_node->cgpa)
                                        {
                                            if (cur->country == new_node->country)
                                            {
                                                // insert at the end
                                                cur->next = new_node;
                                            }
                                            else if (cur->country < new_node->country)
                                            {
                                                // want to insert before
                                                new_node->next = cur;
                                                cur_minus1->next = new_node;
                                            }
                                            else if (cur->country > new_node->country)
                                            {
                                                // insert after
                                                cur->next = new_node;
                                            }
                                        }
                                        else if (cur->cgpa < new_node->cgpa)
                                        {
                                            // insert before
                                            new_node->next = cur;
                                            cur_minus1->next = new_node;
                                        }
                                        else if (cur->cgpa > new_node->cgpa)
                                        {
                                            // insert after
                                            cur->next = new_node;
                                        }
                                    }
                                    else if (cur->research_score > new_node->research_score)
                                    {
                                        // insert after
                                        cur->next = new_node;
                                    }
                                    else if (cur->research_score < new_node->research_score)
                                    {
                                        // insert before
                                        new_node->next = cur;
                                        cur_minus1->next = new_node;
                                    }
                                }
                                else if (new_node->research_score == cur->research_score)
                                {
                                    // go to  the highest node with that rscore
                                    node *top = cur;
                                    int count = 1;

                                    if (new_node->cgpa == top->cgpa)
                                    {
                                        if (new_node->country == top->country)
                                        {
                                            // then insert check if country = then add after
                                            new_node->next = cur->next;
                                            cur->next = new_node;
                                        }
                                        else if (new_node->country < top->country)
                                        {
                                            // when ab<bc
                                            // then you add it before the top
                                            new_node->next = cur_minus1->next;
                                            cur_minus1->next = new_node;
                                        }
                                        else if (new_node->country > top->country)
                                        {
                                            // bc > ab
                                            // want to add after
                                            // need to iterate through all values of same rscore and cgpa and compare country
                                            node *iter3 = top;

                                            while ((new_node->research_score == iter3->research_score) && (new_node->cgpa == iter3->cgpa) && (new_node->cgpa < (iter3->next)->cgpa) && (new_node->country > iter3->country) && (new_node->country < (iter3->next)->country) && (iter3->next != nullptr))
                                            {
                                                iter3 = iter3->next;
                                            }
                                            // after finding correct node you want to add after
                                            new_node->next = iter3->next;
                                            iter3->next = new_node;
                                        }
                                        else
                                        {
                                            cout << "error in same country studd " << endl;
                                        }
                                    }
                                    else if (new_node->cgpa < top->cgpa)
                                    {
                                        if (cur->next == nullptr)
                                        {
                                            // insert at end of list after cur
                                            cur->next = new_node;
                                            list.tail = new_node;
                                        }
                                        else
                                        {
                                            // want to insert after
                                            // iterating after all that have that same rscore
                                            node *iter = cur;

                                            if (iter->next == nullptr)
                                            {
                                                // add to tail
                                                iter->next = new_node;
                                                list.tail = new_node;
                                            }
                                            else
                                            {
                                                while (((iter->next != nullptr) && (new_node->research_score == (iter->next)->research_score) && (new_node->research_score == iter->research_score) && (new_node->cgpa < iter->cgpa) && (new_node->cgpa <= (iter->next)->cgpa)))
                                                {
                                                    iter = iter->next;
                                                }

                                                if (new_node->cgpa == iter->cgpa)
                                                {
                                                    if (new_node->country == iter->country)
                                                    {
                                                        // then insert after
                                                        new_node->next = iter->next;
                                                        iter->next = new_node;
                                                    }
                                                    else if (new_node->country < iter->country)
                                                    {
                                                        // new node to point before iter
                                                        node *before_iter = list.head;
                                                        while ((before_iter != iter) && (before_iter->next != iter))
                                                        {
                                                            before_iter = before_iter->next;
                                                        }
                                                        // then insert before iter
                                                        new_node->next = before_iter->next;
                                                        before_iter->next = new_node;
                                                    }
                                                    else if (new_node->country > iter->country)
                                                    {
                                                        // then you wnat to insert after
                                                        new_node->next = iter->next;
                                                        iter->next = new_node;
                                                    }
                                                }
                                                else if (new_node->cgpa < iter->cgpa)
                                                {
                                                    // then you wnt to insert after
                                                    new_node->next = iter->next;
                                                    iter->next = new_node;
                                                }
                                                else if (new_node->cgpa > iter->cgpa)
                                                {
                                                    // then you want to insert before
                                                    node *b4iter = list.head;
                                                    while ((b4iter != iter) && (b4iter->next != iter))
                                                    {
                                                        b4iter = b4iter->next;
                                                    }
                                                    new_node->next = b4iter->next;
                                                    b4iter->next = new_node;
                                                }
                                            }
                                        }
                                    }
                                    else if (new_node->cgpa > top->cgpa)
                                    {
                                        // then you want to insert before
                                        // finding top-1 pointer
                                        node *curminus = list.head;
                                        while ((curminus != top) && (curminus->next != top))
                                        {
                                            curminus = curminus->next;
                                        }

                                        // then inserts after
                                        new_node->next = curminus->next;
                                        curminus->next = new_node;
                                    }
                                    else
                                    {
                                        cout << "error " << endl;
                                    }
                                }
                                else
                                {
                                    // inserting between two elements
                                    // inserts after even if equal
                                    new_node->next = cur->next;
                                    cur->next = new_node;
                                }
                            }
                        }
                        else if (new_node->research_score == cur->research_score)
                        {
                            // if the newnode and head val are equal
                            if (new_node->cgpa == cur->cgpa)
                            {
                                node *top = cur;

                                node *cur_minus1 = list.head;
                                while ((cur_minus1 != cur) && (cur_minus1->next != cur))
                                {
                                    cur_minus1 = cur_minus1->next;
                                }

                                if (new_node->country == top->country)
                                {
                                    // then insert check if country = then add after
                                    new_node->next = cur->next;
                                    cur->next = new_node;
                                }
                                else if (new_node->country < top->country)
                                {
                                    // when ab<bc
                                    // then you add it before the top
                                    new_node->next = cur_minus1;
                                    list.head = new_node;
                                }
                                else if (new_node->country > top->country)
                                {
                                    // bc > ab
                                    // want to add after
                                    // need to iterate through all values of same rscore and cgpa and compare country
                                    node *iter3 = top;

                                    while ((new_node->research_score == iter3->research_score) && (new_node->cgpa == iter3->cgpa) && (new_node->country > iter3->country) && (new_node->country < (iter3->next)->country) && (iter3->next != nullptr))
                                    {
                                        iter3 = iter3->next;
                                    }
                                    // after finding correct node you want to add after
                                    new_node->next = iter3->next;
                                    iter3->next = new_node;
                                }
                                else
                                {
                                    cout << "error is same cgap check for prov " << endl;
                                }
                            }
                            else if (new_node->cgpa < cur->cgpa)
                            {
                                // add after head node
                                new_node->next = cur->next;
                                cur->next = new_node;
                            }
                            else if (new_node->cgpa > cur->cgpa)
                            {
                                if (cur == list.head)
                                {
                                    // then add to head
                                    new_node->next = cur;
                                    list.head = new_node;
                                }
                                else
                                {
                                    // finding cur-1 value
                                    // inserting as the top value for that research score
                                    node *minus1 = list.head;
                                    while ((minus1 != cur) && (minus1->next != cur))
                                    {
                                        minus1 = minus1->next;
                                    }
                                    new_node->next = minus1->next;
                                    minus1->next = new_node;
                                }
                            }
                            else
                            {
                                cout << "error is rscore == rscore " << endl;
                            }
                            // //for now just add to head
                            // new_node->next = list.head;
                            // list.head = new_node;
                        }
                        else
                        {
                            cout << "error in rscore compare" << endl;
                        }

                        cout << "Student has been inserted." << endl;

                    }
                    else if (digit_i == false || alpha_i == false)
                    {
                    std::cout << endl
                              << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid entry. Entered a character instead of a digit or a digit instead of a character. Try again." << endl;
                        std::cout << "Student first and last name must be of alphabetical characters." << endl;
                        std::cout << "Valid provinces are NL,PE, NS,NB,QC,ON.MB,SK,AB,BC,YT,NT, and NU." << endl;
                        std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
                    }

                } // end if
                else
                {
                    std::cout << endl
                              << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid Toefl Score. Try again." << endl;
                    std::cout << "Valid countries are Canada,China,Indian,Iran, and Korea." << endl;
                    std::cout << "Toefl reading,writing,listening and speaking score must be above 20. The total score for TOEFL must be greater than 93." << endl;
                    std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
                }
            }
            else
            {
                std::cout << endl
                          << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid CGPA. Try again." << endl;
                std::cout << "Valid countries are Canada,China,Indian,Iran, and Korea." << endl;
                std::cout << "Toefl reading,writing,listening and speaking score must be above 20. The total score for TOEFL must be greater than 93." << endl;
                std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
            }
        }
        else
        {
            std::cout << endl
                      << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid Research Score. Try again." << endl;
            std::cout << "Valid countries are Canada,China,Indian,Iran, and Korea." << endl;
            std::cout << "Toefl reading,writing,listening and speaking score must be above 20. The total score for TOEFL must be greater than 93." << endl;
            std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
        }
    }
    else
    {
        std::cout << endl
                  << new_node->first_name << " " << new_node->last_name << " could not be inserted. Invalid Country. Try again." << endl;
        std::cout << "Valid countries are Canada,China,Indian,Iran, and Korea." << endl;
        std::cout << "Toefl reading,writing,listening and speaking score must be above 20. The total score for TOEFL must be greater than 93." << endl;
        std::cout << "The range for CGPA is between 0 and 4.33. The range for Research Score is between 0 and 100." << endl;
    }

    // finding and setting list tail
    node *tail = list.head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    list.tail = tail;

    return list.head;
}

node* insert_international(node* list_head, string fname, string lname, string country, string cgpa, string rscore, string toefl_r, string toefl_w, string toefl_s, string toefl_l)
{
    Linkedlist list;
    list.head = list_head;

    digit_d = true;
    alpha_d = true;

    node *new_node = new node;

    new_node->first_name = fname;
    new_node->first_name = case_insensitive(new_node->first_name);
    for (int i = 0; i < new_node->first_name.size(); i++)
    {
        if (!isalpha(new_node->first_name[i]))
        {
            alpha_d = false;
        }
    }

    new_node->last_name = lname;
    new_node->last_name = case_insensitive(new_node->last_name);
    for (int i = 0; i < new_node->last_name.size(); i++)
    {
        if (!isalpha(new_node->last_name[i]))
        {
            alpha_d = false;
        }
    }

    new_node->country = country;
    new_node->country = case_insensitive(new_node->country);

    if (new_node->country == "Idian")
    {
        cout << "Corrected country spelling from Idian to India." << endl;
        new_node->country = "India";
        mis_spell++;
    }

    // cgpa error checking
    //  checking if digit is inputed
    int count = 0;
    for (int i = 0; i < cgpa.size(); i++)
    {
        if (!isdigit(cgpa[i]))
        {
            if (cgpa[i] == '.')
            {
                count++;
                if (count > 1)
                {
                    digit_d = false;
                    break;
                }
            }
            else
            {
                digit_d = false;
            }
        }
    }
    cgpa = float_1_dec(cgpa);
    new_node->cgpa = atof(cgpa.c_str()); // converting to float

    // checking if digit is inputed
    for (int i = 0; i < rscore.size(); i++)
    {
        if (!isdigit(rscore[i]))
        {
            digit_d = false;
        }
    }

    new_node->research_score = atoi(rscore.c_str()); // convertign to int
    



    new_node->toefl_reading = atoi(toefl_r.c_str()); // convertign to int
                                                  // checking if digit is inputed
    for (int i = 0; i < toefl_r.size(); i++)
    {
        if (!isdigit(toefl_r[i]))
        {
            digit_i = false;
        }
    }

    new_node->toefl_writing = atoi(toefl_w.c_str()); // convertign to int
                                                  // checking if digit is inputed
    for (int i = 0; i < toefl_w.size(); i++)
    {
        if (!isdigit(toefl_w[i]))
        {
            digit_i = false;
        }
    }


   
    new_node->toefl_speaking = atoi(toefl_s.c_str()); // convertign to int
                                                   // checking if digit is inputed
    for (int i = 0; i < toefl_s.size(); i++)
    {
        if (!isdigit(toefl_s[i]))
        {
            digit_i = false;
        }
    }



    new_node->toefl_listening = atoi(toefl_l.c_str()); // convertign to int
                                                    // checking if digit is inputed
    for (int i = 0; i < toefl_l.size(); i++)
    {
        if (!isdigit(toefl_l[i]))
        {
            digit_i = false;
        }
    }

    // using global id
    new_node->id = ID;
    ID++;

    list.head = insert_international(list.head, new_node);

    return list.head;
}

Linkedlist openandstore_international()
{
    Linkedlist list; // linked list declaration

    string cgpaa; // variable declaration
    string researchscore;
    string reading;
    string listening;
    string speaking;
    string writing;
    int lines = 0; // line counter

    // Read the domestic-stu.txt file and exit if failed
    ifstream infile("international-stu.txt");
    if (!infile.is_open())
    {
        std::cout << "Unable to open file international-stu.txt" << endl;
    }
    else if (infile.is_open())
    {
        string line;
        std::getline(infile, line);

        // for giving student an id
        int stu_id = 20220100;

        // FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing

        while (!infile.eof()) // while not end of file run this loop
        {
            // creating new node
            node *new_node = new node; // used only for creating a new node at the head

            digit_i = true;
            alpha_i = true;
                if (infile.eof())
                {
                    break;
                }
                // assigning values to variables
                std::getline(infile, new_node->first_name, ',');
                new_node->first_name = case_insensitive(new_node->first_name);
                for (int i = 0; i < new_node->first_name.size(); i++)
                {
                    if (!isalpha(new_node->first_name[i]))
                    {
                        alpha_i = false;
                    }
                }

                std::getline(infile, new_node->last_name, ',');
                new_node->last_name = case_insensitive(new_node->last_name);
                for (int i = 0; i < new_node->last_name.size(); i++)
                {
                    if (!isalpha(new_node->last_name[i]))
                    {
                        alpha_i = false;
                    }
                }

                std::getline(infile, new_node->country, ',');
                new_node->country = case_insensitive(new_node->country);

                if (new_node->country == "Idian")
                {
                    cout << mis_spell << " "
                         << "Corrected country spelling from Idian to India." << endl;
                    new_node->country = "India";
                    mis_spell++;
                }

                std::getline(infile, cgpaa, ','); // getting cgpa as string
                cgpaa = float_1_dec(cgpaa);
                new_node->cgpa = atof(cgpaa.c_str()); // converting string to float

                // checking if digit is inputed
                for (int i = 0; i < cgpaa.size() - 1; i++)
                {
                    if (!isdigit(cgpaa[i]))
                    {
                        int count = 0;
                        if (cgpaa[i] == '.')
                        {
                            count++;
                            if (count > 1)
                            {
                                digit_i = false;
                            }
                        }
                        else
                        {
                            digit_i = false;
                        }
                    }
                }

                std::getline(infile, researchscore, ',');           // getting rscore as string
                new_node->research_score = stoi(researchscore.c_str()); // converting string to int
                // checking if digit is inputed
                for (int i = 0; i < researchscore.size(); i++)
                {
                    if (!isdigit(researchscore[i]))
                    {
                        digit_i = false;
                    }
                }

                std::getline(infile, reading, ',');  // getting reading as string
                new_node->toefl_reading = stoi(reading); // converting to int
                                                     // checking if digits are inputed
                for (int i = 0; i < reading.size(); i++)
                {
                    if (!isdigit(reading[i]))
                    {
                        digit_i = false;
                    }
                }

                std::getline(infile, listening, ',');
                new_node->toefl_listening = stoi(listening);
                // checking if digits are inputed
                for (int i = 0; i < listening.size(); i++)
                {
                    if (!isdigit(listening[i]))
                    {
                        digit_i = false;
                    }
                }

                std::getline(infile, speaking, ',');
                new_node->toefl_speaking = stoi(speaking);
                // checking if digits are inputed
                for (int i = 0; i < speaking.size(); i++)
                {
                    if (!isdigit(speaking[i]))
                    {
                        digit_i = false;
                    }
                }

                std::getline(infile, writing, '\n');
                new_node->toefl_writing = stoi(writing);
                // checking if digits are inputed
                for (int i = 0; i < writing.size(); i++)
                {
                    if (!isdigit(writing[i]))
                    {
                        digit_i = false;
                    }
                }

                new_node->id = stu_id;
                stu_id++;

                list.head = insert_international(list.head,new_node);

        }
}
    // finding and setting list tail
    node *tail = list.head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    list.tail = tail;

    infile.close();

    return list;
}

void printinternational_LL(Linkedlist list)
{
    int stu_count = 1;
    //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
    std::cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    std::cout.width(8); std::cout << left << "Count";
    std::cout.width(12); std::cout << left << "ID";
    std::cout.width(15); std::cout << left << "First Name";
    std::cout.width(17); std::cout << left << "Last Name";
    std::cout.width(10); std::cout << left << "Country";
    std::cout.width(8); std::cout << left << "CGPA";
    std::cout.width(17); std::cout << left << "Research Score";
    std::cout.width(12); std::cout << left << "Reading";
    std::cout.width(12); std::cout << left << "Listening";
    std::cout.width(12); std::cout << left << "Speaking";
    std::cout.width(12); std::cout << left << "Writing";
    std::cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;


    node *current = list.head;
    while(current != nullptr)
    {
        std::cout.width(8); std::cout << left << stu_count;
        std::cout.width(12); std::cout << left << current->id;
        std::cout.width(15); std::cout << left << current->first_name;
        std::cout.width(17); std::cout << left << current->last_name;
        std::cout.width(10); std::cout << left << current->country;
        std::cout.width(8); std::cout << left << current->cgpa;
        std::cout.width(17); std::cout << left << current->research_score;
        std::cout.width(12); std::cout << left << current->toefl_reading;
        std::cout.width(12); std::cout << left << current->toefl_listening;
        std::cout.width(12); std::cout << left << current->toefl_speaking;
        std::cout.width(12); std::cout << left << current->toefl_writing;
        std::cout << endl;

        current = current->next;
        stu_count++;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    // free(current);
}

node *getinfo_international()
{
    digit_i = true;
    alpha_i = true;

    node *new_n = new node;

    cout << "Enter student first name: " << endl;
    cin >> new_n->first_name;
    new_n->first_name = case_insensitive(new_n->first_name);
    for (int i = 0; i < new_n->first_name.size(); i++)
    {
        if (!isalpha(new_n->first_name[i]))
        {
            alpha_i = false;
        }
    }

    cout << "Enter student last name: " << endl;
    cin >> new_n->last_name;
    new_n->last_name = case_insensitive(new_n->last_name);
    for (int i = 0; i < new_n->last_name.size(); i++)
    {
        if (!isalpha(new_n->last_name[i]))
        {
            alpha_i = false;
        }
    }

    cout << "Enter student country: " << endl;
    cin >> new_n->country;
    new_n->country = case_insensitive(new_n->country);

    if (new_n->country == "Idian")
    {
        cout << "Corrected country spelling from Idian to India." << endl;
        new_n->country = "India";
        mis_spell++;
    }

    cout << "Enter student CGPA: " << endl;
    // storing float value
    string cgpa;
    cin >> cgpa;
    cgpa = float_1_dec(cgpa);
    new_n->cgpa = atof(cgpa.c_str()); // converting to float
                                      // checking if digit is inputed
    int count = 0;
    for (int i = 0; i < cgpa.size(); i++)
    {
        if (!isdigit(cgpa[i]))
        {
            if (cgpa[i] == '.')
            {
                count++;
                if (count > 1)
                {
                    digit_i = false;
                }
            }
            else
            {
                digit_i = false;
            }
        }
    }

    cout << "Enter student research score: " << endl;
    string rscore;
    cin >> rscore;
    new_n->research_score = atoi(rscore.c_str()); // convertign to int
                                                  // checking if digit is inputed
    for (int i = 0; i < rscore.size(); i++)
    {
        if (!isdigit(rscore[i]))
        {
            digit_i = false;
        }
    }

    cout << "Enter student TOEFL reading score: " << endl;
    string toefl_r;
    cin >> toefl_r;
    new_n->toefl_reading = atoi(toefl_r.c_str()); // convertign to int
                                                  // checking if digit is inputed
    for (int i = 0; i < toefl_r.size(); i++)
    {
        if (!isdigit(toefl_r[i]))
        {
            digit_i = false;
        }
    }

    cout << "Enter student TOEFL writing score: " << endl;
    string toefl_w;
    cin >> toefl_w;
    new_n->toefl_writing = atoi(toefl_w.c_str()); // convertign to int
                                                  // checking if digit is inputed
    for (int i = 0; i < toefl_w.size(); i++)
    {
        if (!isdigit(toefl_w[i]))
        {
            digit_i = false;
        }
    }

    cout << "Enter student TOEFL speaking score: " << endl;
    string toefl_s;
    cin >> toefl_s;
    new_n->toefl_speaking = atoi(toefl_s.c_str()); // convertign to int
                                                   // checking if digit is inputed
    for (int i = 0; i < toefl_s.size(); i++)
    {
        if (!isdigit(toefl_s[i]))
        {
            digit_i = false;
        }
    }

    cout << "Enter student TOEFL listening score: " << endl;
    string toefl_l;
    cin >> toefl_l;
    new_n->toefl_listening = atoi(toefl_l.c_str()); // convertign to int
                                                    // checking if digit is inputed
    for (int i = 0; i < toefl_l.size(); i++)
    {
        if (!isdigit(toefl_l[i]))
        {
            digit_i = false;
        }
    }

    // using global id
    new_n->id = ID;
    ID++;

    return new_n;
}

node *delete_getinfo_international()
{
    node *new_n = new node;

    cout << "Enter student first name: " << endl;
    cin >> new_n->first_name;
    new_n->first_name = case_insensitive(new_n->first_name);
    

    cout << "Enter student last name: " << endl;
    cin >> new_n->last_name;
    new_n->last_name = case_insensitive(new_n->last_name);

    return new_n;
}

void print_searched_international(node *found)
{

    std::cout.width(12);
    std::cout << left << found->id;
    std::cout.width(15);
    std::cout << left << found->first_name;
    std::cout.width(17);
    std::cout << left << found->last_name;
    std::cout.width(10);
    std::cout << left << found->country;
    std::cout.width(8);
    std::cout << left << setprecision(1) << fixed << found->cgpa;
    std::cout.width(17);
    std::cout << left << found->research_score;
    std::cout.width(12);
    std::cout << left << found->toefl_reading;
    std::cout.width(12);
    std::cout << left << found->toefl_listening;
    std::cout.width(12);
    std::cout << left << found->toefl_speaking;
    std::cout.width(12);
    std::cout << left << found->toefl_writing;
    cout << "\n";
}

void print_international_menu()
{

    std::cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    std::cout.width(12);
    std::cout << left << "ID";
    std::cout.width(15);
    std::cout << left << "First Name";
    std::cout.width(17);
    std::cout << left << "Last Name";
    std::cout.width(10);
    std::cout << left << "Country";
    std::cout.width(8);
    std::cout << left << "CGPA";
    std::cout.width(17);
    std::cout << left << "Research Score";
    std::cout.width(12);
    std::cout << left << "Reading";
    std::cout.width(12);
    std::cout << left << "Listening";
    std::cout.width(12);
    std::cout << left << "Speaking";
    std::cout.width(12);
    std::cout << left << "Writing";
    std::cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

//****************************SEARCH FUNCTIONS************************************************

/* DOMESTIC */

void Search_id_domestic(Linkedlist list, int student_id)
{
    // if head is NULL
    node *found = search_id_helper(list.head, student_id); // helper function for searching id
    if (found == nullptr)
    {
        // if stu is not found after traversing  the whole list
        return;
    }
    else
    {
        print_domestic_menu();
        print_searched_domestic(found);
        return;
    }
}

void Search_cgpa_domestic(Linkedlist list, float cgpa)
{

    if (list.head == nullptr)
    { // if list is empty
        cout << "List is empty." << endl;
    }

    search_cgpa_domestic_helper(list.head, 0, cgpa);

    return;
}

void search_cgpa_domestic_helper(node *next_stu, int count, float cgpa_value)
{

    if (next_stu == nullptr)
    {

        if (count == 0)
        { // if there is no such student in the list...count remains 0
            cout << "No match found.";
        }
        free(next_stu);
        return;
    }
    if (next_stu != nullptr)
    {

        if (next_stu->cgpa == cgpa_value) // checking if same cgpa
        {
            count++; // incrementing count everytime a student is found with same cgpa
            if (count == 1)
            {
                print_domestic_menu();
            }
            // printing stu_info
            print_searched_domestic(next_stu);
        }

        next_stu = next_stu->next;
        search_cgpa_domestic_helper(next_stu, count, cgpa_value); // recursive call
        return;
    }
}

void Search_score_domestic(Linkedlist list, int score)
{ // searching based on research_score

    if (list.head == nullptr)
    { // if list is empty
        cout << "List is empty." << endl;
    }

    search_score_domestic_helper(list.head, 0, score); // calling helper function

    return;
}

void search_score_domestic_helper(node *next_stu, int count, int score)
{

    if (next_stu == nullptr)
    { // if end of list is reahced
        if (count == 0)
        {                        // if no stu is found after searching is done
            cout << "No match found."; // inform thr user
        }
        free(next_stu);
        return;
    }

    if (next_stu != nullptr)
    {                                          // if searching the whole list is still in progress
        if (next_stu->research_score == score) // if same research_score as searched
        {
            count++; // student found
            if (count == 1)
            {
                print_domestic_menu();
            }
            print_searched_domestic(next_stu);
            count++; // student found
        }
        next_stu = next_stu->next;                            // check next student
        search_score_domestic_helper(next_stu, count, score); /// recursive call
        return;
    }
}

void Search_name_domestic(Linkedlist list, string fname, string lname)
{

    string first = case_insensitive(fname);
    string last = case_insensitive(lname);

    if (list.head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    search_name_domestic_helper(list.head, 0, first, last);

    return;
}

void search_name_domestic_helper(node *next_stu, int count, string fname, string lname)
{

    if (next_stu == nullptr)
    {
        if (count == 0)
        {
            cout << "No match found.";
        }
        free(next_stu);
        return;
    }

    if (next_stu != nullptr)
    {
        if (next_stu->first_name == fname && next_stu->last_name == lname)
        {
            count++;
            if (count == 1)
            {
                print_domestic_menu();
            }
            print_searched_domestic(next_stu);
        }
        next_stu = next_stu->next;
        search_name_domestic_helper(next_stu, count, fname, lname);
        return;
    }
}

/* INTERNATIONAL */
void Search_id_international(Linkedlist list, int student_id)
{

    node *found = search_id_helper(list.head, student_id); // this function searches for the student and returns its position in the list

    if (found == nullptr) // if not found
    {
        //do nothing
    }
    else
    {
        // if found print info
        print_international_menu();
        print_searched_international(found);
    }
    free(found);
}

void Search_cgpa_international(Linkedlist list, float cgpa)
{

    if (list.head == nullptr)
    { // checking if list is empty
        cout << "List is empty." << endl;
    }
    search_cgpa_international_helper(list.head, 0, cgpa); // calling helper func

    return;
}

void search_cgpa_international_helper(node *next_stu, int count, float cgpa_value)
{

    if (next_stu == nullptr)
    { // if reached the end of list

        if (count == 0)
        { // if student is not found
            cout << "No match found.";
        }
        free(next_stu);
        return;
    }

    if (next_stu != nullptr)
    {                                     // if the whole list is not checked yet
        if (next_stu->cgpa == cgpa_value) // checking for same cgpa
        {
            count++; // increment count everytime stu is found
            if (count == 1)
            {
                print_international_menu();
            }
            // if yes, print stu_info
            print_searched_international(next_stu);
        }

        next_stu = next_stu->next;
        search_cgpa_international_helper(next_stu, count, cgpa_value); // recursive call
        return;
    }
}

void Search_score_international(Linkedlist list, int score)
{

    if (list.head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    search_score_international_helper(list.head, 0, score);

    return;
}

void search_score_international_helper(node *next_stu, int count, int score)
{

    if (next_stu == nullptr)
    {
        if (count == 0)
        {
            cout << "No match found.";
        }
        free(next_stu);
        return;
    }

    if (next_stu != nullptr)
    {
        if (next_stu->research_score == score)
        {
            count++;
            if (count == 1)
            {
                print_international_menu();
            }
            print_searched_international(next_stu);
        }
        next_stu = next_stu->next;
        search_score_international_helper(next_stu, count, score);
        return;
    }
}

void Search_name_international(Linkedlist list, string fname, string lname)
{

    string first = case_insensitive(fname);
    string last = case_insensitive(lname);

    if (list.head == nullptr)
    {
        cout << "List is empty." << endl;
    }
    search_name_international_helper(list.head, 0, first, last);

    return;
}

void search_name_international_helper(node *next_stu, int count, string fname, string lname)
{

    if (next_stu == nullptr)
    {
        if (count == 0)
        {
            cout << "No match found.";
        }
        free(next_stu);
        return;
    }

    if (next_stu != nullptr)
    {
        if (next_stu->first_name == fname && next_stu->last_name == lname)
        {
            count++;
            if (count == 1)
            {
                print_international_menu();
            }
            print_searched_international(next_stu);
        }
        next_stu = next_stu->next;
        search_name_international_helper(next_stu, count, fname, lname);
        return;
    }
}

/* BOTH */
node *search_id_helper(node *next_stu, int student_id)
{

    if (next_stu == nullptr)
    {
        cout << "No record found." << endl;
        return next_stu;
    }
    else if (next_stu->id == student_id) // checking if same id
    {
        return next_stu; // returns the node * of tha student found in the list
    }
    else
    {
        next_stu = next_stu->next;                     // check next student
        return search_id_helper(next_stu, student_id); // recursive call to go thru whole list
    }
}

//****************************MERGE FUNCTIONS************************************************

void printMerged(node *head)
{

    print_international_menu();

    int count = 1;

    while (head != nullptr)
    {
        if (head->province == "NL" || head->province == "PE" || head->province == "NS" || head->province == "NB" || head->province == "QC" ||
            head->province == "ON" || head->province == "MB" || head->province == "SK" || head->province == "AB" || head->province == "BC" ||
            head->province == "YT" || head->province == "NT" || head->province == "NU")
        {
            std::cout.width(8);
            std::cout << left << count;
            std::cout.width(12);
            std::cout << left << head->id;
            std::cout.width(15);
            std::cout << left << head->first_name;
            std::cout.width(17);
            std::cout << left << head->last_name;
            std::cout.width(20);
            std::cout << left << head->province;
            std::cout.width(10);
            std::cout << left << head->cgpa;
            std::cout.width(17);
            std::cout << left << head->research_score;
            std::cout.width(12);
            std::cout << left << "-";
            std::cout.width(12);
            std::cout << left << "-";
            std::cout.width(12);
            std::cout << left << "-";
            std::cout.width(12);
            std::cout << left << "-";
            std::cout << endl;

            head = head->next;
            count++;
        }
        else
        {
            std::cout.width(8);
            std::cout << left << count;
            std::cout.width(12);
            std::cout << left << head->id;
            std::cout.width(15);
            std::cout << left << head->first_name;
            std::cout.width(17);
            std::cout << left << head->last_name;
            std::cout.width(20);
            std::cout << left << head->country;
            std::cout.width(10);
            std::cout << left << head->cgpa;
            std::cout.width(17);
            std::cout << left << head->research_score;
            std::cout.width(12);
            std::cout << left << head->toefl_reading;
            std::cout.width(12);
            std::cout << left << head->toefl_listening;
            std::cout.width(12);
            std::cout << left << head->toefl_speaking;
            std::cout.width(12);
            std::cout << left << head->toefl_writing;
            std::cout << endl;

            head = head->next;
            count++;
        }
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

node *mergeLists(node *first, node *second)
{
    //base case
    if (first == nullptr)
    {
        return second;
    }

    //base case
    if (second == nullptr)
    {
        return first;
    }

    // if first list is greater, return it
    if (first->research_score > second->research_score)
    {
        first->next = mergeLists(first->next, second);//recursive call
        return first;
    }
    //else return second
    else if (first->research_score < second->research_score)//recursive call
    {
        second->next = mergeLists(first, second->next);
        return second;
    }

    //otherwise when research score is equal
    else
    {
        //return first if first is greater
        if (first->cgpa > second->cgpa)
        {
            first->next = mergeLists(first->next, second);//recursive call
            return first;
        }
        // otherwise return second
        else
        {
            second->next = mergeLists(first, second->next);//recursive call
            return second;
        }
    }
}

void printSearchThreshold(node* head){
       

    if (head->province == "NL" || head->province == "PE" || head->province == "NS" || head->province == "NB" || head->province == "QC" ||
            head->province == "ON" || head->province == "MB" || head->province == "SK" || head->province == "AB" || head->province == "BC" ||
            head->province == "YT" || head->province == "NT" || head->province == "NU")
        {
            std::cout.width(8);
            std::cout.width(12);
            std::cout << left << head->id;
            std::cout.width(15);
            std::cout << left << head->first_name;
            std::cout.width(17);
            std::cout << left << head->last_name;
            std::cout.width(20);
            std::cout << left << head->province;
            std::cout.width(10);
            std::cout << left << head->cgpa;
            std::cout.width(17);
            std::cout << left << head->research_score;
            std::cout.width(12);
            std::cout << left << "-";
            std::cout.width(12);
            std::cout << left << "-";
            std::cout.width(12);
            std::cout << left << "-";
            std::cout.width(12);
            std::cout << left << "-";
            std::cout << endl;

            head = head->next;
    
        }
        else
        {
            std::cout.width(8);
            std::cout.width(12);
            std::cout << left << head->id;
            std::cout.width(15);
            std::cout << left << head->first_name;
            std::cout.width(17);
            std::cout << left << head->last_name;
            std::cout.width(20);
            std::cout << left << head->country;
            std::cout.width(10);
            std::cout << left << head->cgpa;
            std::cout.width(17);
            std::cout << left << head->research_score;
            std::cout.width(12);
            std::cout << left << head->toefl_reading;
            std::cout.width(12);
            std::cout << left << head->toefl_listening;
            std::cout.width(12);
            std::cout << left << head->toefl_speaking;
            std::cout.width(12);
            std::cout << left << head->toefl_writing;
            std::cout << endl;

            head = head->next;

        }
    }
   
void searchcgpa_threshold(node* head, string threshold){
    
    digit_i = true;
    int count = 0;
    for (int i = 0; i < threshold.size(); i++) //checking function to ensure only a number is inputed
    {
        if (!isdigit(threshold[i]))
        {
            if (threshold[i] == '.')
            {
                count++;
                if (count > 1)
                {
                    digit_i = false;
                }
            }
            else
            {
                digit_i = false;
            }
        }
    }
    float_1_dec(threshold); //rounding user input to 1 decimal

    float thres = atof(threshold.c_str());
    //head->cgpa = atof(threshold.c_str()); // converting to float

                                    
    if(digit_i == true){      // if it is a digit continue the comparing 
        print_international_menu();                            
        while(head != nullptr) {
            // if cgpa score above threshold print
            if(head->cgpa >= thres){
                printSearchThreshold(head);
            }
            else if(head->cgpa < thres){
                //do nothing
            }
            else{
                cout << "There is no match";
            }
            //moving the current head to next one
            head = head->next;
        } 
    } 
    else // if not a digit, print out invalid number
    {
        cout << "Invalid Entry.";
    }  
}

void searchresearch_threshold(node* head, string threshold){

    digit_i = true;
    int count = 0;
    for (int i = 0; i < threshold.size(); i++) //checking function to ensure only a number is inputed
    {
        if (!isdigit(threshold[i]))
        {
            if (threshold[i] == '.')
            {
                count++;
                if (count > 1)
                {
                    digit_i = false;
                }
            }
            else
            {
                digit_i = false;
            }
        }
    }
    float_1_dec(threshold);
    int thres = atoi(threshold.c_str());

    
    if(thres < 0){
        cout << "Invalid entry";
    }

    else if(digit_i ==  true){
        print_international_menu();
        while(head != nullptr) {
            // if research score above threshold print
            if(head->research_score >= thres){
                printSearchThreshold(head);
            }
            else if(head->research_score < thres){
                //do nothing
            }
            else{
                cout << "There is no match";
            }
            //moving the current head to next one
            head = head->next;
        }  
    } 
    else{
        cout << "Invalid Entry";
    }
}











//******************************************************
//***************INTERIM********************************
//******************************************************
// vector<Student::student_info> openandstore_domestic()
// {
//     vector<Domestic::student_info> stuinfo; // vector declaration
//     Domestic::student_info s;

//     string cgpaa; //variable declaration
//     string researchscore;
//     int lines = 0; //line counter

//     //Read the domestic-stu.txt file and exit if failed
//     ifstream infile("domestic-stu.txt");
//     if(!infile.is_open()) 
//     {
//         std::cout << "Unable to open file domestic-stu.txt" << endl;
//     }
//     else if(infile.is_open())
//     {
//         string line;
//         std::getline(infile, line);

//         while(!infile.eof()) //while not end of file run this loop
//         {
//             std::getline(infile, s.first_name, ',');
//             std::getline(infile, s.last_name, ',');
//             std::getline(infile, s.country, ',');

//             std::getline(infile, cgpaa, ','); //getting cgpa as string
//             s.cgpa = atof(cgpaa.c_str()); //converting string to float

//             std::getline(infile, researchscore, '\n'); //getting rscore as string
//             s.research_score = atoi(researchscore.c_str()); //converting string to int

//             stuinfo.push_back(s); //pushes collected input into vector
            
//             //     //get cpga separated by comma, and convert string to float
//             //     std::getline(ss, s_cgpa, ',');
//             //     cgpa = atof(s_cgpa.c_str());
                
//             //     //get researchScore separated by comma, and convert it to int
//             //     std::getline(ss, s_researchScore, ',');
//             //     researchScore = atoi(s_researchScore.c_str());

//             lines+=1;
//         }
//     }
//     infile.close(); //close file

//     // int stu_count = 1;
//     // //printing file unsorted
//     // for(int i = 0; i < lines-1; i++)
//     // {
//     //     std::cout << stu_count << " " << stuinfo[i].first_name << " " << stuinfo[i].last_name << " " 
//     //     << stuinfo[i].country << " " << stuinfo[i].cgpa << " " << stuinfo[i].research_score << endl;

//     //     stu_count++;
//     // }
//     return stuinfo;
// }
// vector<Student::student_info> openandstore_international()
// {

//     vector<International::student_info> stuinfo; // vector declaration
//     International::student_info s;

//     string cgpaa; //variable declaration
//     string researchscore;
//     string reading;
//     string listening;
//     string speaking;                    
//     string writing;
//     int lines = 0; //line counter

//     //Read the domestic-stu.txt file and exit if failed
//     ifstream infile("international-stu.txt");
//     if(!infile.is_open()) 
//     {
//         std::cout << "Unable to open file international-stu.txt" << endl;
//     }
//     else if(infile.is_open())
//     {
//         string line;
//         std::getline(infile, line);

//         //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing

//         while(!infile.eof()) //while not end of file run this loop
//         {
//             std::getline(infile, s.first_name, ',');
//             std::getline(infile, s.last_name, ',');
//             std::getline(infile, s.country, ',');

//             std::getline(infile, cgpaa, ','); //getting cgpa as string
//             s.cgpa = stof(cgpaa); //converting string to float

//             std::getline(infile, researchscore, ','); //getting rscore as string
//             s.research_score = stoi(researchscore); //converting string to int

//             std::getline(infile, reading , ','); //getting reading as string
//             s.toefl_reading = stoi(reading); //converting to int

//             std::getline(infile, listening, ',');
//             s.toefl_listening = stoi(listening);

//             std::getline(infile, speaking, ',');
//             s.toefl_speaking = stoi(speaking);

//             std::getline(infile, writing, '\n');
//             s.toefl_writing = stoi(writing);

//             stuinfo.push_back(s); //pushes collected input into vector

//             lines+=1;
//         }
//     }
//     infile.close(); //close file

//     // int stu_count = 1;
//     // //printing file unsorted
//     // for(int i = 0; i < lines-1; i++)
//     // {
//     //     std::cout << stu_count << " " << stuinfo[i].first_name << " " << stuinfo[i].last_name << " " 
//     //     << stuinfo[i].country << " " << stuinfo[i].cgpa << " " << stuinfo[i].research_score << " "
//     //     << stuinfo[i].toefl_reading << " " <<stuinfo[i].toefl_listening << " " << stuinfo[i].toefl_speaking << " "
//     //     << stuinfo[i].toefl_writing << endl;

//     //     stu_count++;
//     // }
//     return stuinfo;
// }

// void sort_overall_domestic()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_domestic(); // vector declaration
//     Domestic::student_info s;

//     for(int i = 0; i<100; i++)
//     {

//         //creating two students and comparing their research score
//         Domestic s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score);
//         Domestic s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score);


//         string str1 = compare_CGPA(s1,s2);
//         if(s1 < s2) //bool operator checking  and sorting by rscore
//         {
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 int key = stuinfo[q].research_score; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].research_score < key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     h--;
//                 }
//                 stuinfo[h+1].research_score = key;
//             }
//         }
//         if(s1 == s2) //if the research scores are equal
//         {
//             if(s1 > s2) //bool operator checking if s1 cgpa is < s2 cgpa
//             {
//                 //this is insertion sort
//                 for(int q=1; q<100; q++) //i = q, h = j
//                 {
//                     float key = stuinfo[q].cgpa; //mark first as sorted
//                     int h = q-1;

//                     while(h>=0 && stuinfo[h].cgpa < key)
//                     {
//                         swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                         swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                         swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                         swap(stuinfo[h+1].country, stuinfo[h].country);
//                         swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                         h--;
//                     }
//                     stuinfo[h+1].cgpa = key;
//                 }
//             }
//             else if(str1 == "=") //if cgpa is equal
//                 {
//                     //this is insertion sort
//                         for(int q=1; q<100; q++) //i = q, h = j
//                         {
//                             string key = stuinfo[q].country; //mark first as sorted
//                             int h = q-1;

//                             while(h>=0 && stuinfo[h].country > key)
//                             {
//                                 swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                                 swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                                 swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                                 swap(stuinfo[h+1].country, stuinfo[h].country);
//                                 swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                                 h--;
//                             }
//                             stuinfo[h+1].country = key;
//                         }
//                 }
//             else
//                 {
//                     //do nothing
//                 }
//             }
//         }
//     //printing sorted
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << endl;

//         stu_count++;
//     }
// }

// void sort_overall_international()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_international(); // vector declaration
//     International::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
//         International s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);
//         International s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);

//         string str1 = compare_CGPA(s1,s2);
//         if(s1 < s2) //bool operator checking  and sorting by rscore
//         {
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 int key = stuinfo[q].research_score; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].research_score < key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
//                     swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
//                     swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
//                     swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);
//                     h--;
//                 }
//                 stuinfo[h+1].research_score = key;
//             }
//         }
//         if(s1 == s2) //if the research scores are equal
//         {
//             if(s1 > s2) //bool operator checking if s1 cgpa is < s2 cgpa
//             {
//                 //this is insertion sort
//                 for(int q=1; q<100; q++) //i = q, h = j
//                 {
//                     float key = stuinfo[q].cgpa; //mark first as sorted
//                     int h = q-1;

//                     while(h>=0 && stuinfo[h].cgpa < key)
//                     {
//                         swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                         swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                         swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                         swap(stuinfo[h+1].country, stuinfo[h].country);
//                         swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                         swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
//                         swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
//                         swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
//                         swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);
//                         h--;
//                     }
//                     stuinfo[h+1].cgpa = key;
//                 }
//             }
//             else if(str1 == "=") //if cgpa is equal
//                 {
//                     //this is insertion sort
//                         for(int q=1; q<100; q++) //i = q, h = j
//                         {
//                             string key = stuinfo[q].country; //mark first as sorted
//                             int h = q-1;

//                             while(h>=0 && stuinfo[h].country > key)
//                             {
//                                 swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                                 swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                                 swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                                 swap(stuinfo[h+1].country, stuinfo[h].country);
//                                 swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                                 swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
//                                 swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
//                                 swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
//                                 swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);
//                                 h--;
//                             }
//                             stuinfo[h+1].country = key;
//                         }
//                 }
//             else
//                 {
//                     //do nothing
//                 }
//             }
//         }
//      //printing sorted
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << " " 
//         << stuinfo[k].toefl_reading << " " << stuinfo[k].toefl_listening << " " << stuinfo[k].toefl_speaking << " "
//         << stuinfo[k].toefl_writing << endl;

//         stu_count++;
//     }
// }


// void sort_by_researchscore_domestic()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_domestic(); // vector declaration
//     Domestic::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         Domestic s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score);
//         Domestic s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score);
        
//         string compare = compare_ResearchScore(s1,s2);
//         if(compare == "<") //bool operator checking if s1  < s2 
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 int key = stuinfo[q].research_score; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].research_score < key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     h--;
//                 }
//                 stuinfo[h+1].research_score = key;
//             }
//         }
//         else //when they are equal or greater do nothing
//         {
//                 //do nothing
//         }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << endl;

//         stu_count++;
//     }
     
// }

// void sort_by_researchscore_international()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_international(); // vector declaration
//     International::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
//         International s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);
//         International s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);

//         string compare = compare_ResearchScore(s1,s2);
//         if(compare == "<") //is s1 val is less than s2 val
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 int key = stuinfo[q].research_score; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].research_score < key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
//                     swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
//                     swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
//                     swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);

//                     h--;
//                 }
//                 stuinfo[h+1].research_score = key;
//             }
//         }
//         else
//         {
//             //do nothing when = or >
//         }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << " " 
//         << stuinfo[k].toefl_reading << " " << stuinfo[k].toefl_listening << " " << stuinfo[k].toefl_speaking << " "
//         << stuinfo[k].toefl_writing << endl;

//         stu_count++;
//     }
// }


// void sort_by_cgpa_domestic()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_domestic(); // vector declaration
//     Domestic::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         Domestic s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score);
//         Domestic s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score);
        
//         string compare = compare_CGPA(s1,s2);
//         if(compare == "<") //bool operator checking if s1  < s2 
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 float key = stuinfo[q].cgpa; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].cgpa < key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     h--;
//                 }
//                 stuinfo[h+1].cgpa = key;
//             }
//         }
//             else //when they are equal or greater do nothing
//             {
//                 //do nothing
//             }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << endl;

//         stu_count++;
//     }
    
// }

// void sort_by_cgpa_international()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_international(); // vector declaration
//     International::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
//         International s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);
//         International s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);

//         string compare = compare_CGPA(s1,s2);
//         if(compare == "<") //is s1 val is less than s2 val
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 float key = stuinfo[q].cgpa; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].cgpa < key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
//                     swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
//                     swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
//                     swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);

//                     h--;
//                 }
//                 stuinfo[h+1].cgpa = key;
//             }
//         }
//         else
//         {
//             //do nothing when = or >
//         }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << " " 
//         << stuinfo[k].toefl_reading << " " << stuinfo[k].toefl_listening << " " << stuinfo[k].toefl_speaking << " "
//         << stuinfo[k].toefl_writing << endl;

//         stu_count++;
//     }
// }


// void sort_by_firstname_domestic()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_domestic(); // vector declaration
//     Domestic::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         Domestic s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score);
//         Domestic s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score);
        
//         string compare = compare_FirstName(s1,s2);
//         if(compare == "<") //bool operator checking if s1  < s2 
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 string key = stuinfo[q].first_name; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].first_name > key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     h--;
//                 }
//                 stuinfo[h+1].first_name = key;
//             }
//         }
//             else //when they are equal or greater do nothing
//             {
//                 //do nothing
//             }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << endl;

//         stu_count++;
//     }
     
// }

// void sort_by_firstname_international()
// {
//     //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_international(); // vector declaration
//     International::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
//         International s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);
//         International s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);

//         string compare = compare_FirstName(s1,s2);
//         if(compare == "<") //is s1 val is less than s2 val
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 string key = stuinfo[q].first_name; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].first_name > key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
//                     swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
//                     swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
//                     swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);

//                     h--;
//                 }
//                 stuinfo[h+1].first_name = key;
//             }
//         }
//         else
//         {
//             //do nothing when = or >
//         }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << " " 
//         << stuinfo[k].toefl_reading << " " << stuinfo[k].toefl_listening << " " << stuinfo[k].toefl_speaking << " "
//         << stuinfo[k].toefl_writing << endl;

//         stu_count++;
//     }
// }


// void sort_by_lastname_domestic()
// {
//      //new vector declaration
//     vector<Domestic::student_info> stuinfo = openandstore_domestic(); // vector declaration
//     Domestic::student_info s;

//     int count = 0;

//     for(int i = 0; i<100; i++)
//     {
//         //creating two students and comparing their research score
//         Domestic s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score);
//         Domestic s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score);
        
//         string compare = compare_LastName(s1,s2);
//         if(compare == "<") //bool operator checking if s1  < s2 
//         {
//             count++;
//             //this is insertion sort
//             for(int q=1; q<100; q++) //i = q, h = j
//             {
//                 string key = stuinfo[q].last_name; //mark first as sorted
//                 int h = q-1;

//                 while(h>=0 && stuinfo[h].last_name > key)
//                 {
//                     swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
//                     swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
//                     swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
//                     swap(stuinfo[h+1].country, stuinfo[h].country);
//                     swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
//                     h--;
//                 }
//                 stuinfo[h+1].last_name = key;
//             }
//         }
//             else //when they are equal or greater do nothing
//             {
//                 //do nothing
//             }
//     }
//     //std::cout<< " count of < is " << count << endl;

//     //printing sorted by cgpa
//     int stu_count = 1;
//     for(int k = 0; k < 100; k++)
//     {
//         std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
//         << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << endl;

//         stu_count++;
//     }
    
// }

// void sort_by_lastname_international()
//{
//new vector declaration
    // vector<Domestic::student_info> stuinfo = openandstore_international(); // vector declaration
    // International::student_info s;

    // int count = 0;

    // for(int i = 0; i<100; i++)
    // {
    //     //creating two students and comparing their research score
    //     //FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
    //     International s1(stuinfo[i].first_name, stuinfo[i].last_name, stuinfo[i].country, stuinfo[i].cgpa, stuinfo[i].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);
    //     International s2(stuinfo[i+1].first_name, stuinfo[i+1].last_name, stuinfo[i+1].country, stuinfo[i+1].cgpa, stuinfo[i+1].research_score, stuinfo[i].toefl_reading, stuinfo[i].toefl_listening, stuinfo[i].toefl_speaking, stuinfo[i].toefl_writing);

    //     string compare = compare_LastName(s1,s2);
    //     if(compare == "<") //is s1 val is less than s2 val
    //     {
    //         count++;
    //         //this is insertion sort
    //         for(int q=1; q<100; q++) //i = q, h = j
    //         {
    //             string key = stuinfo[q].last_name; //mark first as sorted
    //             int h = q-1;

    //             while(h>=0 && stuinfo[h].last_name > key)
    //             {
    //                 swap(stuinfo[h+1].research_score,stuinfo[h].research_score);
    //                 swap(stuinfo[h+1].first_name, stuinfo[h].first_name);
    //                 swap(stuinfo[h+1].last_name, stuinfo[h].last_name);
    //                 swap(stuinfo[h+1].country, stuinfo[h].country);
    //                 swap(stuinfo[h+1].cgpa, stuinfo[h].cgpa);
    //                 swap(stuinfo[h+1].toefl_listening, stuinfo[h].toefl_listening);
    //                 swap(stuinfo[h+1].toefl_speaking, stuinfo[h].toefl_speaking);
    //                 swap(stuinfo[h+1].toefl_writing, stuinfo[h].toefl_writing);
    //                 swap(stuinfo[h+1].toefl_reading, stuinfo[h].toefl_reading);

    //                 h--;
    //             }
    //             stuinfo[h+1].last_name = key;
    //         }
    //     }
    //     else
    //     {
    //         //do nothing when = or >
    //     }
    // }
    // //std::cout<< " count of < is " << count << endl;

    // //printing sorted by cgpa
    // int stu_count = 1;
    // for(int k = 0; k < 100; k++)
    // {
    //     std::cout << stu_count << " " << stuinfo[k].first_name << " " << stuinfo[k].last_name << " " 
    //     << stuinfo[k].country << " " << stuinfo[k].cgpa << " " << stuinfo[k].research_score << " " 
    //     << stuinfo[k].toefl_reading << " " << stuinfo[k].toefl_listening << " " << stuinfo[k].toefl_speaking << " "
    //     << stuinfo[k].toefl_writing << endl;

    //     stu_count++;
    // }
    // }
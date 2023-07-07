#pragma once

#include"Ticket_DB.h"
#include<list>
#include<iostream>
using namespace std;

class Ticket_ID_Unassigned_DB
{
    private:
        list<int> List_Ticket_ID;

    public: 
        void add_ticket_id(int ticket_id_param);
        void del_ticket_id(int ticket_id_param);
        int count_going(Summary & s_param, Ticket_DB & ticket_db);
        bool is_present(int ticket_id_param);
        void load_list_going(list<int> &list_param, Summary & s_param, Ticket_DB & ticket_db);
        void print();
};
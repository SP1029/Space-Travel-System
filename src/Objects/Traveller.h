#pragma once

#include<string>
#include<list>
#include<iostream>
#include"Ticket_DB.h"
using namespace std;
class Traveller 
{
    private:
        static int count;
        int traveller_id;
        string name;

    protected:
        list<int> list_ticket_id;

    public:
        Traveller(bool is_actual, int traveller_id_param);
        int get_traveller_id();
        string get_name();
        void set_name(string name_param);
        void add_ticket_id(int ticket_id_param);
        void del_ticket_id(int ticket_id_param);
        bool is_empty_list();
        int pop_back_list();
        void print_tickets(Ticket_DB & ticket_db);
};
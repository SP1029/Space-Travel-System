#pragma once

#include"Ticket_DB.h"
#include<list>
#include"Summary.h"
#define TRAVEL_MAX_CAPACITY 10
#define TRAVEL_MIN_CAPACITY 3
#include"Ticket_DB.h"
#include<iostream>
using namespace std;

class Travel
{
    private:
        static int count;
        int travel_id;
        list<int> list_ticket_id; // set first as astro's ticket_id and second as com's ticket id
        int astro_id;
        int com_id;                

    public:
        Travel(bool is_actual);
        int get_travel_id();
        int get_astro_id();
        void set_astro_id(int astro_id_param);
        int get_com_id();
        void set_com_id(int com_id_param);
        void add_ticket_id(int ticket_id_param);
        void del_ticket_id(int ticket_id_param);
        int pop_back_list();
        bool is_passenger_done_list();
        bool is_full();
        bool is_underfilled();
        bool is_present_ticket_id(int ticket_id_param);
        bool is_going(Summary & s_param, Ticket_DB & ticket_db);   
        void print_travel();     
};

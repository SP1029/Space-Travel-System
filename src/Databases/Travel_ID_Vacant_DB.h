#pragma once

#include"Travel_DB.h"
#include"Ticket_DB.h"
#include<list>
#include"Summary.h"
#include<iostream>
using namespace std;

class Travel_ID_Vacant_DB
{
    private:
        list<int> List_Travel_ID;

    public: 
        void add_travel_id(int travel_id_param);
        void del_travel_id(int travel_id_param);
        bool is_present(int ticket_id_param, Travel_DB & travel_db);
        int get_travel_id_for_ticket_id(int ticket_id_param, Travel_DB & travel_db);
        bool is_going_any(Summary & s_param, Travel_DB & travel_db, Ticket_DB & ticket_db);
        int get_travel_id_going(Summary & s_param, Travel_DB & travel_db, Ticket_DB & ticket_db);
        void print();
};
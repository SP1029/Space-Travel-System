#pragma once

#include"Travel_DB.h"
#include<list>
#include<iostream>
using namespace std;

class Travel_ID_Full_DB
{
    private:
        list<int> List_Travel_ID;

    public: 
        void add_travel_id(int travel_id_param);
        void del_travel_id(int travel_id_param);
        bool is_present(int ticket_id_param, Travel_DB & travel_db);
        int get_travel_id_for_ticket_id(int ticket_id_param, Travel_DB & travel_db);
        void print();
};
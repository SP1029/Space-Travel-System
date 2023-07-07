#pragma once

#include"Traveller.h"
#include"Summary.h"
#include"Ticket_DB.h"
#include<iostream>
using namespace std;

class Commander : public Traveller
{
    private:
        static int license_initialiser;
        int license_id;        
        
    public:        
        Commander(bool is_actual,int last) : Traveller(is_actual, last)
        {
            if (is_actual)
            {
                license_initialiser++;
                license_id = license_initialiser;
            }
        }
        int get_license_id();
        bool is_available(Summary &s_param, Ticket_DB & ticket_db_param);   
        void print();
};
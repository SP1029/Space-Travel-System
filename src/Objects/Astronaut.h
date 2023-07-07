#pragma once

#include"Traveller.h"
#include"Summary.h"
#include"Ticket_DB.h"
#include<iostream>

class Astronaut : public Traveller
{
    private:
        static int license_initialiser;
        int experience;
        int license_id;
        
    public: 
        Astronaut (bool is_actual, int last) : Traveller(is_actual,last)
        {
            if (is_actual)
            {
                license_initialiser++;
                license_id = license_initialiser;
            }
        };       
        int get_license_id();
        int get_experience();
        void set_experience(int experience_param);
        bool is_available(Summary &s_param, Ticket_DB & ticket_db_param);   
        void print();
};
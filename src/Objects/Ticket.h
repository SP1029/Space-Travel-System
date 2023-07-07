#pragma once

#define PRICE_CONST 1000000
#include<ctime>
#include"Summary.h"
#include"Credentials_DB.h"
#include<iostream>
using namespace std;

class Ticket
{
    private:
        static int count;
        int ticket_id;
        int traveller_id;
        int expiry_date;
        int price;
        void print_date(int date_param);
        int date_today();
        int days_between(int date1, int date2);
        Summary summary;        

    public:
        Ticket(bool is_actual, Summary & s_param);
        int get_ticket_id();
        int get_traveller_id();
        void set_traveller_id(int traveller_id_param);
        Summary get_summary();
        bool is_going(Summary &s_param);
        bool is_his_ticket(Summary s_param, int traveller_id_param);
        int get_price();
        void set_expiry_date(int set_expiry_date_param);
        int get_expiry_date();
        void print_ticket();
};

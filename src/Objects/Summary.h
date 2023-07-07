#pragma once
#include<iostream>
using namespace std;
class Summary
{
    private:
        int date; // date = DD + MM * 31 + YYYY * 31 * 12 will give a unique int for each date and vice-versa
        int source_id;
        int dest_id;

    public:
        int get_date();
        void set_date(int date_param);
        int get_source_id();
        void set_source_id(int source_id_param);
        int get_dest_id();
        void set_dest_id(int dest_id_param);
        bool operator == (Summary & s_param);
};

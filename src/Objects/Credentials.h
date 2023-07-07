#pragma once

#include<string>
#define PASS_TYPE 1
#define ASTRO_TYPE 2
#define COM_TYPE 3
#include<iostream>
using namespace std;
class Credentials
{
    private:
        int traveller_id;
        int type;
        string name;

    public:
        int get_traveller_id();
        void set_traveller_id(int traveller_id_param);
        int get_type();
        void set_type(int type_param);
        string get_name();
        void set_name(string name_param);
        bool operator == (Credentials & c_param);
        void print();
};
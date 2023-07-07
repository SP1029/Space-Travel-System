#pragma once

#include"Credentials.h"
#include<list>

class Credentials_DB
{
    private:
        list<Credentials> List_Credentials;

    public:
        void Add(Credentials & c_param);
        bool is_valid(Credentials & c_param);
        int get_type(int traveller_id_param, string name_param);
        void print();
};

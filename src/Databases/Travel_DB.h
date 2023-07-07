#pragma once

#include"Travel.h"

class Travel_DB
{
    private:
        list<Travel> List_Travel;

    public:
        void Add_Travel(Travel & travel_param);
        void Del_Travel(int travel_id_param);
        Travel get_Travel(int travel_id_param);
        void print();
};
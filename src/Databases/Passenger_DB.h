#pragma once

#include"Passenger.h"
#include<list>

class Passenger_DB
{
private:
    list<Passenger> List_Passenger;

public:
    void Add_Passenger(Passenger & passenger_param);
    void Del_Passenger(int traveller_id_param);
    Passenger get_Passenger(int traveller_id_param);
    void print();
};
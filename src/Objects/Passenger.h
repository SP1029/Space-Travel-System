#pragma once

#include"Traveller.h"
#include<iostream>
using namespace std;
class Passenger : public Traveller
{
    public:
        Passenger (bool is_actual, int last) : Traveller(is_actual,last)
        {
        };
        void print();
};
#include"Planet_DB.h"
#include<iostream>
using namespace std;

void Planet_DB::Add_Planet(Planet & p_param)
{
    List_Planet.push_back(p_param);
}

void Planet_DB::Del_Planet(int p_id_param)
{
    for (auto itr = List_Planet.begin(); itr != List_Planet.end(); itr++)
    {
        if ( (*itr).get_planet_id() == p_id_param )
        {
            List_Planet.erase(itr);
            break;
        }
    }
}

Planet Planet_DB::get_planet(int p_id_param)
{
    Planet p_temp(false);
    for (auto itr = List_Planet.begin(); itr != List_Planet.end(); itr++)
    {
        if ( (*itr).get_planet_id() == p_id_param )
        {
            p_temp =  *itr;
            break;
        }
    }
    return p_temp;
}

int Planet_DB::get_planet_id(string name_param)
{
    int p_temp;
    for (auto itr = List_Planet.begin(); itr != List_Planet.end(); itr++)
    {
        if ( (*itr).get_name() == name_param )
        {
            p_temp =  (*itr).get_planet_id();
            break;
        }
    }
    return p_temp;
}

void Planet_DB::print()
{
    for (auto itr = List_Planet.begin(); itr!=List_Planet.end(); itr ++)
    {
        (*itr).print();
    }
}
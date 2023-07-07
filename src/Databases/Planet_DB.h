#pragma once

#include"Planet.h"
#include<list>

class Planet_DB
{
private:
    list<Planet> List_Planet;

public:
    void Add_Planet(Planet & p_param);
    void Del_Planet(int p_id_param);
    Planet get_planet(int p_id_param);
    int get_planet_id(string name_param);
    void print();
};
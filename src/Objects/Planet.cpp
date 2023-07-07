#include"Planet.h"

int Planet::count = 0;

Planet::Planet (bool is_actual)
{
    if (is_actual)
    {
        count++;
        planet_id = count;
    }    
}

int Planet::get_planet_id()
{
    return planet_id;
}

int Planet::get_x()
{
    return x;
}

void Planet::set_x(int x_param)
{
    x = x_param;
}

int Planet::get_y()
{
    return y;
}

void Planet::set_y(int y_param)
{
    y = y_param;
}

int Planet::get_z()
{
    return z;
}

void Planet::set_z(int z_param)
{
    z = z_param;
}

string Planet::get_name()
{
    return name;
}

void Planet::set_name(string name_param)
{
    name = name_param;
}

void Planet::print()
{
    cout<<"Planet ID: "<<planet_id<<" ";
    cout<<"Planet Name: "<<name<<" ";
    cout<<"Planet X Y Z: "<<x<<" "<<y<<" "<<z<<endl;
}
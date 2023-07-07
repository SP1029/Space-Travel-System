#pragma once

#include<string>
#include<iostream>
using namespace std;
class Planet
{
    private:
        static int count;
        int planet_id;
        int x;
        int y;
        int z;
        string name;

    public:
        Planet (bool is_actual);
        int get_planet_id();
        int get_x();
        void set_x(int x_param);
        int get_y();
        void set_y(int y_param);
        int get_z();
        void set_z(int z_param);
        string get_name();
        void set_name(string name_param);
        void print();
};
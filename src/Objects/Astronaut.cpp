#include"Astronaut.h"
#define LICENCE_INITIAL_ASTRO 1000

int Astronaut::license_initialiser = LICENCE_INITIAL_ASTRO;

int Astronaut::get_license_id()
{
    return license_id;
}

int Astronaut::get_experience()
{
    return experience;
}

void Astronaut::set_experience(int experience_param)
{
    experience = experience_param;
}

bool Astronaut::is_available(Summary & s_param, Ticket_DB & ticket_db_param)
{
    bool flag = true;
    for (auto itr = list_ticket_id.begin(); itr != list_ticket_id.end(); itr ++)
    {
        Summary s_param_junk;
        Ticket t_temp(false,s_param_junk);
        t_temp = ticket_db_param.get_Ticket(*itr);
        if (t_temp.is_going(s_param))
        {
            flag = false;
        }
    }
    return flag;
}

void Astronaut::print()
{
    cout<<"Travelller ID: "<<get_traveller_id()<<" ";
    cout<<"Name: "<<get_name()<<" ";
    cout<<"Type: Astronaut";
    cout<<"License ID: "<<license_id<<" ";
    cout<<"Experience: "<<experience<<endl;
}
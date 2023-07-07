#include"Commander.h"
#define LICENCE_INITIAL_COM 10000

int Commander::license_initialiser = LICENCE_INITIAL_COM;

int Commander::get_license_id()
{
    return license_id;
}

bool Commander::is_available(Summary & s_param, Ticket_DB & ticket_db_param)
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

void Commander::print()
{
    cout<<"Travelller ID: "<<get_traveller_id()<<" ";
    cout<<"Name: "<<get_name()<<" ";
    cout<<"Type: Commander";
    cout<<"License ID: "<<license_id<<endl;
}
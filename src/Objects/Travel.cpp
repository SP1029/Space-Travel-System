#include"Travel.h"

int Travel::count = 0;

Travel::Travel(bool is_actual)
{
    if (is_actual)
    {
        count++;
        travel_id = count;
    }
}

int Travel::get_travel_id()
{
    return travel_id;
}

int Travel::get_astro_id()
{
    return astro_id;
}

void Travel::set_astro_id(int astro_id_param)
{
    astro_id = astro_id_param;
}

int Travel::get_com_id()
{
    return com_id;
}

void Travel::set_com_id(int com_id_param)
{
    com_id = com_id_param;
}

void Travel::add_ticket_id(int ticket_id_param)
{
    list_ticket_id.push_back(ticket_id_param);
}

void Travel::del_ticket_id(int ticket_id_param)
{
    for (auto itr = list_ticket_id.begin();itr != list_ticket_id.end(); itr++)
    {
        if (*itr == ticket_id_param)
        {
            list_ticket_id.erase(itr);
            break;
        }
    }
}

bool Travel::is_passenger_done_list()
{
    return (list_ticket_id.size()==2);
}

int Travel::pop_back_list()
{
    int travel_id_temp;
    travel_id_temp = list_ticket_id.back();
    list_ticket_id.pop_back();
    return travel_id_temp;
}

bool Travel::is_full()
{
    if (list_ticket_id.size()==TRAVEL_MAX_CAPACITY) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Travel::is_underfilled()
{
    if (list_ticket_id.size()<TRAVEL_MIN_CAPACITY) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Travel::is_present_ticket_id(int ticket_id_param)
{
    int flag = false;
    for (int ticket_id_temp : list_ticket_id)
    {
        if (ticket_id_temp==ticket_id_param)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool Travel::is_going(Summary & s_param, Ticket_DB & ticket_db)
{
    bool flag;
    int ticket_id_temp = list_ticket_id.front();
    Summary s_param_junk;
    Ticket ticket_temp(false,s_param_junk);
    ticket_temp = ticket_db.get_Ticket(ticket_id_temp);
    if (ticket_temp.is_going(s_param))
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}

void Travel::print_travel()
{
    cout<<"Travel ID: "<<travel_id<<" ";
    cout<<"Astro_ID: "<<astro_id<<" ";
    cout<<"Com_ID: "<<com_id<<endl;
    cout<<"List of Ticket_ID:"<<endl;
    for (auto itr : list_ticket_id)
    {
        cout<<itr<<" ";
    }
    cout<<endl;
}
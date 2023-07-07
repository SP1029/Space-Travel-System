#include"Astronaut_DB.h"

void Astronaut_DB::Add_Astronaut(Astronaut & a_param)
{
    List_Astronaut.push_back(a_param);
}

void Astronaut_DB::Del_Astronaut(int traveller_id_param)
{
    for (auto itr = List_Astronaut.begin(); itr != List_Astronaut.end(); itr++)
    {
        if ( (*itr).get_traveller_id() == traveller_id_param )
        {
            List_Astronaut.erase(itr);
            break;
        }
    }
}

Astronaut Astronaut_DB::get_astronaut(int traveller_id_param)
{
    Astronaut a_temp(false,0);
    for (auto itr = List_Astronaut.begin(); itr != List_Astronaut.end(); itr++)
    {
        if ( (*itr).get_traveller_id() == traveller_id_param )
        {
            a_temp =  *itr;
            break;
        }
    }
    return a_temp;
}

bool Astronaut_DB::is_free_any(Summary & s_param, Ticket_DB & ticket_db_param)
{
    bool flag = false;
    for (auto itr = List_Astronaut.begin(); itr != List_Astronaut.end(); itr++)
    {
        if ( (*itr).is_available(s_param,ticket_db_param) )
        {
            flag = true;
            break;
        }
    }
    return flag;
}

pair<int,int> Astronaut_DB::get_id_of_free(Summary & s_param, Ticket_DB & ticket_db_param)
{
    pair<int,int> p_id;
    for (auto itr = List_Astronaut.begin(); itr != List_Astronaut.end(); itr++)
    {
        if ( (*itr).is_available(s_param,ticket_db_param) )
        {
            p_id.first = (*itr).get_traveller_id();
            p_id.second = (*itr).get_license_id();
            break;
        }
    }
    return p_id;
}

void Astronaut_DB::print()
{
    for (auto itr = List_Astronaut.begin(); itr!=List_Astronaut.end(); itr ++)
    {
        (*itr).print();
    }
}

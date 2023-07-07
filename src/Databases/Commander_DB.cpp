#include"Commander_DB.h"

void Commander_DB::Add_Commander(Commander & com_param)
{
    List_Commander.push_back(com_param);
}

void Commander_DB::Del_Commander(int traveller_id_param)
{
    for (auto itr = List_Commander.begin(); itr != List_Commander.end(); itr++)
    {
        if ( (*itr).get_traveller_id() == traveller_id_param )
        {
            List_Commander.erase(itr);
            break;
        }
    }
}

Commander Commander_DB::get_Commander(int traveller_id_param)
{
    Commander c_temp(false, 0);
    for (auto itr = List_Commander.begin(); itr != List_Commander.end(); itr++)
    {
        if ( (*itr).get_traveller_id() == traveller_id_param )
        {
            c_temp =  *itr;
            break;
        }
    }
    return c_temp;
}

bool Commander_DB::is_free_any(Summary & s_param, Ticket_DB & ticket_db_param)
{
    bool flag = false;
    for (auto itr = List_Commander.begin(); itr != List_Commander.end(); itr++)
    {
        if ( (*itr).is_available(s_param,ticket_db_param) )
        {
            flag = true;
            break;
        }
    }
    return flag;
}

pair<int,int> Commander_DB::get_id_of_free(Summary & s_param, Ticket_DB & ticket_db_param)
{
    pair<int,int> p_id;
    for (auto itr = List_Commander.begin(); itr != List_Commander.end(); itr++)
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

void Commander_DB::print()
{
    for (auto itr = List_Commander.begin(); itr!=List_Commander.end(); itr ++)
    {
        (*itr).print();
    }
}
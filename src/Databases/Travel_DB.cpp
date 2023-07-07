#include"Travel_DB.h"

void Travel_DB::Add_Travel(Travel & travel_param)
{
    List_Travel.push_back(travel_param);
}

void Travel_DB::Del_Travel(int travel_id_param)
{
    for (auto itr = List_Travel.begin(); itr != List_Travel.end(); itr++)
    {
        if ( (*itr).get_travel_id() == travel_id_param )
        {
            List_Travel.erase(itr);
            break;
        }
    }
}

Travel Travel_DB::get_Travel(int travel_id_param)
{
    Travel tr_temp(false);
    for (auto itr = List_Travel.begin(); itr != List_Travel.end(); itr++)
    {
        if ( (*itr).get_travel_id() == travel_id_param )
        {
            tr_temp =  *itr;
            break;
        }
    }
    return tr_temp;
}

void Travel_DB::print()
{
    for (auto itr = List_Travel.begin(); itr != List_Travel.end();  itr++)
    {
        (*itr).print_travel();
    }
}
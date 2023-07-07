#include"Travel_ID_Vacant_DB.h"

void Travel_ID_Vacant_DB::add_travel_id(int travel_id_param)
{
    List_Travel_ID.push_back(travel_id_param);
}

void Travel_ID_Vacant_DB::del_travel_id(int travel_id_param)
{
    for (auto itr = List_Travel_ID.begin(); itr != List_Travel_ID.end(); itr++)
    {
        if (*itr == travel_id_param)
        {
            List_Travel_ID.erase(itr);
            break;
        }
    }
}

bool Travel_ID_Vacant_DB::is_present(int ticket_id_param, Travel_DB & travel_db)
{
    bool flag = false;
    for (int travel_id_temp : List_Travel_ID)
    {
        Travel travel_temp(false);
        travel_temp = travel_db.get_Travel(travel_id_temp);
        if (travel_temp.is_present_ticket_id(ticket_id_param))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int Travel_ID_Vacant_DB::get_travel_id_for_ticket_id(int ticket_id_param, Travel_DB & travel_db)
{
    int travel_id_return;
    for (int travel_id_temp : List_Travel_ID)
    {
        Travel travel_temp(false);
        travel_temp = travel_db.get_Travel(travel_id_temp);
        if (travel_temp.is_present_ticket_id(ticket_id_param))
        {
            travel_id_return = travel_id_temp;
            break;
        }
    }
    return travel_id_return;
}

bool Travel_ID_Vacant_DB::is_going_any(Summary & s_param, Travel_DB & travel_db, Ticket_DB & ticket_db)
{
    bool flag = false;
    for (int travel_id_temp : List_Travel_ID)
    {
        Travel travel_temp(false);
        travel_temp = travel_db.get_Travel(travel_id_temp);
        if (travel_temp.is_going(s_param,ticket_db))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int Travel_ID_Vacant_DB::get_travel_id_going(Summary & s_param, Travel_DB & travel_db, Ticket_DB & ticket_db)
{
    int travel_id_return;
    for (int travel_id_temp : List_Travel_ID)
    {
        Travel travel_temp(false);
        travel_temp = travel_db.get_Travel(travel_id_temp);
        if (travel_temp.is_going(s_param,ticket_db))
        {
            travel_id_return = travel_id_temp;
            break;
        }
    }
    return travel_id_return;
}

void Travel_ID_Vacant_DB::print()
{
    for (int temp : List_Travel_ID)
    {
        cout<<"Ticket ID: "<<temp<<endl;
    }
}
#include"Passenger_DB.h"

void Passenger_DB::Add_Passenger(Passenger & passenger_param)
{
    List_Passenger.push_back(passenger_param);
}

void Passenger_DB::Del_Passenger(int traveller_id_param)
{
    for (auto itr = List_Passenger.begin(); itr != List_Passenger.end(); itr++)
    {
        if ( (*itr).get_traveller_id() == traveller_id_param )
        {
            List_Passenger.erase(itr);
            break;
        }
    }
}

Passenger Passenger_DB::get_Passenger(int traveller_id_param)
{
    Passenger passenger_temp(false,0);
    for (auto itr = List_Passenger.begin(); itr != List_Passenger.end(); itr++)
    {
        if ( (*itr).get_traveller_id() == traveller_id_param )
        {
            passenger_temp =  *itr;
            break;
        }
    }
    return passenger_temp;
}

void Passenger_DB::print()
{
    for (auto itr = List_Passenger.begin(); itr!=List_Passenger.end(); itr ++)
    {
        (*itr).print();
    }
}

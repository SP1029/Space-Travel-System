#include"Credentials_DB.h"

void Credentials_DB::Add(Credentials & c_param)
{
    List_Credentials.push_back(c_param);
}

bool Credentials_DB::is_valid(Credentials & c_param)
{
    bool flag = false;
    for (auto itr = List_Credentials.begin(); itr != List_Credentials.end(); itr++)
    {
        if (*itr == c_param)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int Credentials_DB::get_type(int traveller_id_param, string name_param)
{
    int type;
    for (auto itr = List_Credentials.begin(); itr != List_Credentials.end(); itr++)
    {
        if ((*itr).get_name() == name_param && (*itr).get_traveller_id() == traveller_id_param)
        {
            type = (*itr).get_type();
            break;
        }
    }
    return type;
}

void Credentials_DB::print()
{
    for (Credentials c_temp : List_Credentials)
    {
        c_temp.print();
    }
}
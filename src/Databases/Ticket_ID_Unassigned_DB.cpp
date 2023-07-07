#include"Ticket_ID_Unassigned_DB.h"
#include"Ticket.h"

void Ticket_ID_Unassigned_DB::add_ticket_id(int ticket_id_param)
{
    List_Ticket_ID.push_back(ticket_id_param);
}

void Ticket_ID_Unassigned_DB::del_ticket_id(int ticket_id_param)
{
    for (auto itr = List_Ticket_ID.begin();itr != List_Ticket_ID.end(); itr++)
    {
        if (*itr == ticket_id_param)
        {
            List_Ticket_ID.erase(itr);
            break;
        }
    }
}

int Ticket_ID_Unassigned_DB::count_going(Summary & s_param, Ticket_DB & ticket_db)
{
    int count = 0;
    for (int ticket_id_temp : List_Ticket_ID)
    {
        Summary s_param_junk;
        Ticket ticket_temp(false,s_param_junk);
        ticket_temp = ticket_db.get_Ticket(ticket_id_temp);
        if (ticket_temp.is_going(s_param))
        {
            count++;
        }
    }
    cout<<"We have got count as"<<count<<endl;
    return count;
}

bool Ticket_ID_Unassigned_DB::is_present(int ticket_id_param)
{
    bool flag = false;
    for (int ticket_id_temp : List_Ticket_ID)
    {
        if (ticket_id_param == ticket_id_temp)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void Ticket_ID_Unassigned_DB::load_list_going(list<int> &list_param, Summary & s_param, Ticket_DB & ticket_db)
{
    list_param.clear();
    for (int ticket_id_temp : List_Ticket_ID)
    {
        Summary s_param_junk;
        Ticket ticket_temp(false, s_param_junk);
        ticket_temp = ticket_db.get_Ticket(ticket_id_temp);
        if (ticket_temp.is_going(s_param))
        {
            list_param.push_back(ticket_temp.get_ticket_id());
        }
    }
}

void Ticket_ID_Unassigned_DB::print()
{
    for (int temp : List_Ticket_ID)
    {
        cout<<"Ticket ID: "<<temp<<endl;
    }
}

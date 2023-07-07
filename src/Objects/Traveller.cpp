#include"Traveller.h"

int Traveller::count = 0;

Traveller::Traveller(bool is_actual, int traveller_id_param)
{
    if (is_actual)
    {
        count++;
        traveller_id = traveller_id_param + count *10;
    }
}

int Traveller::get_traveller_id()
{
    return traveller_id;
}

string Traveller::get_name()
{
    return name;
}

void Traveller::set_name(string name_param)
{
    name = name_param;
}
void Traveller::add_ticket_id(int ticket_id_param)
{
    list_ticket_id.push_back(ticket_id_param);
}

void Traveller::del_ticket_id(int ticket_id_param)
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

bool Traveller::is_empty_list()
{
    return list_ticket_id.empty();
}

int Traveller::pop_back_list()
{
    int travel_id_temp;
    travel_id_temp = list_ticket_id.back();
    list_ticket_id.pop_back();
    return travel_id_temp;
}

void Traveller::print_tickets(Ticket_DB & ticket_db)
{
    Summary s_param_junk;
    Ticket t(false, s_param_junk);
    for (int temp : list_ticket_id)
    {
        t = ticket_db.get_Ticket(temp);
        t.print_ticket();
    }
}
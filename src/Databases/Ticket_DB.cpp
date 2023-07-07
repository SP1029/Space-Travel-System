#include"Ticket_DB.h"

void Ticket_DB::Add_Ticket(Ticket & ticket_param)
{
    List_Ticket.push_back(ticket_param);
}

void Ticket_DB::Del_Ticket(int ticket_id_param)
{
    for (auto itr = List_Ticket.begin(); itr != List_Ticket.end(); itr++)
    {
        if ( (*itr).get_ticket_id() == ticket_id_param )
        {
            List_Ticket.erase(itr);
            break;
        }
    }
}

Ticket Ticket_DB::get_Ticket(int ticket_id_param)
{
    Summary s_param_junk;
    Ticket a_temp(false,s_param_junk);
    for (auto itr = List_Ticket.begin(); itr != List_Ticket.end(); itr++)
    {
        if ( (*itr).get_ticket_id() == ticket_id_param )
        {
            a_temp =  *itr;
            break;
        }
    }
    return a_temp;
}

Ticket Ticket_DB::get_Ticket(int traveller_id_param, Summary & s_param)
{
    Summary s_param_junk;
    Ticket a_temp(false,s_param_junk);
    for (auto itr = List_Ticket.begin(); itr != List_Ticket.end(); itr++)
    {
        if ((*itr).is_his_ticket(s_param, traveller_id_param) )
        {
            a_temp = *itr;
            break;
        }
    }
    return a_temp;
}

void Ticket_DB::print()
{
    for (auto itr = List_Ticket.begin(); itr!=List_Ticket.end(); itr ++)
    {
        (*itr).print_ticket();
    }
}
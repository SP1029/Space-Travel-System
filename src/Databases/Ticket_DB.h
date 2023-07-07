#pragma once

#include"Ticket.h"
#include<list>

class Ticket_DB
{
private:
    list<Ticket> List_Ticket;

public:
    void Add_Ticket(Ticket & ticket_param);
    void Del_Ticket(int ticket_id_param);
    Ticket get_Ticket(int ticket_id_param);
    Ticket get_Ticket(int traveller_id_param, Summary & s_param);
    void print();
};
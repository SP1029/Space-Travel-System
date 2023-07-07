#pragma once

#include"Astronaut.h"
class Astronaut_DB
{
private:
    list<Astronaut> List_Astronaut;

public:
    void Add_Astronaut(Astronaut & a_param);
    void Del_Astronaut(int traveller_id_param);
    Astronaut get_astronaut(int traveller_id_param);
    bool is_free_any(Summary & s_param, Ticket_DB & ticket_db_param);
    pair<int,int> get_id_of_free(Summary & s_param, Ticket_DB & ticket_db_param); // traveller_id and license_id
    void print();
};
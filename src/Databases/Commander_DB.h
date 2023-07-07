#pragma once

#include"Commander.h"
class Commander_DB
{
private:
    list<Commander> List_Commander;

public:
    void Add_Commander(Commander & com_param);
    void Del_Commander(int traveller_id_param);
    Commander get_Commander(int traveller_id_param);
    bool is_free_any(Summary & s_param, Ticket_DB & ticket_db_param);
    pair<int,int> get_id_of_free(Summary & s_param, Ticket_DB & ticket_db_param); // traveller_id and license_id
    void print();
};
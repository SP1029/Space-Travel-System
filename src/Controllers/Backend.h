#pragma once

#include"Astronaut_DB.h"
#include"Commander_DB.h"
#include"Credentials_DB.h"
#include"Passenger_DB.h"
#include"Planet_DB.h"
#include"Summary.h"
#include"Ticket_DB.h"
#include"Ticket_ID_Unassigned_DB.h"
#include"Travel_DB.h"
#include"Travel_ID_Vacant_DB.h"
#include"Travel_ID_Full_DB.h"

class Backend
{
    public:
        Astronaut_DB astronaut_db;
        Commander_DB commander_db;
        Credentials_DB credentials_db;
        Passenger_DB passenger_db;
        Planet_DB planet_db;
        Ticket_DB ticket_db;
        Ticket_ID_Unassigned_DB ticket_id_unassigned_db;
        Travel_DB travel_db;
        Travel_ID_Vacant_DB travel_id_vacant_db;
        Travel_ID_Full_DB travel_id_full_db;

    public:
        bool Authorise(Credentials & c_param);
        void Book_Ticket(Summary & s_param, Credentials & c_param, bool is_return, Summary & s_return_param, int expiry_date);
        void Update_Ticket(Summary & s_old_param, Summary & s_new_param, Credentials & c_param);
        Ticket Delete_Ticket(Summary & s_param, Credentials & c_param);
        int Add_User(Credentials & c_param,int last, int experience);
};
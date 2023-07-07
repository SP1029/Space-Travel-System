#include"Backend.h"
#include<iostream>
using namespace std;
bool Backend::Authorise(Credentials & c_param)
{
    bool flag;
    flag = credentials_db.is_valid(c_param);
    return flag;
}

void Backend::Book_Ticket(Summary & s_param, Credentials & c_param, bool is_return, Summary & s_return_param, int expiry_date)
{
    if (is_return)
    {
        Book_Ticket(s_param,c_param,false,s_return_param,0);
        Book_Ticket(s_return_param,c_param,false,s_return_param,0);
    }
    else
    {
        int traveller_id;
        traveller_id = c_param.get_traveller_id();
        
        // Make Ticket and sort it
        Ticket ticket_book(true,s_param);
        ticket_book.set_traveller_id(traveller_id);
        ticket_db.Add_Ticket(ticket_book);
        if (expiry_date!=0)
        {
            ticket_book.set_expiry_date(expiry_date);
        }
        
        // Update Passenger
        Passenger passenger_book(false,0);
        passenger_book = passenger_db.get_Passenger(traveller_id);
        passenger_db.Del_Passenger(traveller_id);
        passenger_book.add_ticket_id(ticket_book.get_ticket_id());
        passenger_db.Add_Passenger(passenger_book);

        // Check for Travels
        if (travel_id_vacant_db.is_going_any(s_param,travel_db,ticket_db))
        {
            //  Sort the travel
            int travel_id_temp = travel_id_vacant_db.get_travel_id_going(s_param,travel_db,ticket_db);            
            Travel travel_temp(false);
            travel_temp = travel_db.get_Travel(travel_id_temp);
            travel_db.Del_Travel(travel_id_temp);
            travel_temp.add_ticket_id(ticket_book.get_ticket_id());
            travel_db.Add_Travel(travel_temp);

            if (travel_temp.is_full())
            {
                travel_id_vacant_db.del_travel_id(travel_temp.get_travel_id());
                travel_id_full_db.add_travel_id(travel_temp.get_travel_id());                
            }            
        }
        else
        {
            if(ticket_id_unassigned_db.count_going(s_param,ticket_db)==TRAVEL_MIN_CAPACITY-1)
            {
                if (astronaut_db.is_free_any(s_param, ticket_db) && commander_db.is_free_any(s_param,ticket_db))
                {                   
                    // Create New Travel
                    Travel travel_book(true);

                    // Get Astro and Com traveller_id and license_id
                    pair<int,int> p_astro_id = astronaut_db.get_id_of_free(s_param, ticket_db); 
                    pair<int,int> p_com_id = commander_db.get_id_of_free(s_param, ticket_db);

                    // Update Astro and Com DB
                    Astronaut a_temp(false,0);
                    Commander c_temp(false,0);
                    a_temp = astronaut_db.get_astronaut(p_astro_id.first);
                    c_temp = commander_db.get_Commander(p_com_id.first);
                    astronaut_db.Del_Astronaut(p_astro_id.first);
                    commander_db.Del_Commander(p_com_id.first);

                    Ticket ticket_a(true,s_param);
                    Ticket ticket_c(true,s_param);
                    ticket_a.set_traveller_id(p_astro_id.first);
                    ticket_c.set_traveller_id(p_com_id.first);

                    a_temp.add_ticket_id(ticket_a.get_ticket_id());
                    c_temp.add_ticket_id(ticket_c.get_ticket_id());

                    ticket_db.Add_Ticket(ticket_a);
                    ticket_db.Add_Ticket(ticket_c);

                    astronaut_db.Add_Astronaut(a_temp);
                    commander_db.Add_Commander(c_temp);
                    
                    // Set Ticket Details
                    travel_book.add_ticket_id(ticket_a.get_ticket_id());
                    travel_book.add_ticket_id(ticket_c.get_ticket_id());
                    travel_book.add_ticket_id(ticket_book.get_ticket_id());
                    list<int> ticket_id_to_make_travel;
                    ticket_id_unassigned_db.load_list_going(ticket_id_to_make_travel,s_param, ticket_db);
                    for (int ticket_id_temp : ticket_id_to_make_travel)
                    {
                        travel_book.add_ticket_id(ticket_id_temp);
                        ticket_id_unassigned_db.del_ticket_id(ticket_id_temp);
                    }
                    travel_book.set_astro_id(p_astro_id.second);
                    travel_book.set_com_id(p_com_id.second);

                    // Upadate Rest Logic
                    travel_db.Add_Travel(travel_book);
                    travel_id_vacant_db.add_travel_id(travel_book.get_travel_id());
                }
            }
            else
            {
                ticket_id_unassigned_db.add_ticket_id(ticket_book.get_ticket_id());
            }
        }
    }
}

void Backend::Update_Ticket(Summary & s_old_param, Summary & s_new_param, Credentials & c_param)
{
    Summary s_param_junk;
    Ticket ticket_old(false,s_param_junk);
    ticket_old = Delete_Ticket(s_old_param, c_param);
    Book_Ticket(s_new_param, c_param, false, s_new_param,ticket_old.get_expiry_date());
}

Ticket Backend::Delete_Ticket(Summary & s_param, Credentials & c_param)
{
    int traveller_id_my = c_param.get_traveller_id();

    // Get Ticket
    Summary s_param_junk;
    Ticket ticket_my(false,s_param_junk);
    ticket_my = ticket_db.get_Ticket(traveller_id_my,s_param);
    int ticket_id_my = ticket_my.get_ticket_id();
    ticket_db.Del_Ticket(ticket_id_my);

    // Get Passenger
    Passenger passenger_me(false,0);
    passenger_me = passenger_db.get_Passenger(traveller_id_my);
    passenger_db.Del_Passenger(traveller_id_my);

    // Update Passenger
    passenger_me.del_ticket_id(ticket_my.get_ticket_id());
    passenger_db.Add_Passenger(passenger_me);

    // Check Tickets and Travels
    if (travel_id_full_db.is_present(ticket_id_my, travel_db))
    {
        // Get and update my Travel
        int travel_id_my = travel_id_full_db.get_travel_id_for_ticket_id(ticket_id_my, travel_db);
        Travel travel_my(false);
        travel_my = travel_db.get_Travel(travel_id_my);
        travel_db.Del_Travel(travel_my.get_travel_id());
        travel_my.del_ticket_id(ticket_id_my);

        // Update All DB        
        travel_id_full_db.del_travel_id(travel_id_my);
        travel_id_vacant_db.add_travel_id(travel_id_my);                
        travel_db.Add_Travel(travel_my);
    }
    else if (travel_id_vacant_db.is_present(ticket_id_my, travel_db))
    {
        // Get and update my Travel
        int travel_id_my = travel_id_full_db.get_travel_id_for_ticket_id(ticket_id_my, travel_db);
        Travel travel_my(false);
        travel_my = travel_db.get_Travel(travel_id_my);
        travel_db.Del_Travel(travel_id_my);
        travel_my.del_ticket_id(ticket_id_my);

        if (travel_my.is_underfilled())
        {               
            // Set passengers
            while (travel_my.is_passenger_done_list()!=true)
            {
                int ticket_id_temp;
                ticket_id_temp = travel_my.pop_back_list();
                ticket_id_unassigned_db.add_ticket_id(ticket_id_temp);
            }

            // Set astro and com
            int ticket_id_com = travel_my.pop_back_list();
            int ticket_id_astro = travel_my.pop_back_list();
            Summary s_param_junk;
            Ticket ticket_a(false,s_param_junk);
            ticket_a = ticket_db.get_Ticket(ticket_id_astro);
            ticket_db.Del_Ticket(ticket_a.get_ticket_id());
            Ticket ticket_c(false,s_param_junk);
            ticket_c = ticket_db.get_Ticket(ticket_id_com);
            ticket_db.Del_Ticket(ticket_c.get_ticket_id());
            int traveller_id_a;
            traveller_id_a = ticket_a.get_traveller_id();
            int traveller_id_c;
            traveller_id_c = ticket_c.get_traveller_id();
            Astronaut a_temp(false,0);
            a_temp = astronaut_db.get_astronaut(traveller_id_a);
            astronaut_db.Del_Astronaut(traveller_id_a);
            Commander c_temp(false,0);
            c_temp = commander_db.get_Commander(traveller_id_c);
            commander_db.Del_Commander(traveller_id_c);

            a_temp.del_ticket_id(ticket_a.get_ticket_id());
            c_temp.del_ticket_id(ticket_c.get_ticket_id());
            astronaut_db.Add_Astronaut(a_temp);
            commander_db.Add_Commander(c_temp);
        }
        else
        {
            travel_db.Add_Travel(travel_my);
        }
    }
    else
    {
        ticket_id_unassigned_db.del_ticket_id(ticket_id_my);
    }
    return ticket_my;
}

int Backend::Add_User(Credentials & c_param,int last, int experience)
{
    int traveller_id_his;
    switch (c_param.get_type())
    {
        case -1:
        {
            credentials_db.Add(c_param);
            return c_param.get_traveller_id();
        }
        case PASS_TYPE:
        {
            Passenger p(true, last); 
            traveller_id_his = p.get_traveller_id();
            p.set_name(c_param.get_name());
            c_param.set_traveller_id(p.get_traveller_id());
            passenger_db.Add_Passenger(p);    
            credentials_db.Add(c_param);
            return c_param.get_traveller_id();
        }
        case ASTRO_TYPE:
        {
            Astronaut a(true, last);
            traveller_id_his = a.get_traveller_id();
            a.set_name(c_param.get_name());
            a.set_experience(experience);
            astronaut_db.Add_Astronaut(a);
            c_param.set_traveller_id(a.get_traveller_id());
            credentials_db.Add(c_param);
            return c_param.get_traveller_id();
        }
        case COM_TYPE:
        {
            Commander c(true, last);
            traveller_id_his = c.get_traveller_id();
            c.set_name(c_param.get_name());
            c_param.set_traveller_id(c.get_traveller_id());
            commander_db.Add_Commander(c);
            credentials_db.Add(c_param);
            return c_param.get_traveller_id();
        }
    }
    
}

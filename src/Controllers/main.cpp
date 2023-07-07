#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"Backend.h"
using namespace std;

int main()
{
    // Intro Message
    cout<<"//////////////////////////////////////////"<<endl;
    cout<<"///// Welcome to Space Travel System /////"<<endl;
    cout<<"//////////////////////////////////////////"<<endl<<endl;

    // Basic Structures
    Backend backend;

    // Adding Admin Login to create users
    Credentials c_admin;
    c_admin.set_name("admin");
    c_admin.set_traveller_id(-1);
    c_admin.set_type(-1);
    backend.Add_User(c_admin,0,0);
    bool flag = true;
    Credentials c_user;
    string user_name;
    int user_traveller_id;
    cout<<"Following is the details of the Admin"<<endl;
    backend.credentials_db.print();
    cout<<endl<<"Currently there are no users registered except the Admin"<<endl;
    cout<<"The admin can create accounts for Astronauts, Commanders and Travellers"<<endl;
    cout<<"The admin will also have to create Planets present in the Universe"<<endl<<endl;    

    // Start of infinite loop
    while (flag==true)
    {
        // Authorise
        cout<<"///////////"<<endl;
        cout<<"// Login //"<<endl;
        cout<<"///////////"<<endl;
        cout<<"Enter Your Traveller_id: ";
        cin>>user_traveller_id;
        c_user.set_traveller_id(user_traveller_id);
        cout<<"Enter Your First Name: ";
        cin>>user_name;
        c_user.set_name(user_name);

        if (backend.Authorise(c_user))
        {
            cout<<"Log in Successful"<<endl;
            int type = backend.credentials_db.get_type(user_traveller_id, user_name);
            switch (type)
            {
                case -1: // admin is to add users
                {
                    cout<<"///////////"<<endl;
                    cout<<"// Admin //"<<endl;
                    cout<<"///////////"<<endl;
                    int x;
                    cout<<"Enter 0 to logout"<<endl<<"Enter 1 to add Planet"<<endl<<"Enter 2 to add User"<<endl;
                    cin>>x;
                    switch (x)
                    {
                        case 2:
                        {
                            // Read the User Details

                            Credentials c_user_temp;
                            string user_name_temp;
                            int last;
                            cout<<"Enter User's First Name : ";
                            cin>>user_name_temp;
                            c_user_temp.set_name(user_name_temp);
            USER_ID_SET:    cout<<"Select a Last digit for the user's Traveller_id : ";
                            cin>>last;
                            if (!(last>=0 && last<10))
                            {
                                cout<<"Error in the input. Please enter a digit from 0 to 9."<<endl;
                                goto USER_ID_SET;
                            }
                            c_user_temp.set_traveller_id(last);
                            cout<<"Enter User Type (1 is Passenger, 2 is Astronaut and 3 is Commander): ";
                            int temp;
                            cin>>temp;
                            c_user_temp.set_type(temp);
                            int experience = 0;
                            if (temp==2)
                            {
                                cout<<"Enter Astronaut's Year's of Experience : ";
                                cin>>experience;
                            }
                            cout<<endl;

                            // Add the User

                            temp = backend.Add_User(c_user_temp, last, experience);
                            cout<<temp<<" is the unique Traveller ID assigned to the user"<<endl;
                            
                            // Check DB Status

                            cout<<"All DBs Status"<<endl;
                            cout<<"Passenger DB"<<endl;
                            backend.passenger_db.print();
                            cout<<"Astronaut DB"<<endl;
                            backend.astronaut_db.print();
                            cout<<"Commander DB"<<endl;
                            backend.commander_db.print();
                            cout<<"Credentials DB"<<endl;
                            backend.credentials_db.print();
                            cout<<endl;
                            break;
                        }
                        case 1:
                        {
                            // Read Planet Details
                            Planet p(true);
                            string name;
                            int x,y,z;
                            cout<<"Enter the Planet's Name: ";
                            cin>>name;
                            cout<<"Enter the Planet's X co-ordinate: ";
                            cin>>x;
                            cout<<"Enter the Planet's Y co-ordinate: ";
                            cin>>y;
                            cout<<"Enter the Planet's Z co-ordinate: ";
                            cin>>z;
                            cout<<endl;

                            // Add Planet to DB
                            p.set_name(name);
                            p.set_x(x);
                            p.set_y(y);
                            p.set_z(z);
                            backend.planet_db.Add_Planet(p);

                            // DB Status
                            backend.planet_db.print();
                            cout<<endl;
                            break;
                        }   

                    }                    
                    break;
                }

                case PASS_TYPE: 
                {   

                    cout<<"///////////////"<<endl;
                    cout<<"// Traveller //"<<endl;
                    cout<<"///////////////"<<endl;
    USER_ACTION_SET:cout<<"Enter Function Code you want to perform"<<endl;
                    cout<<"1 - Book a Ticket"<<endl;
                    cout<<"2 - Update a Ticket"<<endl;
                    cout<<"3 - Delete a Ticket"<<endl;
                    cout<<"4 - View My Tickets"<<endl;
                    cout<<"Function Code: ";
                    int x;
                    cin>>x;
                    if (!(x>=1 && x<5))
                    {
                        cout<<"Error in the input. Please enter a digit from 1 to 4."<<endl;
                        goto USER_ACTION_SET;
                    }
                    switch (x)
                    {
                        case 1:
                        {
                            // Get Info from User
                            int date;
                            int d,m,y;
                            int source_id;
                            int dest_id;
                            cout<<"Enter date in DD MM YYYY form: ";
                            cin>>d;
                            cin>>m;
                            cin>>y;
                            date = d + m * 32 + y * 13 * 32; // Storing Date as int
                            cout<<"Enter Source Planet Name: ";
                            string source;
                            cin>>source;
                            cout<<"Enter Destination Planet Name: ";
                            string dest;                            
                            cin>>dest;
                            Summary s_temp;
                            s_temp.set_date(date);
                            s_temp.set_dest_id(backend.planet_db.get_planet_id(dest));
                            s_temp.set_source_id(backend.planet_db.get_planet_id(source));

                            // Set return ticket details
                            bool ret;
                            int ret_temp;
                            cout<<"Do you want Return Ticket (Reply in 0/1): ";
                            cin>>ret_temp;
                            ret = ret_temp;
                            int ret_date;
                            if (ret)
                            {
                                cin>>d;
                                cin>>m;
                                cin>>y;
                                cout<<"Enter the Return Date in DD MM YYYY form";
                                ret_date = d + m * 32 + y * 13 * 32;;
                            }                            
                            Summary s_ret = s_temp;
                            s_ret.set_date(ret_date);
                            cout<<endl;

                            // Book Ticket
                            backend.Book_Ticket(s_temp,c_user,ret,s_ret,0);

                            // Check DB Status
                            cout<<"Ticket DB"<<endl;
                            backend.ticket_db.print();
                            cout<<"Travel DB"<<endl;
                            backend.travel_db.print();
                            cout<<"Ticket ID Unassigned DB"<<endl;
                            backend.ticket_id_unassigned_db.print();
                            cout<<"Travel ID Vacant DB"<<endl;
                            backend.travel_id_vacant_db.print();
                            cout<<"Travel ID Full DB"<<endl;
                            backend.travel_id_full_db.print();
                            cout<<endl;
                            
                            break;
                        }
                        case 2:
                        {
                            // Get Info from User Old
                            int date;
                            int d,m,y;
                            int source_id;
                            int dest_id;
                            cout<<"Enter date in DD MM YYYY form: ";
                            cin>>d;
                            cin>>m;
                            cin>>y;
                            date = d + m * 32 + y * 13 * 32; // Storing Date as int
                            cout<<"Enter Source Planet Name: ";
                            string source;
                            cin>>source;
                            cout<<"Enter Destination Planet Name: ";
                            string dest;                            
                            cin>>dest;
                            Summary s_temp;
                            s_temp.set_date(date);
                            s_temp.set_dest_id(backend.planet_db.get_planet_id(dest));
                            s_temp.set_source_id(backend.planet_db.get_planet_id(source));
                            
                            // Info new
                            cout<<"Enter date in DD MM YYYY form: ";
                            cin>>d;
                            cin>>m;
                            cin>>y;
                            date = d + m * 32 + y * 13 * 32; // Storing Date as int
                            cout<<"Enter Source Planet Name: ";
                            cin>>source;
                            cout<<"Enter Destination Planet Name: ";                            
                            cin>>dest;
                            Summary s_temp_new;
                            s_temp_new.set_date(date);
                            s_temp_new.set_dest_id(backend.planet_db.get_planet_id(dest));
                            s_temp_new.set_source_id(backend.planet_db.get_planet_id(source));

                            // Update
                            backend.Update_Ticket(s_temp,s_temp_new,c_user);

                            // Check DB Status
                            cout<<"Ticket DB"<<endl;
                            backend.ticket_db.print();
                            cout<<"Travel DB"<<endl;
                            backend.travel_db.print();
                            cout<<"Ticket ID Unassigned DB"<<endl;
                            backend.ticket_id_unassigned_db.print();
                            cout<<"Travel ID Vacant DB"<<endl;
                            backend.travel_id_vacant_db.print();
                            cout<<"Travel ID Full DB"<<endl;
                            backend.travel_id_full_db.print();
                            cout<<endl;

                            break;
                        }
                        case 3:
                        {
                            // Get Info from User Old
                            int date;
                            int d,m,y;
                            int source_id;
                            int dest_id;
                            cout<<"Enter date in DD MM YYYY form: ";
                            cin>>d;
                            cin>>m;
                            cin>>y;
                            date = d + m * 32 + y * 13 * 32; // Storing Date as int
                            cout<<"Enter Source Planet Name: ";
                            string source;
                            cin>>source;
                            cout<<"Enter Destination Planet Name: ";
                            string dest;                            
                            cin>>dest;
                            Summary s_temp;
                            s_temp.set_date(date);
                            s_temp.set_dest_id(backend.planet_db.get_planet_id(dest));
                            s_temp.set_source_id(backend.planet_db.get_planet_id(source));

                            // Delete
                            backend.Delete_Ticket(s_temp,c_user);

                            // Check DB Status
                            cout<<"Ticket DB"<<endl;
                            backend.ticket_db.print();
                            cout<<"Travel DB"<<endl;
                            backend.travel_db.print();
                            cout<<"Ticket ID Unassigned DB"<<endl;
                            backend.ticket_id_unassigned_db.print();
                            cout<<"Travel ID Vacant DB"<<endl;
                            backend.travel_id_vacant_db.print();
                            cout<<"Travel ID Full DB"<<endl;
                            backend.travel_id_full_db.print();
                            cout<<endl;
                            break;
                        }
                        case 4:
                        {
                            int traveller_id = c_user.get_traveller_id();
                            Passenger passenger_temp(false,0);
                            passenger_temp = backend.passenger_db.get_Passenger(traveller_id);
                            cout<<"Your Tickets Are:"<<endl;
                            passenger_temp.print_tickets(backend.ticket_db);
                            cout<<endl;
                            
                            break;
                        }          
                    }
                    break;
                }

                case ASTRO_TYPE: 
                {
                    cout<<"///////////////"<<endl;
                    cout<<"// Astronaut //"<<endl;
                    cout<<"///////////////"<<endl;
                    cout<<"Do you want to view your upcoming Tickets (Type 0 or 1)"<<endl;
                    int temp;
                    cin>>temp;
                    if (temp)
                    {
                        int traveller_id = c_user.get_traveller_id();
                        Astronaut a_temp(false,0);
                        a_temp = backend.astronaut_db.get_astronaut(traveller_id);
                        cout<<"Your Tickets Are:"<<endl;
                        a_temp.print_tickets(backend.ticket_db);
                        cout<<endl;                        
                    }

                    break;
                }

                case COM_TYPE: 
                {
                    cout<<"///////////////"<<endl;
                    cout<<"// Commander //"<<endl;
                    cout<<"///////////////"<<endl;
                    cout<<"Do you want to view your upcoming Tickets (Type 0 or 1)"<<endl;
                    int temp;
                    cin>>temp;
                    if (temp)
                    {
                        int traveller_id = c_user.get_traveller_id();
                        Commander c_temp(false,0);
                        c_temp = backend.commander_db.get_Commander(traveller_id);
                        cout<<"Your Tickets Are:"<<endl;
                        c_temp.print_tickets(backend.ticket_db);
                        cout<<endl;                        
                    }
                    break;
                }
            }
        }
        else
        {
            cout<<"Invalid User Credentials"<<endl;
        }
        cout<<"Want to Close the Application (Enter 0 or 1):";
        int x;
        cin>>x;
        if (x==1)
        {
            flag = false;
        }
        cout<<"Press ENTER to Proceed"<<endl;
        string dump;
        getline(cin,dump);
        // getch();
    }
}
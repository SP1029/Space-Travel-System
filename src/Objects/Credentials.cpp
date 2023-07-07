#include"Credentials.h"

int Credentials::get_traveller_id()
{
    return traveller_id;
}

void Credentials::set_traveller_id(int traveller_id_param)
{
    traveller_id = traveller_id_param;
}

int Credentials::get_type()
{
    return type;
}

void Credentials::set_type(int type_param)
{
    type = type_param;
}

string Credentials::get_name()
{
    return name;
}

void Credentials::set_name(string name_param)
{
    name = name_param;
}

bool Credentials::operator == (Credentials & c_param)
{
    bool flag = true;
    if (traveller_id!=c_param.get_traveller_id()) flag = false;
    if (name!=c_param.get_name()) flag = false;
    return flag;
}
void Credentials::print()
{
    cout<<"Traveller ID: "<<traveller_id<<" ";
    cout<<"First Name: "<<name<<" ";
    cout<<"Type: ";
    switch (type)
    {
        case PASS_TYPE:
            cout<<"Passenger"<<endl;
            break;
        
        case ASTRO_TYPE:
            cout<<"Astronaut"<<endl;
            break;

        case COM_TYPE:  
            cout<<"Commander"<<endl;
            break;
        case -1:
            cout<<"Admin"<<endl;
            break;
    }
}
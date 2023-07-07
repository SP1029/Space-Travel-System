#include"math.h"
#include"Ticket.h"

int Ticket::count = 0;

int Ticket::days_between(int date1, int date2)
{
    if (date1<date2)
    {
        int temp;
        date1 = temp;
        temp = date2;
        date2 = date1;
    }
    // date1>=date2
    return date1 - date2;
}

int Ticket::date_today()
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    int expiry_date = t.tm_mday + (t.tm_mon+1) * 32 + (t.tm_year + 10) * 32 * 13;
    int date = t.tm_mday + (t.tm_mon+1) * 32 + (t.tm_year + 0) * 32 * 13;
    return date;
}

Ticket::Ticket(bool is_actual, Summary & s_param)
{
    if (is_actual)
    {
        count++;
        ticket_id = count;
        expiry_date = s_param.get_date() + 32*13*10;
        price = (float) 1000000 / (days_between(date_today(),s_param.get_date()) + 10);
        summary = s_param;
    }
}

int Ticket::get_ticket_id()
{
    return ticket_id;
}

int Ticket::get_traveller_id()
{
    return traveller_id;
}

void Ticket::set_traveller_id(int traveller_id_param)
{
    traveller_id = traveller_id_param;
}

Summary Ticket::get_summary()
{
    return summary;
}

bool Ticket::is_going(Summary &s_param)
{
    if (summary == s_param)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ticket::is_his_ticket(Summary s_param, int traveller_id_param)
{
    if (summary == s_param && traveller_id ==  traveller_id_param)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Ticket::get_price()
{
    return price;
}

void Ticket::set_expiry_date(int set_expiry_date_param)
{
    expiry_date = set_expiry_date_param;
}

int Ticket::get_expiry_date()
{
    return expiry_date;
}

void Ticket::print_date(int date_param)
{
    int y;
    int m;
    int d;
    d = date_param%32;
    m = (date_param%(32*13))/32;
    y = date_param/(32*13);
    cout<<d<<"/"<<m<<"/"<<y;
}

void Ticket::print_ticket()
{
    cout<<"Ticket_ID: "<<ticket_id<<" ";
    cout<<"Traveller ID: "<<traveller_id<<" ";
    cout<<"Date: ";
    print_date(summary.get_date());
    cout<<"Source_ID"<<summary.get_source_id()<<" ";
    cout<<"Dest_ID"<<summary.get_dest_id()<<" ";
    cout<<"Price: "<<price<<" ";
    cout<<"Expiry Date: ";
    print_date(expiry_date);
    cout<<endl;
}
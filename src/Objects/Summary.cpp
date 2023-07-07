#include"Summary.h"

int Summary::get_date()
{
    return date;
}

void Summary::set_date(int date_param)
{
    date = date_param;
}

int Summary::get_source_id()
{
    return source_id;
}

void Summary::set_source_id(int source_id_param)
{
    source_id = source_id_param;
}

int Summary::get_dest_id()
{
    return dest_id;
}

void Summary::set_dest_id(int dest_id_param)
{
    dest_id = dest_id_param;
}

bool Summary::operator == (Summary & s_param)
{
    bool flag = true;
    if (date!=s_param.get_date()) flag = false;
    if (source_id!=s_param.get_source_id()) flag = false;
    if (dest_id!=s_param.get_dest_id()) flag = false;
    return flag;
}
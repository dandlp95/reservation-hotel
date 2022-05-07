#pragma once
#ifndef reservation_h
#define reservation_h

#include "Customer.h"
using namespace std;
#include <string>;
#include <array>

class Reservation
{
	private:
		// Private attributes
		string start_date;
		string end_date;
		string room;
		string guest_number;
		
		// Private method(s)

	public:
		Reservation(string start_date, string end_date, string room, string guest_number);
		Reservation(string start_date, string end_date, string room);
		array<string, 4> get_reservation_info() const;


};

#endif 


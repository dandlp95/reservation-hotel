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
		// Information will use to store under the client's reservation
		string start_date;
		string end_date;
		string room;
		string guest_number;
		
	public:
		
		Reservation(string start_date, string end_date, string room, string guest_number);
		Reservation(string start_date, string end_date, string room); // Guest number is an optional parameter, sets to 1 by default.
		array<string, 4> get_reservation_info() const;


};

#endif 


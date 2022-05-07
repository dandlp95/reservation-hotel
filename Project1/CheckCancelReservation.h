#pragma once
#ifndef checkcancelreservation_h
#define checkcancelreservation_h
using namespace std;
#include "Customer.h";

#include "json.hpp";


class CheckCancelReservation
{
	public:
		const Customer& customer;
		// The 3 methods below are bool because return 1 or 0, depending on whether they worked as intended or not. 
		bool check_in();
		bool cancel_reservation();
		bool check_out();
		CheckCancelReservation(const Customer& client);

};

#endif

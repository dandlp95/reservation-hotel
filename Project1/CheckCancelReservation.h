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
		bool check_in();
		bool cancel_reservation();
		bool check_out();
		CheckCancelReservation(const Customer& client);

};

#endif

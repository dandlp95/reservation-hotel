#pragma once
#ifndef reservationmanager_h
#define	reservationmanager_h
#include "Reservation.h"
#include "Customer.h"
#include <string>

using namespace std;

class ReservationManager
{
	private:
	const Reservation& client_reservation;
	const Customer& client;

	public:
		ReservationManager(const Customer& client, const Reservation& client_reservation); // To store the reservation, we need both the client's and reservantion's info to store it.

		void make_reservation();

};

#endif
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
		ReservationManager(const Customer& client, const Reservation& client_reservation);
		void make_reservation();

};

#endif
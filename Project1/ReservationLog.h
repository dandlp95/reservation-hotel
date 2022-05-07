#pragma once
#pragma once
#ifndef reservationlog_h
#define reservationlog_h
#include "reservation.h"

using namespace std;

class ReservationLog
{
	private:
		const Reservation& client_reservation;

	public:
		ReservationLog(const Reservation& client_reservation, string file_path);
		void reserve();
		void cancel();
		void check_in();
};

#endif 
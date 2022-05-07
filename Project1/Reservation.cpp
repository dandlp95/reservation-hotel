#include "Reservation.h"
using namespace std;
#include <string>

Reservation::Reservation(string start_date, string end_date, string room, string guest_number) :
	start_date{ start_date }, end_date{ end_date }, room{ room }, guest_number{ guest_number }{}

Reservation::Reservation(string start_date, string end_date, string room) :
	start_date{ start_date }, end_date{ end_date }, room{ room }, guest_number{ "1"}{}


array<string, 4> Reservation::get_reservation_info() const {

	array<string, 4> reservation_info= { start_date, end_date, room, guest_number };
	
	return reservation_info;
}








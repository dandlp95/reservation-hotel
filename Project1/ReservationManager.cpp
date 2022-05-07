#include <iostream>
#include "ReservationManager.h"
#include <string>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

ReservationManager::ReservationManager(const Customer& client, const Reservation& client_reservation) : client{ client }, client_reservation{ client_reservation }{};


void ReservationManager::make_reservation() {

	array<string, 3> client_info = client.get_customer_info();

	string client_name = client_info[0];
	string credit_card = client_info[1];
	string address = client_info[2];

	array<string, 4> reservation_info = client_reservation.get_reservation_info();

	string start_date = reservation_info[0];
	string end_date = reservation_info[1];
	string room = reservation_info[2];
	string guest_number = reservation_info[3];

	json reservation = {
		{"client", {
			{"name", client_name},
			{"address", address},
			{"creditCard", credit_card}
			}},
		{"reservation", {
			{"startDate", start_date},
			{"endDate", end_date},
			{"guests", guest_number},
			{"room", room},
			{"reservationStatus", "waiting"}
		}}
	};

	ifstream ifs("reservation.json");
	json reservation_db = json::parse(ifs);

	int db_size = reservation_db["reservations"].size();
	
	// we dont need to add +1 to db_size because the index starts at 0, so size works perfect.
	reservation_db["reservations"][db_size] = reservation;

	std::ofstream f("reservation.json");
	f << std::setw(4) << reservation_db << std::endl;
}

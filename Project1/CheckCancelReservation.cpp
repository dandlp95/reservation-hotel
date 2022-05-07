#include "CheckCancelReservation.h"
#include <string>
#include <array>
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

CheckCancelReservation::CheckCancelReservation(const Customer& customer) : customer{ customer } {};

bool CheckCancelReservation::check_in(){

	array<string, 3> customer_info = customer.get_customer_info();
	const string name = customer_info[0];
	const string credit_card = customer_info[1];
	const string address = customer_info[2];

	ifstream ifs("reservation.json");
	json reservation_db = json::parse(ifs);

	int size = reservation_db["reservations"].size();

	for (int i = 0; i < size; i++) {

		if (reservation_db["reservations"][i]["client"]["name"] == name && reservation_db["reservations"][i]["client"]["address"] == address
			&& reservation_db["reservations"][i]["client"]["creditCard"] == credit_card) {

			reservation_db["reservations"][i]["reservation"]["reservationStatus"] = "checked in";

			ofstream f("reservation.json");
			f << setw(4) << reservation_db << endl;

			return true;
		};

	}
	
	return false;
		
}

bool CheckCancelReservation::cancel_reservation() {

	array<string, 3> customer_info = customer.get_customer_info();
	const string name = customer_info[0];
	const string credit_card = customer_info[1];
	const string address = customer_info[2];

	ifstream ifs("reservation.json");
	json reservation_db = json::parse(ifs);

	int size = reservation_db["reservations"].size();

	for (int i = 0; i < size; i++) {

		if (reservation_db["reservations"][i]["client"]["name"] == name && reservation_db["reservations"][i]["client"]["address"] == address
			&& reservation_db["reservations"][i]["client"]["creditCard"] == credit_card) {

			reservation_db["reservations"][i]["reservation"]["reservationStatus"] = "cancelled";

			ofstream f("reservation.json");
			f << setw(4) << reservation_db << endl;

			return true;
		};

	}

	return false;



}

bool CheckCancelReservation::check_out() {

	array<string, 3> customer_info = customer.get_customer_info();
	const string name = customer_info[0];
	const string credit_card = customer_info[1];
	const string address = customer_info[2];

	ifstream ifs("reservation.json");
	json reservation_db = json::parse(ifs);

	int size = reservation_db["reservations"].size();

	for (int i = 0; i < size; i++) {

		if (reservation_db["reservations"][i]["client"]["name"] == name && reservation_db["reservations"][i]["client"]["address"] == address
			&& reservation_db["reservations"][i]["client"]["creditCard"] == credit_card) {

			reservation_db["reservations"][i]["reservation"]["reservationStatus"] = "checked out";

			ofstream f("reservation.json");
			f << setw(4) << reservation_db << endl;

			return true;
		};

	}

	return false;

}




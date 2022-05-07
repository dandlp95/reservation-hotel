#include "CheckCancelReservation.h"
#include <string>
#include <array>
#include "json.hpp" // This is the nholmann's library. Helps with working with json. 
#include <fstream>

using namespace std;
using json = nlohmann::json;

CheckCancelReservation::CheckCancelReservation(const Customer& customer) : customer{ customer } {};

bool CheckCancelReservation::check_in(){

	array<string, 3> customer_info = customer.get_customer_info();
	const string name = customer_info[0];
	const string credit_card = customer_info[1];
	const string address = customer_info[2];

	ifstream ifs("reservation.json"); // Reads from specified file
	json reservation_db = json::parse(ifs); // Stores json in reservation_db

	int size = reservation_db["reservations"].size(); // We use the size for for loop. 

	for (int i = 0; i < size; i++) {

		if (reservation_db["reservations"][i]["client"]["name"] == name && reservation_db["reservations"][i]["client"]["address"] == address /*If the information from the customer and reservation matches
																																			 the check in goes through.*/
			&& reservation_db["reservations"][i]["client"]["creditCard"] == credit_card) {

			reservation_db["reservations"][i]["reservation"]["reservationStatus"] = "checked in"; // We changed the reservationStatus key from the json file to checked in

			ofstream f("reservation.json"); 
			f << setw(4) << reservation_db << endl; // Saves it back to the json file. 

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

		if (reservation_db["reservations"][i]["client"]["name"] == name && reservation_db["reservations"][i]["client"]["address"] == address /*If the information of the customer and reservation
																																			 matches, cancel reservation goes through*/
			&& reservation_db["reservations"][i]["client"]["creditCard"] == credit_card) {

			reservation_db["reservations"][i]["reservation"]["reservationStatus"] = "cancelled"; // We alter the value of the reservtionStatus to cancelled.

			ofstream f("reservation.json");
			f << setw(4) << reservation_db << endl; // Saves it back to the file. 

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




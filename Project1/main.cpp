#include <iostream>
#include "Customer.h"
#include "Reservation.h"
#include "ReservationManager.h"
#include "CheckCancelReservation.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

int main() {

	bool client_menu = true;
	while (client_menu) {

		int option;

		cout << "Welcome to C++ Hotel! Please pick an option: " << endl;
		cout << "1. Make a Reservation " << endl;
		cout << "2. Check in" << endl;
		cout << "3. Check out" << endl;
		cout << "4. Cancel Reservation" << endl;
		cout << "5. Exit" << endl << endl;

		cout << "Enter a number (1-4): ";
		cin >> option;
		cout << endl;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (1 <= option && option < 5) {

			string name;
			cout << "Enter your full name: ";
			getline(cin, name);
			
			string address;
			cout << "Enter your address: ";
			getline(cin, address);
			
			string credit_card;
			cout << "Enter your credit card number: ";
			getline(cin, credit_card);

			Customer client(name, credit_card, address);

			if (option == 1) {
				
				string start_date;
				cout << "When will you be checking in with us? (Enter date format: mm-dd-yyy) ";
				cin >> start_date; 
				cout << endl;

				string end_date;
				cout << "When will you be checking out? (Enter date format: mm-dd-yyy) ";
				cin >> end_date;
				cout << endl;

				string room;
				cout << "In which room will you be staying? ";
				cin >> room;
				cout << endl;

				string guests;
				cout << "How many guests? ";
				cin >> room;
				cout << endl;

				Reservation client_reservation(start_date, end_date, room, guests);

				ReservationManager reservation(client, client_reservation);

				reservation.make_reservation();

				cout << "Thank you " + client.get_customer_info()[0] + ". Your reservation has been made for "
					+ client_reservation.get_reservation_info()[0] << endl;

			}

			else if (option == 2) {

				CheckCancelReservation checkin(client);

				if (checkin.check_in()) { cout << "You are checked in. Enjoy your stay! " << endl; }
				else { cout << "Sorry, we could not check out in." << endl; };

			}

			else if (option == 3) {

				CheckCancelReservation checkout(client);

				if (checkout.check_out()) { cout << "You are checked out. Thank you for staying with us! " << endl; }
				else { cout << "Sorry, we could not check out your reservation." << endl; };
				
			}
			else if (option == 4) {

				CheckCancelReservation cancel(client);

				if (cancel.cancel_reservation()) { cout << "Your reservation has been cancelled." << endl; }
				else { cout << "Sorry, we could not cancel your reservation." << endl; };
			
			}
		}
		else if (option == 5) {

			cout << "Goodbye. " << endl;
			client_menu = false;
		}
		else {
			cout << "this is not a valid option" << endl;
		}
	}

}

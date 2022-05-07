#pragma once
#ifndef customer_h
#define customer_h
#include <string>
#include <array>
using namespace std;

class Customer
{
	private:
		// Information we'll store for the client for check in purposes and correctly
		// identify their reservation.
		string name;
		string credit_card;
		string address;

	public:
		Customer(string name, string credit_card, string address);
		array<string, 3> get_customer_info() const;
};

#endif

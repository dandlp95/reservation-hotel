#pragma once
#ifndef customer_h
#define customer_h
#include <string>
#include <array>
using namespace std;

class Customer
{
	private:
		string name;
		string credit_card;
		string address;

	public:
		Customer(string name, string credit_card, string address);
		array<string, 3> get_customer_info() const;
};

#endif

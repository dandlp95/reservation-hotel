#include "Customer.h"
#include <string>
using namespace std;

Customer::Customer(string name, string credit_card, string address) :
	name{ name }, credit_card{ credit_card }, address{ address } {}

array <string, 3> Customer::get_customer_info()const {
	
	array <string, 3> customer_inf = { name, credit_card, address };

	return customer_inf;
}

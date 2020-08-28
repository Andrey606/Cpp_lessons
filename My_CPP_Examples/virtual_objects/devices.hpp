#pragma once

#include <iostream>

using namespace std;

class Base_device
{
	public:
		Base_device();

		void get_mac(void);
		

	private:
		uint64_t mac;
};
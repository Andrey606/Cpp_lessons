#pragma once

#include <iostream>

class Base_device
{
	public:
		enum class eCommand: uint8_t {UNDEFINED, ON, OFF, OPEN, CLOSE};

		Base_device():Command(eCommand::UNDEFINED){};
		~Base_device();

		uint64_t get_mac(void);
		void set_mac(uint64_t mac);
		
		void set_command(eCommand cmd);
		virtual void set_command_proccesing() = 0;
		
		virtual eCommand get_command(void) = 0;

	private:
		uint64_t mac;
		eCommand Command;
};

class Intercom: public Base_device 
{
	private:
		
	public:
		Intercom(){};
		~Intercom();
		
		void set_command_proccesing(void) override;
		Base_device::eCommand get_command(void) override;
};

class Curtain: public Base_device 
{
	private:

	public:
		Curtain(){};
		~Curtain();
		
		void set_command_proccesing(void) override;
		Base_device::eCommand get_command(void) override;
};
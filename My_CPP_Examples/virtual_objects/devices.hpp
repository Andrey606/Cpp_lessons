#pragma once

#include <iostream>

class Base_device
{
	public:
		enum class eCommand: uint8_t {UNDEFINED, ON, OFF, OPEN, CLOSE};

		Base_device():Command(eCommand::UNDEFINED){};
		virtual ~Base_device()  = default;

		uint64_t get_mac(void);
		void set_mac(uint64_t mac);
		
		void set_command(eCommand cmd);
		virtual void set_command_proccesing() = 0;
		
		Base_device::eCommand get_command(void);

	private:
		uint64_t mac;
		eCommand Command;
};

class Intercom: public Base_device 
{
	private:
		void set_command_proccesing(void) override;
		
	public:
		Intercom(){};
		~Intercom() = default;	
};

class Curtain: public Base_device 
{
	private:
		void set_command_proccesing(void) override;

	public:
		Curtain(){};
		~Curtain() = default;	
};
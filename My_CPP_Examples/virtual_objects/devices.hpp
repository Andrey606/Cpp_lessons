#pragma once

#include <iostream>

class Base_device
{
	public:
		Base_device();
		~Base_device();

		uint64_t get_mac(void);
		void set_mac(uint64_t mac);
		
		virtual void set_command(int cmd) = 0;
		virtual int get_command(void) = 0;
	private:
		uint64_t mac;
};

class Intercom: public Base_device 
{
	private:
		//enum eCommand {UNDEFINED, ON, OFF} Command = Intercom::eCommand::UNDEFINED;
		int Command;
	public:
		Intercom();
		~Intercom();
		
		void set_command(int cmd) override;
		int get_command(void) override;
};

class Curtain: public Base_device 
{
	private:
		//enum eCommand {UNDEFINED, OPEN, CLOSE} Command = Curtain::eCommand::UNDEFINED;
		int Command;
	public:
		Curtain();
		~Curtain();
		
		void set_command(int cmd) override;
		int get_command(void) override;
};
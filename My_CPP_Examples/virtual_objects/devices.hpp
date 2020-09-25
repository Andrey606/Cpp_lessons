#pragma once

#include <iostream>

class Base_device
{
	public:
		enum class eCommand: uint8_t {UNDEFINED, ON, OFF, OPEN, CLOSE};
		
		Base_device(Base_device&& in): mac(std::move(in.mac)),  Command(std::move(in.Command)){};
		Base_device():Command(eCommand::UNDEFINED){};
		virtual ~Base_device()  = default;

		uint64_t get_mac(void);
		void set_mac(uint64_t mac);
		
		void set_command(eCommand cmd);
		virtual void set_command_proccesing() {std::cout << "base set_command_proccesing" << std::endl;};
		
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
		Intercom(Base_device&& in): Base_device(std::move(in)){};
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
#include "devices.hpp"

// Base
void Base_device::set_mac(uint64_t mac)
{
    mac = mac;
}

uint64_t Base_device::get_mac(void)
{
    return mac;
}

void Base_device::set_command(eCommand cmd)
{
    Command = cmd;

    set_command_proccesing();
}

Base_device::eCommand Base_device::get_command(void)
{
    return Command;
}


// Intrercom
void Intercom::set_command_proccesing(void)
{
    std::cout << "Intrercom" << std::endl;
}

// Curtain
void Curtain::set_command_proccesing(void)
{
    std::cout << "Curtain" << std::endl;
}
#include "devices.hpp"

// Base
Base_device::Base_device(void)
{

}

void Base_device::set_mac(uint64_t mac)
{
    mac = mac;
}

uint64_t Base_device::get_mac(void)
{
    return mac;
}

// Intrercom
Intercom::Intercom()
{

}

void Intercom::set_command(int cmd)
{
    Command = cmd;
}

int Intercom::get_command(void)
{
    return Command;
}

// Curtain
Curtain::Curtain()
{

}

void Curtain::set_command(int cmd)
{
    Command = cmd;
}

int Curtain::get_command(void)
{
    return Command;
}
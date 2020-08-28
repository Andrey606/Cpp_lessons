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

void Base_device::set_command(eCommand cmd)
{
    Command = cmd;

}

// Intrercom
Intercom::Intercom()
{

}

void Intercom::set_command(Base_device::eCommand cmd)
{
    // to do
}

Base_device::eCommand Intercom::get_command(void)
{
    return Command;
}

// Curtain
Curtain::Curtain()
{

}

void Curtain::set_command(Base_device::eCommand cmd)
{
    // to do
}

Base_device::eCommand Curtain::get_command(void)
{
    return Command;
}
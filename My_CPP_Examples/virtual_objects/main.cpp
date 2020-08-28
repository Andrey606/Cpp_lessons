#include "devices.hpp"
#include <memory>

int main()
{
	
	auto a= std::make_shared<Intercom>();
	auto b= std::make_shared<Curtain>();

	std::shared_ptr<Base_device> obj=a;
	a->set_command(Base_device::eCommand::OFF);

	obj=b;
	b->set_command(Base_device::eCommand::ON);
}
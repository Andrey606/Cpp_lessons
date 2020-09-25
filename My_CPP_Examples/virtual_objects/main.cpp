#include "devices.hpp"
#include <memory>

int main()
{
	Base_device obj1;
	

	obj1.set_command(Base_device::eCommand::ON);
	obj1.set_mac(123);
	std::cout << obj1.get_mac() << std::endl;

	Intercom *obj2 = new Intercom(std::move(obj1));

	while(1)
	{
		std::cout << "obj1: " << obj1.get_mac() << std::endl; // seg error
	}
	std::cout << obj2->get_mac() << std::endl;
	obj2->set_command(Base_device::eCommand::ON);

	/*obj2 = dynamic_cast<Intercom *>(obj1);
	obj2->set_command(Base_device::eCommand::ON);
	std::cout << obj2->get_mac() << std::endl;*/



	/*auto a= std::make_shared<Intercom>();
	auto b= std::make_shared<Curtain>();
	auto c= std::make_shared<Base_device>();

	std::shared_ptr<Base_device> obj;

	obj=c;
	obj->set_mac(12345);
	obj->set_command(Base_device::eCommand::OFF);
	std::cout << obj->get_mac() << std::endl << std::endl;
	
	obj=a;
	a->set_command(Base_device::eCommand::OFF);
	std::cout << obj->get_mac() << std::endl << std::endl;

	obj=b;
	b->set_command(Base_device::eCommand::ON);
	std::cout << obj->get_mac() << std::endl << std::endl;*/
}
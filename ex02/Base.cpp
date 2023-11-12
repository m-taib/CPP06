#include "Base.hpp"

Base * 	generate(void)
{
	Base	*ptr;
	int	nb;


	srand(time(NULL));
	nb = rand() % 3;
	ptr = NULL;
	if (nb == 1)
		ptr = new A();
	else if (!nb)
		ptr = new B();
	else 
		ptr = new C();
	return (ptr);
}

void 	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A"<< std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B"<< std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C"<< std::endl;
	else
		std::cout << "unkown type" << std::endl;
}

void 	identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} 
	catch (const std::exception &e) {
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e) 
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e) 
			{ 
				std::cout << "unkown type" << std::endl; 
			}
		}
	}
}

Base::~Base()
{
	
}

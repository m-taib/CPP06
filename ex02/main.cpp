#include "Base.hpp"

int     main( void )
{
    Base*   a = generate();
	Base	d;
    identify(a);
    identify(d);
    delete a;
    return (0);
}

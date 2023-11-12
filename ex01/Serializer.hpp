#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

struct Data
{
	int		a;
	int		b;
	char	c;
	bool	t;
};

typedef unsigned long           uintptr_t;

class Serializer
{
	public :
		~Serializer();
		
		static uintptr_t serialize(Data* ptr);
		static Data* 	 deserialize(uintptr_t raw);
		
	private :
		
		Serializer();
		Serializer(const Serializer& rhs);
		Serializer& operator=(const Serializer& rhs);

};

#endif

#ifndef C_H
# define C_H

# include "Base.hpp"

class C : public Base
{
	public:
		C(void);
		C(const C &obj);
		virtual ~C(void);
		C &operator= (C const &src);
};

#endif

#ifndef B_H
# define B_H

# include "Base.hpp"

class B : public Base {
	public:
		B(void);
		B(const B &obj);
		virtual ~B(void);
		B &operator= (B const &src);
};

#endif

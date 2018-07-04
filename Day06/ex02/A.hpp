#ifndef A_H
# define A_H

# include "Base.hpp"

class A : public Base {
	public:
		A(void);
		A(const A &obj);
		virtual ~A(void);
		A &operator= (A const &src);
};

#endif

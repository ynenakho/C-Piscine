#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <iomanip>

class OutOfRangeException : public std::exception {
	public:
		virtual const char *what() const throw();
};

const char *OutOfRangeException::what() const throw() {
	return "Out of range access";
}
template <typename T = int>
class Array {

	private:
		T *_arr;
		unsigned int 	_len;

	public:

		Array<T>() : _arr(new T()), _len(0) {}
		Array<T>(unsigned int len) : _arr(new T[len]), _len(len) {}
		~Array<T>() { delete [] this->_arr; }


		Array<T>(Array<T> const &obj) {	*this = obj; }
		Array<T> &operator=(Array const &rhs) {
			this->_len = rhs.size();
			this->_arr = new T[this->_len];
			for (unsigned int i = 0; i < this->_len; i++) {
				this->_arr[i] = rhs[i];
			}
			return *this;
		}

		T &operator[](unsigned int num) {
			if (num > this->_len || num < 0)
				throw OutOfRangeException();
			return (this->_arr[num]);
		}

		T &operator[](unsigned int num) const {
			if (num >= this->_len || num < 0)
				throw std::exception();
			return (this->_arr[num]);
		}

		int size(void) const { return this->_len; }
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, Array<T> const &obj) {
	if (obj.size() == 0) {
		stream << "Array is empty";
		return stream;
	}
	stream << "Array <" << "T" << "> { ";
	for (int i = 0; i < obj.size(); i++)
		stream << obj[i] << ", ";
	stream << obj[obj.size() - 1 ] << " }";
	return stream;
}

#endif

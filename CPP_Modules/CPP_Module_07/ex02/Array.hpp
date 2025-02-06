#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

class OutOfLimit : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Out of limit";
		}
};

# define TT template <typename T>

TT class Array
{
	private:
		T*				_Array;
		unsigned int	_Size;
	public:
		Array<T>() { _Array = NULL; _Size = 0; }

 		Array<T>(unsigned int n) { !n ? _Array = NULL : _Array = new T[n](); _Size = n; }

		Array<T>(const Array<T> & other) : _Array(NULL), _Size(0) {*this = other; }

		Array<T> & operator=(const Array<T> & other) {
			if (this != &other) {
				if (_Array)
					delete [] _Array;
				if (other._Size && other._Array)
					_Array = new T[other._Size];
				for (unsigned int i = 0; _Array && i < other._Size && other._Array; i++)
					_Array[i] = other._Array[i];
				_Size = other._Size;
			}
			return (*this);
		}

		~Array<T>() { if (_Array) delete [] _Array;}

 		T &	operator[](unsigned int n) { if (n >= _Size) throw OutOfLimit(); return (_Array[n]); }

		unsigned int	size() const { return _Size;}
};


#endif

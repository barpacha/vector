#include <cstdlib>
template <typename T>
class Vector
{
public:
	class Iterator
	{
		friend Iterator Vector<T>::begin();
		friend Iterator Vector<T>::end();
	public:
		Iterator();
		Iterator(const Iterator &copy);
		Iterator operator++(int);
		T operator*();
		Iterator &operator=(const Iterator& right);
		bool operator==(const Iterator& right);
		bool operator!=(const Iterator& right);
	private:
		T * pointer;
	};
	Vector();
	Vector(const Vector &copy);
	Vector(T mas[], int size);
	~Vector();
	void insert(Iterator iterator, T data);
	void push_back(T data);
	void pop_back();
	void resize(int new_size);
	Iterator begin();
	Iterator end();
	T operator[](int index);
	int size();
	T front();
	T back();
private:
	T * mas = nullptr;
	int _size = 0;
};

template<typename T>
Vector<T>::Vector()
{
}

template<typename T>
Vector<T>::Vector(const Vector & copy)
{
	resize(copy._size);
	for (int i = 0; i < copy._size; i++)
		mas[i] = copy[i];
}

template<typename T>
Vector<T>::Vector(T mass[], int size)
{
	resize(size);
	for (int i = 0; i < copy._size; i++)
		mas[i] = mass[i];
}

template<typename T>
Vector<T>::~Vector()
{
	if (_size != 0) free(mas);
}

template<typename T>
void Vector<T>::insert(Iterator iterator, T data)
{
	resize(_size + 1);
	for (int i = (iterator.pointer - mas) / sizeof(T); i < _size; i++)
		mas[i + 1] = mas[i];
	mas[(iterator.pointer - mas) / sizeof(T)] = data;
}

template<typename T>
void Vector<T>::push_back(T data)
{
	resize(_size + 1);
	mas[_size - 1] = data;
}

template<typename T>
void Vector<T>::pop_back()
{
	resize(_size - 1);
}

template<typename T>
void Vector<T>::resize(int new_size)
{
	T *m = (T*)calloc(new_size, sizeof(T));
	for (int i = 0; i < _size && i < new_size; i++)
		m[i] = mas[i];
	if (!mas) free(mas);
	mas = m;
	_size = new_size;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
	Vector<T>::Iterator rez;
	rez.pointer = mas;
	return rez;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
	Vector<T>::Iterator rez;
	rez.pointer = mas + _size;
	return rez;
}

template<typename T>
T Vector<T>::operator[](int index)
{
	return mas[index];
}

template<typename T>
int Vector<T>::size()
{
	return _size;
}

template<typename T>
T Vector<T>::front()
{
	return mas[0];
}

template<typename T>
T Vector<T>::back()
{
	return mas[_size - 1];
}

template<typename T>
Vector<T>::Iterator::Iterator()
{
}

template<typename T>
Vector<T>::Iterator::Iterator(const Iterator & copy)
{
	pointer = copy.pointer;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
{
	pointer++;
	return *this;
}

template<typename T>
T Vector<T>::Iterator::operator*()
{
	return *pointer;
}

template<typename T>
typename Vector<T>::Iterator & Vector<T>::Iterator::operator=(const Iterator & right)
{
	this->pointer = right.pointer;
	return *this;
}

template<typename T>
bool Vector<T>::Iterator::operator==(const Iterator & right)
{
	return (pointer == right.pointer);
}

template<typename T>
bool Vector<T>::Iterator::operator!=(const Iterator & right)
{
	return (pointer != right.pointer);
}
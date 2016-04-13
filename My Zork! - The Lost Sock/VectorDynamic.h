#ifndef __VECTOR__
#define __VECTOR__

template<class TYPE>
class Vector{
private:
	TYPE* buffer;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;
	

public:
	Vector()
	{
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& copy)
	{
		capacity = num_elements = copy.num_elements;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; ++i)
			buffer[i] = copy.buffer[i];
	}
	
	~Vector()
	{
		delete[] buffer;
	}

	//Source http://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm
	TYPE &operator[](const unsigned int& i)
	{
		if (i > capacity)
		{
			// return first element.
			return buffer[0];
		}
		return buffer[i];
	}

	void push_back(const TYPE &element){
		
		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}

		buffer[num_elements++] = element;
	}

	void push_front(const TYPE &element){
		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}
		num_elements++;
		for (unsigned int i = 1; i < num_elements; i++)
			buffer[i] = buffer[i-1];
		buffer[0] = element;
	}

	void PaintVector()const
	{
		for (unsigned int i = 0; i < num_elements; i++)
			printf("%i ", buffer[i]);
		printf("\n");
	}

	bool empty(){
		return num_elements == 0 ? 1 : 0;
	}

	void clean(){
		delete[] buffer;
		buffer = new TYPE[capacity];
	}

	int size(){
		return num_elements;
	}

	int capacityn(){
		return capacity;
	}

	void pop_back(){
		buffer[num_elements--] = 0;
	}

	void shrink_to_fit(){
		TYPE* temp = nullptr;
		capacity = num_elements;
		temp = new TYPE[capacity];

		for (unsigned int i = 0; i < num_elements; i++)
			temp[i] = buffer[i];

		delete[] buffer;

		buffer = temp;
	}

};

#endif
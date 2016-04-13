#ifndef __MYSTRING__
#define __MYSTRING__

#include<stdio.h>
#include<string.h>

class My_String{

	private:
		char* buffer = nullptr;


	public:
		My_String(){}
		My_String(const char* str);
		My_String(const My_String& str);

		~My_String();

		void write();
		void write(const char* str);
		unsigned int lenght() const;
		const char* c_str() const;
		bool empty() const;
		bool operator == (const My_String str) const;
		My_String operator -= (const My_String str) const;
};

#endif


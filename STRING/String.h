//
//  String.h
//  STRING
//
//  Created by Анна Горячева on 19.04.2021.
//

#ifndef String_h
#define String_h
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"

////////////////////////////////////////////////////////////////////////////////////////////
///////////////////        CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА            ////////////////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
    char* str;    //Указатель на строки в динамической памяти
    int  size;    //Размер строки в Байтах.
public:
    const char* get_str()const;
    char* get_str();
    unsigned long long int get_size()const;

    //            Constructors:
    explicit String(int size = 80);
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();

    //            Operators:
    String& operator=(const String& other);
    String& operator=(String&& other);
    String& operator+=(const String& other);

    const char& operator[](int index)const;
    char& operator[](int index);

    //            Methods:
    void print()const;
};

///////////////////                  CLASS DECLARATION END                    ////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


#endif /* String_h */

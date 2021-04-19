//
//  main.cpp
//  STRING
//
//  Created by Анна Горячева on 12.04.2021.
//
#include <iostream>
using namespace std;

#define DELIMETER "\n-----------------------------------\n"


///////////////////////////// CLASS DECLARATION - объявление класса/////////////////
class String;
String operator+(const String& left, const String& right);

class String
{
    char* str; // указатель на строку в динамической памяти
    unsigned long long int size; // Размер строки в байтах
public:
    const char* get_str()const;
    char* get_str();
    unsigned long long int get_size()const;
    
    // Constructors
    explicit String(int size=80);
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();
    
    char& operator[](int index);
    const char& operator[](int index)const;
    
    // Operators
    String& operator=(const String& other);
    String& operator=(String&& other);
    String& operator+=(const String& other);
    
    // Methods
    void print()const;
};
///////////////////////////// CLASS DECLARATION END////////////////////////////////

///////////////////////////// CLASS DEFINITION - определение класса/////////////////

const char* String::get_str()const
{
    return str;;
}
char* String::get_str()
{
    return str;;
}
unsigned long long int String::get_size()const
{
    return size;
}

// Constructors
String::String(int size):size(size),str(new char[size] {})
{
//        this->size=size;
//        this->str=new char[size]{};
    cout << (size==80? "Default" : "Size")<< "Constructor:\t" << this << endl;
}
String::String(const char* str): String(strlen(str)+1)
{
    strcpy(this->str, str);
    cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other):String(other.str)
{
//        this->size=other.size;
//        this->str=new char[size]{};
    //strcpy(this->str, other.str);
    cout << "CopyConstructor:\t"<< this << endl;
}
String::String(String&& other):size(other.size), str(other.str)
{
//        this->size = other.size;
//        this->str = other.str;
    other.str=nullptr;
    cout << "MoveConstructor:\t"<<this<< endl;
}
String::~String()
{
    delete[]this->str;
    cout << "Destructor:\t\t"<<this << endl;
}

char& String::operator[](int index)
{
    return this->str[index];
}
const char& String::operator[](int index)const
{
    return this->str[index];
}

// Operators
String& String::operator=(const String& other)
{
    //Проверить не является ли другой объект нашим объектом
    if(this==&other)return *this;
    // Сначала удаляем старое значение объекта и только потом присваиваем ему новое значение
    delete [] this->str;
    this->size=other.size;
    this->str=new char[size]{};
    strcpy(this->str, other.str);
    cout << "CopyAssignments:\t\t"<< this << endl;
    return *this;
    
}
String& String::operator=(String&& other)
{
    delete[] this->str;
    this->size=other.size;
    this->str=other.str;
    other.str=nullptr;
    cout << "MoveAssignment:\t\t" << this << endl;
    return *this;
}
String& String::operator+=(const String& other)
{
    return *this=*this+other;
}

// Methods
void String::print()const
{
    cout << "Size:\t"<< size << endl;
    cout << "Str:\t" << str << endl;
    //for(int i=0; i<size;i++)cout << (int)str[i];cout << endl;
}
String operator+(const String& left, const String& right)
{
    String result(left.get_size()+right.get_size()-1);
    for(int i=0;i<left.get_size();i++)
    {
        result[i]=left[i];
    }
    for(int i=0;i<right.get_size();i++)
    {
        result[i+left.get_size()-1]=right[i];
    }
    return result;
}
ostream& operator<<(ostream& os, const String& obj)
{
    return os << obj.get_str();
}
istream& operator>>(istream& os, String& obj)
{
    return os >> obj.get_str();
}

///////////////////////////// CLASS DEFINITION END////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATORS_PLUS_CHECK
int main() {
    setlocale (LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
    String str;
    str.print();
    String str2= "Hello";
    str2.print();
    cout << str2 << endl;
    String str3=str2;
    cout << "Str3:\t" << str3 << endl;
    String str4;
    str4=str3; //CopyAssignments
    cout << "Str4:\t" << str4 << endl;
#endif
#ifdef ASSIGNMENT_CHECK
    String str1 = "Hello";
    String str2;
    str1=str1;
    cout << str1 << endl;
    cout << str2 << endl;
#endif
#ifdef OPERATORS_PLUS_CHECK
    String str1="Hello";
    String str2="World";
    cout << DELIMETER << endl;
    String str3;
    str3=str1 + str2; // Оператор + будет выполнять конкатенацию (слияние) строк
    //cout << str3 << endl;
    str3.print();
    String str4=str3;
    cout << str4 << endl;
//    //cout << &str3.get_str() << endl;
//    cout << DELIMETER << endl;
//    cout << str3 << endl;
//    cout << DELIMETER << endl;
//    str1+=str2;
//    cout << str1 << endl;
//    cout << DELIMETER << endl;
#endif
//    String str1; // DefaultConstructor
//    String str2(); // объявляется функция str2,кот.ничего не принимает и возвращает значение типа String
//    String str3{}; // DefaultConstructor
//    String str4(5); // SizeConstructor
//    String str5{ 8 }; // SizeConstructor
//    String str6("Hello");
//    String str7{"Hello"};
//    cout << str7 << endl;
//    //String str8=16; // Неявное преобразование в String
    
    return 0;
}

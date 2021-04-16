//
//  main.cpp
//  STRING
//
//  Created by Анна Горячева on 12.04.2021.
//
#include <iostream>
using namespace std;

#define DELIMETER "\n-----------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
    char* str; // указатель на строку в динамической памяти
    unsigned long long int size; // Размер строки в байтах
public:
    const char* get_str()const
    {
        return str;;
    }
    char* get_str()
    {
        return str;;
    }
    unsigned long long int get_size()const
    {
        return size;
    }
    
    // Constructors
    String(int size=80)
    {
        this->size=size;
        this->str=new char[size]{};
        cout << (size==80? "Default" : "Size")<< "Constructor:\t" << this << endl;
    }
    String(const char* str)
    {
        this->size=strlen(str)+1;
        this->str=new char[size]{};
        strcpy(this->str, str);
        cout << "Constructor:\t\t" << this << endl;
    }
    String(const String& other)
    {
        this->size=other.size;
        this->str=new char[size]{};
        strcpy(this->str, other.str);
        cout << "CopyConstructor:\t"<< this << endl;
    }
    String(String&& other)
    {
        this->size = other.size;
        this->str = other.str;
        other.str=nullptr;
        cout << "MoveConstructor:\t"<<this<< endl;
    }
    ~String()
    {
        delete[]this->str;
        cout << "Destructor:\t\t"<<this << endl;
    }
    
    char& operator[](int index)
    {
        return this->str[index];
    }
    const char& operator[](int index)const
    {
        return this->str[index];
    }
    
    // Operators
    String& operator=(const String& other)
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
    String& operator=(String&& other)
    {
        delete[] this->str;
        this->size=other.size;
        this->str=other.str;
        other.str=nullptr;
        cout << "MoveAssignment:\t\t" << this << endl;
        return *this;
    }
    String& operator+=(const String& other)
    {
        return *this=*this+other;
    }
    
    // Methods
    void print()const
    {
        cout << "Size:\t"<< size << endl;
        cout << "Str:\t" << str << endl;
        //for(int i=0; i<size;i++)cout << (int)str[i];cout << endl;
    }
};
String operator+(const String& left, const String& right)
{
    String result=left.get_size()+right.get_size()-1;
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

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
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
    String str1="Hello";
    String str2="World";
    cout << DELIMETER << endl;
    String str3;
    str3=str1 + str2; // Оператор + будет выполнять конкатенацию (слияние) строк
    //cout << str3 << endl;
    str3.print();
//    //cout << &str3.get_str() << endl;
//    cout << DELIMETER << endl;
//    cout << str3 << endl;
//    cout << DELIMETER << endl;
//    str1+=str2;
//    cout << str1 << endl;
//    cout << DELIMETER << endl;
    return 0;
}

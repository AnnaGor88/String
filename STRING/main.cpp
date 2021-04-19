//
//  main.cpp
//  STRING
//
//  Created by Анна Горячева on 12.04.2021.

#include "String.h"
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
//    cout << DELIMETER << endl;
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

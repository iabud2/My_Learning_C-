#include <iostream>
#include "clsDeveloper.h"
using namespace std;

int main()
{
    clsDeveloper Person1(10, "Ahmed", "Mohammed", "me@gmail.com", "09864321", "Boss", 5550, "Stc", "C++");

    Person1.Print();
    Person1.SendEmail("Hi", "How Are You");
    Person1.SendSMS("How Are You");
    system("pause>0");
    return 0;
}
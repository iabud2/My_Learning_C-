#include <iostream>
using namespace std;

struct Job
{
    float salary;
    string job_address;
    string Job_name;
    string Job_phone;
};


struct contact
{
    string Phone_number;
    string Email;
};
struct address
{
    string street1;
    string street2;
    string city;
    string country;
};

struct info1
{
    string name;
    int age;
    string married_or_not;
    string gender;
    address country;
    contact Email;
    Job salary;
};






int main(){
    info1 person_1, person_2;
    person_1.name = "Mohammed Ahmed";
    person_1.age = 30;
    person_1.married_or_not = "Yes married";
    person_1.gender = "Male";
    person_1.country.country = "Qatar";
    person_1.Email.Email = "Mohammed@gmail.com";
    person_1.salary.salary = 10000;

    cout << person_1.country.country<<endl<< person_1.salary.salary ;
    return 0 ;
}
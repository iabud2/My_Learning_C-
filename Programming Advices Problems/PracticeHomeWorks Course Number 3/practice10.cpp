#include <iostream>
using namespace std;

enum enCOLOR {Yellow, White, Green, Red};
enum enGender  {Male, Female};
enum enMaritalstatus {Single , Married};

struct stJob
{
    float salary;
    string job_address;
    string Job_name;
    string Job_phone;
};

struct stcontact
{
    string Phone_number;
    string Email;
};
struct staddress
{
    string street1;
    string street2;
    string city;
    string country;
};

struct stinfo1
{
    string name;
    int age;
    enMaritalstatus Maritial_status;
    enGender Gender;
    staddress address;
    stcontact contacti;
    stJob job_info;
    enCOLOR fcolor;
};

int main(){
    stinfo1 person_1, person_2;
    enMaritalstatus Maritial_status;
    enGender Gender;
    enCOLOR fcolor;
    person_1.name = "Mohammed Ahmed";
    person_1.age = 30;
    person_1.Gender = enGender::Male;
    person_1.Maritial_status = enMaritalstatus::Married;
    person_1.address.country = "Qatar";
    person_1.contacti.Email = "Mohammed@gmail.com";
    person_1.job_info.salary = 10000;
    person_1.fcolor = enCOLOR::Red;

    cout << person_1.Maritial_status;
    return 0 ;
}
//functions in c++
#include <iostream>
using namespace std;

void info_func() {

    string name ="Mohammed Abi-hadhoud";
    string Age = "44 Years";
    string City = "Amman.";
    string Country = "Jordan";

    cout <<"Name: "<< name << endl;
    cout <<"Age: "<< Age << endl;
    cout <<"City: "<< City << endl;
    cout <<"Country: "<< Country << endl;    

};

void stars_func()
{
    string stars= "************************\n";
    cout << stars;    
    cout << stars;    
    cout << stars;    
    cout << stars;    
    cout << stars;    
}

void words_func()
{
    string s1 = "I Love Programing\n";
    string s2 = "I Promise To Be The Beest Developer Ever\n";
    string s3 = "I Know It Will Take Some Time To Pracitce ,\nBut I Wil Achive My Goal\n";
    string s4 = "Best Regards,\n Mohammed Abu-Hadhoud";
    cout<< s1 << s2 << s3 << s4;
}

void h_func()
{
    cout <<"*     *\n*     *\n*******\n*     *\n*     *";

}

int main()
{
    info_func();
    cout << endl;
    stars_func();
    cout << endl;
    words_func();
    cout << endl;
    h_func();
    cout << endl;

    return 0;
}
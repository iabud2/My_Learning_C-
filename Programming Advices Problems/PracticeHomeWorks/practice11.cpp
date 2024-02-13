#include <iostream>
#include <string>
using namespace std;

int main()
{
    string st1 = "43.22";

    int one = stoi(st1);
    float two = stof(st1);
    double three= stod(st1);
    cout<<"num_int = "<<one<<endl;
    cout<<"num_dloat = "<<two<<endl;
    cout<<"num_idouble = "<<three<<endl;

    int N1 = 20;
    float N2 = 33.05;
    string string_one = to_string(N1);
    string string_two = to_string(N2);
    cout <<string_one << "--" <<string_two<<endl;

    float N3 = 55.23;
    int N4;
    N4 = N3;
    cout << N4<<endl;
    int N6, N7;
    N6 = (int)N3;
    N7 = int(N3);
    string s10;
    s10 = to_string(N3);
    cout<< N6 << endl << N7<<endl << s10;

    return 0;
}  
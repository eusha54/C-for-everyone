#include <iostream>
using namespace :: std;
const double mi_to_km = 1.609;

inline double convert(int mi){return mi*mi_to_km;}

int main(void){
    int miles = 1;
    while(miles){
        cout << "Enter distance in miles or 0 to terminate" << endl;
        cin >> miles;
        cout << "Distance is " << convert(miles) << " km" << endl;
    }
}
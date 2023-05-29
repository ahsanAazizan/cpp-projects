#include <iostream>;
#include <cmath>;

using namespace std;

// Mortgage Calculator (in dollar)

double calculateMortgage(int p, float r, int n){
    const int MONTH = 12;
    const int PERCENT = 100;

    float monthlyInterest = r / PERCENT / MONTH; // Monthly interest
    int numberOfPayment = n * MONTH;

    double mortgage = p * (monthlyInterest * pow(1 + monthlyInterest, numberOfPayment)) / (pow(1 + monthlyInterest, numberOfPayment) - 1);
    return mortgage;
}

int main(){
    int p, n;
    float r;

    cout << " Principal: ";
    cin >> p;

    cout << "Annual Interest Rate: ";
    cin >> r;

    cout << "Period (Years): ";
    cin >> n;

    cout << "Mortgage: $" << calculateMortgage(p, r, n);
    return 0;
}


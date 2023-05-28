#include <iostream>

using namespace std;

// Using Luhn Algorithm
int main(int argc, char *argv[]) {
    string cardNum;
    int res = 0;

    cout << "Credit Card Number: ";
    cin >> cardNum;

    res = sumEven(cardNum) + sumOdd(cardNum);

    if (res % 10 == 0) cout << cardNum << " is valid"<< endl;
    else cout << cardNum << " is invalid" << endl;
}

int sumOdd(const string cardNum) {
    int sum = 0;

    for (int i = cardNum.size() - 1; i >= 0; i -= 2)
    {
        sum += cardNum[i] - 48;
    }
    
    return sum;
}

int sumEven(const string cardNum) {
    int sum = 0;

    for (int i = cardNum.size() - 2; i >= 0; i -= 2)
    {
        sum += getDigit((cardNum[i] - 48) * 2);
    }

    return sum;
}

int getDigit(const int num) {
    int res = num % 10 + (num / 10 % 10);
    return res; 
}

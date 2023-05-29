#include <iostream>

using namespace std;

int getDigit(const int num);
int sumOdd(const string cardNum);
int sumEven(const string cardNum);
string split(const string cardNum);

// Using Luhn Algorithm
int main(int argc, char *argv[]) {
    string cardNum;
    int res = 0;

    cout << "Credit Card Number: ";
    cin >> cardNum;

    res = sumEven(cardNum) + sumOdd(cardNum);
    cardNum = split(cardNum);

    if (res % 10 == 0){
        cout << cardNum << "is valid"<< endl;
        return 0;
    }


    cout << cardNum << "is invalid" << endl; // if not valid
    return 0;
}

int getDigit(const int num) {
    int res = num % 10 + (num / 10 % 10);
    return res; 
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

// split string to xxxx-xxxx-xxxx-xxxx
string split(const string cardNum) {
    string res = "";

    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res += cardNum[index];
            index++;
        }
        res += "-";
    }
    res[19] = ' ';
    
    return res;
}
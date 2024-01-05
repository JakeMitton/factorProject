/**
 * findFactors.cpp
 * Find the square root of a positive integer, then use that to find the factors
 * of that integer (must run in less then O(n) time.)
 *
 */

#include <iostream>
#include <string>
using namespace std;


int sqrt(int, int);
int sqrt_recursive(int, int);


int sqrt(int number) {
    return sqrt_recursive(number, number);
}

int sqrt_recursive(int root, int integer) {
    int temp = root / 2;
    int temp_squared = temp * temp;

    if (temp_squared > integer) {
        return sqrt_recursive(temp, integer);
    } else if (temp_squared < integer) {
        //In this case temp will always be less than sqrt(integer)
        //therefore this for loop has complexity O(sqrt(n))
        for (int i = 0; i <= temp; i++) {
            temp++;
            temp_squared = temp * temp;
            if (temp_squared > integer) {
                return temp-1;
            }
        }
    } else {
        return temp;
    }
}

void factor(int integer) {
    cout << "The factors of " << integer << " are: " << endl;
    int root = sqrt_recursive(integer, integer);
    cout << "\t" << 1 << endl;
    for (int i = 2; i <= root; i++) {
        if (integer % i == 0) {
            cout << "\t" << i << endl;
        }
    }
    //if (root * root == integer) {
        //cout << "\t" << root << endl;
    //}
    for (int i = root; i > 0; i--) {
        if (integer % i == 0) {
            cout << "\t" << integer/i << endl;
        }
    }
}





int main() {

    cout << "The square root of 1 is " << sqrt(1) << endl;
    cout << "\texpected: 1" << endl;
    factor(1);
    cout << endl;
    cout << "The square root of 2 is " << sqrt(2) << endl;
    cout << "\texpected: 1" << endl;
    factor(2);
    cout << endl;
    cout << "The square root of 4 is " << sqrt(4) << endl;
    cout << "\texpected: 2" << endl;
    factor(4);
    cout << endl;
    cout << "The square root of 21 is " << sqrt(21) << endl;
    cout << "\texpected: 4" << endl;
    factor(21);
    cout << endl;
    cout << "The square root of 45 is " << sqrt(45) << endl;
    cout << "\texpected: 6" << endl;
    factor(45);
    cout << endl;
    cout << "The square root of 144 is " << sqrt(144) << endl;
    cout << "\texpected: 12" << endl;
    factor(141);
    cout << endl;
    cout << "The square root of 265 is " << sqrt(265) << endl;
    cout << "\texpected: 16" << endl;
    factor(265);
    cout << endl;
    cout << "The square root of 512 is " << sqrt(512) << endl;
    cout << "\texpected: 22" << endl;
    factor(512);
    cout << endl;
    cout << "The square root of 1000 is " << sqrt(1000) << endl;
    cout << "\texpected: 31" << endl;
    factor(1000);
    cout << endl;
    cout << "The square root of 12,544 is " << sqrt(12544) << endl;
    cout << "\texpected: 112" << endl;
    factor(12544);
    cout << endl;
    
    return 0;
}

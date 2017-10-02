/*
 * Jeremy Reynolds
 * Lab3
 * Due Oct 2 2017
 * COSC 2030
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int factorial(int);
int error();
int strange(int n);
int repeat(int n);
int repeatFact(int n);
int error1();


int main(int n) {
    // Part 1 reads n and computes the sum of the consecutive integer using type short .
    // Question 2: I can detect overflow because it goes from positive numbers to negative.
    // When i run n (or i) as 300, 256 is the value that produces overflow. Same happened when i ran 270 as n.
    cout << "Sum of consecutive ints:"<< endl;

    short count = 0;
    for (short n=0; n<300; n++){
        count+=n;
        if (count < 0){
            cout << n << endl;
            break; // Take out if you want to see overflow

        }
        cout << n << "\t" << count << endl;
    }
    factorial(300);
    repeatFact(300);
    error1();
    error();
    strange(20);
    //repeat(300); ////Kills laptop
}

int repeat(int n) {
    // This is a repeat of Part 1 that reads n and computes the sum of the consecutive integer using type LONG.
    // Tried to test the value that causes overflow but laptop gets overheated and acts up.
    // My research tells me that it can go up to 2,147,483,647 and is at least 32 bits in size.

    long count = 0;
    for (long n = 0; n < 5000000000; n++) {
        count += n;
        if (count < 0) {
            cout << n << endl;

        }
        cout << n << "\t" << count << endl;
    }
}

int factorial(int n){
    // Here i test for overflow by repeatedly reading n and computing the factorial.
    //Question 3: The value that causes overflow is 35. I can detect overflow because it goes into infinity (inf).
    cout << "Computing factorials:"<< endl;

    float product = 1;
    for (long i=1; i<n; i++){
        product*=i;
        if (isinf(product)){
            cout << i << endl;
            break; // take out break to go over
        }
        cout << i << "\t" << product << endl;
    }
}

int repeatFact(int n){
    // Here i test for overflow by repeatedly reading n and computing the factorial.
    // Question 5: 171 is the overflow value when i change float to double.
    cout << "Repeat using double instead of float:"<< endl;

    double product = 1;
    for (long i=1; i<n; i++){
        product*=i;
        if (isinf(product)){
            cout << i << endl;
        }
        cout << i << "\t" << product << endl;
    }
}


int strange(int n) {
    //Expected output should always be zero.

    cout << "Strange floats 1/n:"<< endl;

    double count = 0;
    for (double i = 1; i <= n; i++) {
        count+=(1/n);
        cout << i << "\t" << count << endl;

        }

    }

int error1() {
// The problem is i = 4.4 is printed even the for loop says i < 4.44.
    cout << "error using float: " << endl;
    for (float i = 3.4; i < 4.4; i += 0.2) {
        cout << "i = " << i << endl;
    }
}
int error(){
    cout << "error using double: " << endl;
// The problem is i = 4.4 is printed even the for loop says i < 4.44.
// A double is more precise than a float making the for loop more accurate.

    for (double i = 3.4; i < 4.4; i += 0.2) {
        cout << "i = " << i << endl;
    }
}
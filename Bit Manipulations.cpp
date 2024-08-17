// Bit Manipulations.cpp : This file contains the 'main' function. Program execution begins and ends there.



// 
//The "rightmost set bit" refers to the position of the first bit set to 1
//when counting from the right(least significant bit) 
//to the left(most significant bit) in the binary representation of a number.
#include <iostream>
using namespace std;

//getting a bit at specific position
int getBit(int n, int pos) {
    return (n & (1 << pos)) != 0;
}

//setting 1 at specific position
int setBit(int n, int pos) {
    return (n | (1 << pos));
}

//setting bit 0 at specific position
int clearBit(int n, int pos) {
    return (n & (~(1 << pos)));
}

//updating bit with 1 or 0
int updateBit(int n, int pos,int value) {
    return ((clearBit(n, pos)) | value << pos);
}

bool checkPowerOfTwo(int n);
int numberOfOnes(int n);
void subsets(int arr[], int n);
int uniqueNumber(int arr[], int idx);
int getrightSetBitPosition(int n);
void findTwoUniqueNumbers(int arr[], int idx);
int findUniqueInThriceArray(int arr[], int n);
int main()
{
    int arr[10] = { 1,2,5,7,2,7,1 ,3,3,6};
    int threearr[10] = { 1,2,3,4,3,2,1,2,3,1 };
    /*
    cout << getBit(5, 2) << endl;
    cout << setBit(5, 1) << endl;
    cout << clearBit(5, 2) << endl;
    cout<<updateBit(5, 1, 1) << endl;*/
    //cout << (checkPowerOfTwo(64) ? "Yes it is power of two" : "no it is not power of two") << endl;
    //cout << numberOfOnes(7) << endl;
    //subsets(arr, 4);
   //cout<< uniqueNumber(arr, 7) << endl;
    //findTwoUniqueNumbers(arr, 10);
    cout<<findUniqueInThriceArray(threearr, 10);
}

//check whether n is power of two or not
// (n and n-1) has same bits except the rightmost setbit
// so suppose if number is 8 which is 1000 in binary then n-1 will be 0111 and (n & n-1) is 0000 which is 0 
bool checkPowerOfTwo(int n) {
    return ((n & n - 1) == 0);
}

//count number of ones in binary representation of number
int numberOfOnes(int n) {
    int count=0;
    while (n>0)
    {
        n = (n & n - 1);
        count++;
    }
    return count;
}

//find all subsets of a set
void subsets(int arr[], int n) {
    for (int i = 0; i <(1<<n) ; i++)
    {
        cout << "{";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << ",";
            }
        }
        cout << "}";
        cout << endl;
    }
}

//we will find unique number in array where all the numbers are present twice
int uniqueNumber(int arr[], int idx) {
    int xorSum = 0;
    for (int i = 0; i < idx; i++)
    {
        xorSum = xorSum ^ arr[i];
    }
    return xorSum;
}

//we will find the position of rightmost set bit
int getrightSetBitPosition(int n) {
    int position = 0;
    while ((n & 1)==0)
    {
        n >>= 1;
        position++;
    }
    return position;
}

//we will find two unique numbers in array where all other numbers are present twice
void findTwoUniqueNumbers(int arr[], int idx) {
    int xorSum = 0;
    int oldxorSum;
    for (int i = 0; i < idx; i++)
    {
        xorSum = xorSum ^ arr[i];
    }
    oldxorSum = xorSum;
    int position = getrightSetBitPosition(xorSum);
    for (int i = 0; i < idx; i++)
    {
        if (getBit(arr[i], position)) {
            xorSum = xorSum ^ arr[i];
        }
    }
    int firstNum = xorSum;
    int secondNum = xorSum ^ oldxorSum;
    cout << "two unique numbers are " << firstNum << " and " << secondNum << endl;
}

//we have to find unique number where all other numbers are present thrice
int findUniqueInThriceArray(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i)) {
                sum++;
            }
        }
        if (sum%3!=0)
        {
            result = setBit(result, i);
        }
    }
    return result;

}
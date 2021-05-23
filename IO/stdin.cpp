/*
 * Author: Jiawei Wang
 * Date:   May 21. 2021
 * In the C++ input process, the input is loaded into the buffer.
 * Then we use these stdin functions to deal with the data in the buffer.
 *
 */

#include <iostream>
#include <stdio.h>

using namespace::std;

void Cin() {
    /* 
     * End condition: [enter] [space] [tab]
     *
     * Processing Method: when meet the [enter] [space] or [tab] in the buffer,
     * cin will end the current input and discard [enter] [space] [tab], continue the next input.
     * when there is continuous [space], [enter], [tab]. will be discarded.
     *
     * the data is input into the buffer, and then read in the data through scanf or cin or getchar functions
     */

    char a[10], b[10];
    cin >> a;
    cin >> b;
    cout << a << endl << b;

    /* 
     * input: 1234[Enter][Enter]5678
     * output: 1234[Wrap here]5678
     */
}

void CinGet() {
    /*
     * get() just get one char from the buffer no matter what is it
     */

    char a, b, c, d;
    a = cin.get();
    b = cin.get();
    cin.get(c);
    cin.get(d);
    cout << int(a) << ',' << int(b) << ',' << int(c) << ',' << int(d) << endl;

    /*
     * input: [Tab][Enter][Enter][Space]
     * output: 9, 10, 10, 32
     */
}

void CinGetline() {
    /*
     * getline() and get are pretty similar.
     * But only one difference: getline will delete [enter] from the buffer before it ends.
     */

    char a[10], b;
    /*
    cin.getline(a, 10);
    cin.get(b);
    cout << a << endl << (int)b;
    */

    /*
     * input: 1234[Enter]a[Enter]
     * output: 1234[Wrap here]97
     */

    cin.get(a, 10);
    cin.get(b);
    cout << a << endl << (int)b;

    /*
     * input: 1234[Enter]
     * output: 1234[Wrap here] 10
     */

}

void Scanf() {

    /*
     * scan the data from the buffer (no matter what is it)
     */
    
    char a,b;
    scanf("%c",&a);
//    getchar();
    scanf("%c",&b);
    printf("%d  %d\n",a,b);

    /*
     * input: a[Space]b
     * output: 97 32
     */

}

void Getchar() {
    char a, b;
    a = getchar();
    b = getchar();

    cout << a << endl << b;

    /*
     * input: a[Enter]
     * output: a[Wrap here] [Wrap here]
     */
}



int main() {
    // Cin();
    // CinGet();
    // CinGetline();
    // Scanf();
    // Getchar();

}

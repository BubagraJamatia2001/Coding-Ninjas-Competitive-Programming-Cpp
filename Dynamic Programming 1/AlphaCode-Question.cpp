/*
AlphaCode-Question

Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”
Bob:   “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”
Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think 
        you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”
Bob:   “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings 
        and with that many you would find at least two different ones that would make sense.”
Alice: “How many different decodings?”
Bob:   “Jillions!”

For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for 
a given string using her code.

Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.

Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"

Sample Input:
25114
1111111111
3333333333
0

Sample Output:
6
89
1
*/

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
typedef float f;
typedef string str;
typedef  long long ll;
typedef  long long int lli;
typedef char c;
typedef double d;
typedef vector<int> vi;
#define mod 1000000007

ll alpha_code(ll *n, ll size, ll *temp){
    if(size==1 || size==0)
        return 1;
    if(temp[size]>0)
        return temp[size];

    ll out=0;
    if(n[size-1]!=0)
        out+= alpha_code(n, size-1,temp);
    if((10*n[size-2]+n[size-1])<=26 && n[size-2]!=0)
        out+=alpha_code(n,size-2,temp);
    out%=mod;
    temp[size]=out;
    return out;
}
int main(){
    fast
    str s;
    while(cin>>s, s!="0"){
        ll size = s.length();
        ll* arr = new ll[size];
        ll temp[size+1];
        memset(temp,0,(size+1)* sizeof(ll));
        for (ll i = 0; i < s.length(); i++){
            arr[i] = s[i] - '0';
        }
        cout << alpha_code(arr, s.size(), temp) << endl;
        delete arr ,temp;
    }
    return 0;
}

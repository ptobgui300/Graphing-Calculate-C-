/*Program : 9.1
  Author : Pierre Tobgui
  Description : A program that can add large numbers at any base using pointers.
*/

#include <iostream>

using namespace std;

void Depad(char *a);
void Swap(char *a, char *b);
void Reverse(char *a);
void Pad(char *a);
int Strlen(char*a);
int Digit2Int(char a);
char Int2Digit(int s);
int Check(char key, char *a);
char AddAny(char*string, char*string2, char *result, int base);

void TESTADD();
void TestHexaDecimal();
void TESTADDANYBASE();

const int MAX=10;

int main(int argc, char *argv[])
{
    TESTADD();

    cout<<endl;

    TestHexaDecimal();

    cout<<endl;

    TESTADDANYBASE();

    return 0;
}
void TESTADD(){

    char string[MAX]= "999";
    char string2[MAX]="999";
    char result[MAX];
    int base=10;

    cout<<"In Base : "<<base<<endl;
    cout<<"String 1 : "<<string<<endl;
    cout<<"String 2 : "<<string2<<endl;

    AddAny(string,string2,result,base);

    cout<<"Result : "<<result<<endl;

}
void TESTADDANYBASE()
{
    char a1[MAX]="1001";
    char a2[MAX]="0011";
    char output[MAX];
    int base=2;

    cout<<"In Base : "<<base<<endl;
    cout<<"String 1 : "<<a1<<endl;
    cout<<"String 2 : "<<a2<<endl;

    AddAny(a1,a2,output,base);

    cout<<"Result : "<<output<<endl;

}
void TestHexaDecimal(){

    char s1[MAX]="F";
    char s2[MAX]="1";
    char Result[MAX];
    int base=10;

    cout<<"In Base : "<<base<<endl;
    cout<<"String 1 : "<<s1<<endl;
    cout<<"String 2 : "<<s2<<endl;

    AddAny(s1,s2,Result,base);

    cout<<"Result : "<<Result<<endl;

}
void Swap(char *a, char *b){

    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int Digit2Int(char a){

    int i=0;

    i=Check(a,"0123456789ABCDEF");

    return i;

}
char Int2Digit(int s){// Converts a int into a character.

    char c;
    c=s+'0';
    return c;

}
void Pad(char *a){ //Pads with zeros beginging at the string length and ending at one less than max.

    int start=Strlen(a);

    a+=start;
    for(int i=start;i<MAX-1;i++){
        *a= '0';
        a++;
    }
}
int Strlen(char*a){// Returns the length of the string.
    // How many characters are in a string.

    char*walker=a;

    while(*walker!=NULL){
        walker++;
    }
    return walker-a;

}
void Depad(char *a){// Removes unnecessary zeros.


    while (*a == '0'){


        a++;
    }
}
void Reverse(char*a){ //Reverses a string of characters.

    char *rptr=a;
    int start=Strlen(a);
    rptr+=start-1;

    while(rptr>a){

        Swap(a,rptr);
        rptr--;
        a++;
    }

}
char AddAny(char *string, char *string2,char*result, int base){

    int carry=0;
    int total;
    int value1;
    int value2;
    int num;

    char*walker=result;

    Reverse(string);
    Pad(string);

    Reverse(string2);
    Pad(string2);

    for(int i=0;i<MAX-1;i++){

        value1=Digit2Int(*string);
        value2=Digit2Int(*string2);

        total=carry+value1+value2;

        carry=total/base;

        num=total%base;

        *walker=Int2Digit(num); //converting the sum of both values back to a character.

        string++;
        string2++;
        walker++;

    }
    *walker=NULL;

    Reverse(result);
    Depad(result);
}
int Check(char key,char *a){// Checks the integer value in a character.

    char *walker=a;
    int send;

    int stop;
    stop=Strlen(a);

    while(key!=*walker){

        walker++;
    }

    send=walker-a;
    if(send>=stop){
        return 0;
    }
    else{
        return send;
    }
}

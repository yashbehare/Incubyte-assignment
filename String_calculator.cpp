#include<bits/stdc++.h>
using namespace std;

int add(string numbers)
{
    if( numbers.size() == 0 )
    {
        return 0;
    }
    int n = numbers.size();

    int sum = 0;
    int num = 0;
    bool negative = false;
    for(int i=0; i<n; i++)
    {
        // checking if there is a negative number
        if( i < n-1 and numbers[i] == '-' and numbers[i+1] >= '0' and numbers[i+1] <= '9' )
        {
            negative = true;
        }
        //forming a number from the string
        else if( numbers[i] >= '0' and numbers[i] <= '9' )
        {
            num = num*10 + numbers[i]-'0';
        }
        //if the character is a alphabet
        else if( 'a' <= numbers[i] and numbers[i] <= 'z' )
        {
            sum = sum + numbers[i]-'a'+1;
        }
        //if number is negative then raise exception and print num
        else if( negative )
        {
            cout<<"Exception : negatives not allowed : -"<<num<<endl;
            negative = false;
            num = 0;
        }
        //add only if num <= 1000
        else
        {
            if( num <= 1000 ) sum += num;
            num = 0;
        }
    }
    // handeling edge case for negative numbers at the end of string
    if( negative )
    {
        cout<<"Exception : negatives not allowed : -"<<num<<endl;
        negative = false;
        num = 0;
    }
    return sum+num;
}

int main()
{
//	string s;
//	cin>> s;
    //test cases
    cout<<add( "ab-1,-22,- 100cd" )<<endl<<endl;

    cout<<add( "-1,-22,- 100" )<<endl<<endl;
    cout<<add( "//;\n1;2" )<<endl<<endl;
    cout<<add( "1\n2,3" )<<endl<<endl;
    cout<<add( "20,30,100,40" )<<endl<<endl;
    cout<<add( "1,2" )<<endl<<endl;
    cout<<add( "1" )<<endl<<endl;
    cout<<add( "" )<<endl<<endl;
}

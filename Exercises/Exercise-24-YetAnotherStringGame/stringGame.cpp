#include <iostream>
#include <string>

using namespace std;

string yetAnotherStringGame(const string& s) 
{
    string finalString = s;
    int n = s.length();

    for (int i = 0; i < n; i++) 
    {
        if (i % 2 == 0) 
        {
            if (finalString[i] == 'a') finalString[i] = 'b';
            else finalString[i] = 'a';
        }
        else 
        {
            if (finalString[i] == 'z') finalString[i] = 'y';
            else finalString[i] = 'z';
        }
    }

    return finalString;
}

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        string s;
        cin >> s;

        string finalString = yetAnotherStringGame(s);
        cout << finalString << endl;
    }

    return 0;
}
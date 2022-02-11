#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    
    stack <int> myStack;

    freopen("PARENTHESES.inp", "r", stdin);
    freopen("PARENTHESES.out", "w", stdout);
    
    cin >> s;
    
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(')
            myStack.push(i);
        else if (s[i] == ')')
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }

    }

    return 0;
}
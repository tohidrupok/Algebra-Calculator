#include<bits/stdc++.h>
using namespace std;
int calculator(string ans)
{
    stack<int> s;
    for(int i=0; i<ans.length(); i++)
    {
        char now = ans[i];
        if(isdigit(now))
        {
            s.push(now - '0');
        }
        else
        {
            int dig1= s.top();
            s.pop();
            int dig2= s.top();
            s.pop();
            switch(now)
            {
            case '+':
                s.push(dig1 + dig2);
                break;
            case '-':
                s.push(dig2 - dig1);
                break;
            case '*':
                s.push(dig1 * dig2);
                break;
            case '/':
                s.push(dig1 / dig2);
                break;
            }
        }
    }
     return s.top();
}
int prec(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 0;
    }
    // * or /
    return 1;
}
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    string ans="";
    for(int i=0; i<s.size(); i++)
    {
        char now = s[i];
        /*if(now>='a' && now<='z')
        {
            ans += now;
        }*/
        if(isdigit(now))
        {
            ans +=(now) ;
        }

        else if (now == '(')
        {
            st.push(now);
        }

        else if (now == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }


        else
        {
            while(st.size() && st.top() != '(' && prec(st.top()) >= prec(now) )
            {
                ans += st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    while(st.size())
    {
        ans+=st.top();
        st.pop();
    }
    //cout<<ans <<" \n";
    int result = calculator(ans);
    cout<<result <<" \n";
    return 0;
}

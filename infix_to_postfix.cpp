#include<bits/stdc++.h>

using namespace std;
int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
  
string infixToPostfix(string s) 
{ 
    stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string postfix; 
    for(int i = 0; i < l; i++) 
    {  
        if((s[i] >= '0' && s[i] <= '9')) 
       		 postfix+=s[i]; 			 
        else if(s[i] == '(') 
        		st.push('('); 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               	postfix+= c;
			}
            	if(st.top() == '(') 
            	{ 
                	char c = st.top();
                	st.pop(); 
            	}	 
        	} 
    	
        else{ 
            while(st.top() != 'N' && precedence(s[i]) <= precedence(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                postfix += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        postfix += c; 
    } 
  
  return postfix; 
  
} 
int calculate(int a, int b, char operatorSign)
{
    if(operatorSign=='+')
        return a+b;
    else if(operatorSign=='-')
        return a-b;
    else if(operatorSign=='*')
        return a*b;
    else if(operatorSign=='/')
        return a/b;
    else if(operatorSign=='^')
        return pow(a,b);

}
int evaluatePostfixExpression(string postfixexp)
{
    stack <int> myStack;
    char ch;
    for(int i=0; postfixexp[i]; i++)
    {
        ch = postfixexp[i];
        if(ch>='0' && ch<='9') 
            myStack.push(ch-'0'); 
        else 
        {
            int a,b;
            b = myStack.top();
            myStack.pop();
            a = myStack.top();
            myStack.pop();

            myStack.push(calculate(a, b, ch));
        }
    }

    return myStack.top();
}

int main() 
{
	int result; 
    string exp,s1;
    cout<<"\nEnter the Infix Expression:";
	cin>>exp;
  	s1=infixToPostfix(exp);
  	cout<<"\nThe Outfix Expression is:"<<s1;;
 	result=evaluatePostfixExpression(s1);
	cout<<"\nThe evaluated result is: "<<result;
    return 0; 
} 

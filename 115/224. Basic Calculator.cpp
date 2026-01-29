#include <bits/stdc++.h>

using namespace std;

class Solution
{

    vector<string> convertStrToTerms(string s){
        vector<string> terms;
        int i = 0;
        bool isOp = true;
        while (i < s.size())
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            if (s[i] == '-')
            {
                if (isOp)
                {
                    i++;
                    while (s[i] == ' ')
                        i++;
                    if (s[i] == '(')
                    {
                        terms.push_back("-1");
                        terms.push_back("*");
                    }
                    else
                    {
                        string curr = "-";
                        while (i < s.size() && isdigit(s[i]))
                        {
                            curr += s[i];
                            i++;
                        }
                        terms.push_back(curr);
                    }
                    isOp = false;
                }
                else
                {
                    terms.push_back("-");
                    isOp = true;
                    i++;
                }
            }
            else if (s[i] == '+' || s[i] == '/' || s[i] == '*' || s[i] == '(' || s[i] == ')')
            {
                terms.push_back(string(1, s[i]));
                if (s[i] != ')')
                    isOp = true;
                i++;
            }
            else
            {
                string curr = "";
                while (i < s.size() && isdigit(s[i]))
                {
                    curr += s[i];
                    i++;
                }
                terms.push_back(curr);
                isOp = false;
            }
        }
        return terms;
    }


    vector<string> convertToPostFix(vector<string> &terms)
    {
        vector<string> postfix;
        stack<string> op;
        map<string, int> priority;
        priority["+"] = priority["-"] = 1;
        priority["*"] = priority["/"] = 2;
        for (string term : terms)
        {
            if (term == "(")
            {
                op.push("(");
            }
            else if (term == "+" || term == "-" || term == "*" || term == "/")
            {
                while (!op.empty() && op.top() != "(" && priority[op.top()] >= priority[term])
                {
                    postfix.push_back(op.top());
                    op.pop();
                }
                op.push(term);
            }
            else if (term == ")")
            {
                while (op.top() != "(")
                {
                    postfix.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }
            else
            {
                postfix.push_back(term);
            }
        }
        while (!op.empty())
        {
            postfix.push_back(op.top());
            op.pop();
        }
        return postfix;
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string token : tokens)
        {
            if (token != "+" && token != "/" && token != "-" && token != "*")
            {
                st.push(stoi(token));
                continue;
            }
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            int res;
            if (token == "+")
            {
                res = x + y;
            }
            else if (token == "-")
            {
                res = x - y;
            }
            else if (token == "/")
            {
                res = x / y;
            }
            else
            {
                res = x * y;
            }
            st.push(res);
        }
        return st.top();
    }

public:
    int calculate(string s)
    {

        vector<string> terms = convertStrToTerms(s);
        vector<string> postfix = convertToPostFix(terms);
        return evalRPN(postfix);

        return 0;
    }
};


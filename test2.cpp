#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

int main()  {

    ifstream input_stream("input.txt");
    string line;
    stack<char> stack;
    int errorResult = 0, i, oldValue;

    while(getline(input_stream, line))  {
        i = 0; oldValue = errorResult;

        while(line[i] != '\0')  {
            switch (line[i])  {
                case '(':
                case '[':
                case '{':
                case '<':
                    stack.push(line[i]);
                    break;
                
                case ')':
                    if(stack.empty() || stack.top() != '(') 
                        errorResult += 3;
                    else
                        stack.pop();
                    break;

                case ']':
                    if(stack.empty() || stack.top() != '[')
                        errorResult += 57;
                    else
                        stack.pop();
                    break;

                case '}':
                    if(stack.empty() || stack.top() != '{')
                        errorResult += 1197;
                    else
                        stack.pop();
                    break;

                case '>':
                    if(stack.empty() || stack.top() != '<')
                        errorResult += 25137;
                    else
                        stack.pop();
                    break;
            }

            if(oldValue != errorResult)  {
                cout << "Line corrupted " << errorResult << endl;
                break; // Current line is corrupted
            } 
            i++;
        }

        while(!stack.empty())  {
            stack.pop();
        }
        
    }

}
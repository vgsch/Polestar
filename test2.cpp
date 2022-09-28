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
    // we need a stack to push opening chars and to pop when finding a closing char

    // when finding a closing char and top of stack is not the proper opener, line is corrupted

    // before that, when finding a closing char, we need to test if stack is empty, line is also corrupted

    // on end of line we can say that line is OK or incomplete. As task dosen't ask to differentiate these two,
    // only compute the total syntax score error

}
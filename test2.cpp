#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

int main()  {

    ifstream input_stream("input.txt");
    string line;
    stack<char> stack;
    int errorResult = 0, i;

    while(getline(input_stream, line))  {
        i = 0;
        while(line[i] != '\0')  {
            switch (line[i])  {
                case '(':
                case '[':
                case '{':
                case '<':
                    stack.push(line[i]);
                    break;
            }
            i++;
        }
        cout << "Line: ";
        while(!stack.empty())  {
            cout << stack.top();
            stack.pop();
        }
        cout << endl;
        
    }
    // we need a stack to push opening chars and to pop when finding a closing char

    // when finding a closing char and top of stack is not the proper opener, line is corrupted

    // before that, when finding a closing char, we need to test if stack is empty, line is also corrupted

    // on end of line we can say that line is OK or incomplete. As task dosen't ask to differentiate these two,
    // only compute the total syntax score error

}
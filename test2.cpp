#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main()  {

    ifstream input_stream("input.txt");
    string line;
    stack<char> stack;
    int errorResult = 0, i, oldValue, j;
    list<double> incompleteList;
    list<double>::iterator it = incompleteList.begin();
    double incompleteResult;

    while(getline(input_stream, line))  {
        i = 0; oldValue = errorResult; incompleteResult = 0;

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

        if(oldValue != errorResult)  { //Corrupted Line
            while(!stack.empty())  {
                stack.pop();
            }
        }
        else  { // Incomplete Line
            while(!stack.empty())  {
                switch(stack.top())  {
                    case '(':  incompleteResult = incompleteResult * 5 + 1; break;
                    case '[':  incompleteResult = incompleteResult * 5 + 2; break;
                    case '{':  incompleteResult = incompleteResult * 5 + 3; break;
                    case '<':  incompleteResult = incompleteResult * 5 + 4; break;
                }
                stack.pop();
            }
            cout << "Line incomplete " << incompleteResult << endl;
            incompleteList.push_back(incompleteResult);
        }
    }
    
    incompleteList.sort();
    advance(it, incompleteList.size()/2 + 1);
    cout << "Middle : " <<fixed<< *it << endl;
}
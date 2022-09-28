#include <iostream>
#include <stack>
using namespace std;

int main() {

    // we need a stack to push opening chars and to pop when finding a closing char

    // when finding a closing char and top of stack is not the proper opener, line is corrupted

    // before that, when finding a closing char, we need to test if stack is empty, line is also corrupted

    // on end of line we can say that line is OK or incomplete. As task dosen't ask to differentiate these two,
    // only compute the total syntax score error

}
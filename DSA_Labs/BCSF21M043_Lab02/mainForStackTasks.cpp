#include <iostream>
#include "stackUsingDLL.h"
#include "stackUsingDLL.cpp"
using namespace std;
int main()
{
    /*Driver functions for Browser History Navigation program*/
    Stack<string> s1;
    Stack<string> forward;
    Stack<string> back;

    s1.visitNew("www.google.com", forward, back);
    s1.visitNew("www.youtube.com", forward, back);
    s1.visitNew("www.facebook.com", forward, back);
    s1.visitNew("www.hackster.com", forward, back);
    s1.navBack(forward, back);
    s1.navBack(forward, back);
    s1.navForw(forward, back);

    /*Driver functions for testing the Text Editor program*/

    Stack<char> undo;
    Stack<char> redo;

    undo.typing('M',undo, redo);
    undo.typing('E',undo, redo);
    undo.typing('E',undo, redo);
    undo.typing('S',undo, redo);
    undo.typing('U',undo, redo);
    undo.typing('M',undo, redo);
    undo.undoAction(undo, redo);
    undo.undoAction(undo, redo);
    undo.undoAction(undo, redo);
    undo.redoAction(undo, redo);

    /*Driver functions for Task Management System*/

    Stack<string> tasks;
    tasks.addTask("Task 1");
    tasks.addTask("Task 2");
    tasks.addTask("Task 3");
    tasks.addTask("Task 4");
    tasks.completeRecentTask();
    tasks.completeRecentTask();
    tasks.completeRecentTask();
    tasks.completeRecentTask();
    tasks.completeRecentTask();


    return 0;
}
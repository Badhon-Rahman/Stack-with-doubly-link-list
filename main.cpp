#include <iostream>

using namespace std;

typedef struct StackNode{
     int data;
     struct StackNode *nextNode;
     struct StackNode *previousNode;
}*stackPtr;

stackPtr topNode = NULL;

void PushList(int item){
       stackPtr newNode = new StackNode;
       newNode->data = item;
       if(topNode == NULL){
        newNode->previousNode = NULL;
        newNode->nextNode = NULL;
        topNode = newNode;
       }
       else{
        while(topNode->nextNode != NULL){
            topNode = topNode->nextNode;
        }
        if(topNode->nextNode == NULL){
           newNode->previousNode = topNode;
           newNode->nextNode = NULL;
           topNode = newNode;
        }
       }
}

void TravarseStackList(){
        stackPtr sPtr = topNode;
        if(sPtr == NULL){
            cout << "Stack List is Empty!!!" << endl;
        }
        else{
             cout << "Stack List: ";
             while(sPtr->previousNode != NULL){
               cout << sPtr->data << " ";
               sPtr = sPtr->previousNode;
             }
             if(sPtr->previousNode == NULL){
               cout << sPtr->data << endl;
             }
        }
}

void PopList(){
      stackPtr popPtr = topNode;
      if(topNode == NULL){
        cout << "Stack List is Empty!!!" << endl;
      }
      else if(topNode->previousNode == NULL){
         cout << "List Item Popped: " << popPtr->data << endl;
         delete(popPtr);
         topNode = NULL;
      }
      else{
         topNode->previousNode->nextNode = NULL;
         topNode = topNode->previousNode;
         cout << "List Item Popped: " << popPtr->data << endl;
         delete(popPtr);
      }
}

int main()
{
    int choice, pushValue, poppedValue;

    do{
      cout << "Press 1 to push element in stack." << endl;
      cout << "Press 2 to pop element from stack." << endl;
      cout << "Press 3 to display element of the stack." << endl;
      cout << "Press 4  Exit System." << endl;
      cout << "Select Your Choice: ";
      cin >> choice;
      switch(choice){
             case 1:{
                    cout << "Enter the pushing element: ";
                    cin >> pushValue;
                    PushList(pushValue);
                    break;
             }
            case 2:{
                    PopList();
                    break;
             }
             case 3:{
                  TravarseStackList();
                  break;
             }
             case 4:{
                    cout << "Exit System." << endl;
                    break;
             }
             default:{
                  cout << "You peek the WRONG choice. Select your choice again:";
             }
      }
    } while(choice != 4);
    return 0;
}

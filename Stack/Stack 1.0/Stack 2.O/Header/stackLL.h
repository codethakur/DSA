#pragma once

// Define the ListNode struct
struct ListNode {
    int data;
    ListNode* next;
};

// Define the StackLL struct
struct StackLL {
    ListNode* top; 
};

StackLL* CreateStackLL();
void pushintoStackLL(StackLL* S, int data);
int SizeStackLL(StackLL* S);
int isEmptStackLL(StackLL* S);
int popStackLL(StackLL* S);
int peekStackLL(StackLL* S);
void deleteStackLL(StackLL* S);

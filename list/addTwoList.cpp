#include <iostream>
#include <conio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void addNode(ListNode*& p, int val) {
        ListNode* new_node = new ListNode(val);

        ListNode* aux1 = p;
        ListNode* aux2 = nullptr;

        while (aux1 != nullptr) {
            aux2 = aux1;
            aux1 = aux1->next;
        }

        if (p == aux1)
            p = new_node;
        else
            aux2->next = new_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* aux1 = l1;
        ListNode* aux2 = l2;
        ListNode* new_node = nullptr;
        int res = 0;
        int carry = 0;

        while (aux1 != nullptr || aux2 != nullptr) {
            if(aux1 == nullptr){
                add(0, aux2->val, res, carry);
            }
            else if (aux2 == nullptr)
                add(aux1->val, 0, res, carry);
            else
                add(aux1->val, aux2->val, res, carry);
                
            addNode(new_node, res);
            if(aux1 != nullptr)
                aux1 = aux1->next;
            if(aux2 != nullptr)
                aux2 = aux2->next;  
        }
        
        return new_node;
    }

    void add(int aux1, int aux2,int &res, int &carry){
        res = aux1 + aux2 + carry;
        if (res < 10){
            carry = 0;
        }
        else {
            res = res - 10;
            carry = 1;
        }
    }
};

void modified(int &val1, int &val2){
    val1 = 1;
    val2 = 2;
}
int main(){
    int val1 = 6;
    int val2 = 5;
    
    cout << "val1: " << val1 << endl << "val2: " << val2 << endl; 
    modified(val1, val2);
    cout << "val1: " << val1 << endl << "val2: " << val2 << endl; 

    return 0;
}
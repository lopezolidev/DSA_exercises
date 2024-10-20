#include <iostream>

using namespace std ;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    ListNode* next ;
    int val ;
    ListNode() {
        val = 0 ; 
        next = nullptr ;
    } ;
    ListNode (int x) {
        val = x ;
        next = nullptr ;
    }
    ListNode (int x, ListNode *next) {
        val = x ;
        next = next ;
    }
} ;

void middleNode(ListNode* head) {
        int count = 1 ;

        ListNode* i = head ;
        while(i->next != nullptr) {

            count++ ;
            i = i->next ;
        } // loop for resorting through the linked list and know how many elements are there

        i = head ; // restarting the initial node

        int j = 0 ;

        while(j < count / 2){
            i = i->next ;
            j++ ;
        } // loop to resort to the middle node of the list

        cout << i->val ;
    }


int main () {

    ListNode A = ListNode(1) ;

    ListNode B = ListNode(2) ;

    ListNode C = ListNode(3) ;

    ListNode D = ListNode(4) ;

    ListNode E = ListNode(5) ;

    ListNode F = ListNode(6) ;

    A.next = &B ;

    B.next = &C ;

    C.next = &D ;

    D.next = &E ;

    E.next = &F ; 

    middleNode(&A) ;


    return 0 ;
}
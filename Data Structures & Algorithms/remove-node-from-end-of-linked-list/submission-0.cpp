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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int l=0;
        ListNode* temp=head;
        while(temp){
            l++;
            temp=temp->next;
        }

        if(n==l){
            ListNode* node=head;
            head=head->next;
            delete node;
            return head;
        }

        int cnt=0;
        ListNode* temp1=head;
        ListNode* prev=nullptr;
        while(temp1){
            cnt++;
            if(cnt==l-n+1){
                prev->next=temp1->next;
                break;
            }
            prev=temp1;
            temp1=temp1->next;
        }
        return head;
    }
};

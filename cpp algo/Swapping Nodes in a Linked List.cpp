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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        vector<int> vec;
        int count = 0;
        int i=0;
        while(temp1){
            vec.push_back(temp1->val);
            temp1 = temp1->next;
            count++;
        }
        
        swap(k-1, count-k, vec);
        
        while(temp2){
            temp2->val = vec[i];
            temp2 = temp2->next;
            i++;
        }
        
        return head;
    }
    void swap(int i, int j, vector<int>&vec){
        int temp;
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
}; 
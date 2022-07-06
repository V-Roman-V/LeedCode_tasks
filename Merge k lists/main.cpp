#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    
    lists.erase(remove_if(lists.begin(), lists.end(), [](ListNode* x){return x == nullptr;}), lists.end());
    
    while (true){            
        int min_id = -1;
        for(int i = 0; i < lists.size(); i++)
            if( min_id == -1 || lists[i]->val < lists[min_id]->val)
                min_id = i;
        if(min_id == -1)
            break;
        

        if(head == nullptr) {
            head = lists[min_id];
            cur = head;
        } else {
            cur->next = lists[min_id]; 
            cur = cur->next;
        }
        
        lists[min_id] = lists[min_id]->next;
        if(lists[min_id] == nullptr)
            lists.erase(lists.begin() + min_id);
    }
    
    return head;
}
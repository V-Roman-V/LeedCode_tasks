class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* cpHead = new Node(head->val);
        
        Node* cur = head;
        Node* cpCur = cpHead;

        while (cur->next != nullptr){
            cpCur->next = new Node(cur->next->val);;
            
            cur = cur->next;
            cpCur = cpCur->next;
        }

        cur = head;
        cpCur = cpHead;
        while (cur != nullptr){
            Node* random = cur->random;
            if(random != nullptr){        
                Node* ran_cur = head;
                Node* ran_cpCur = cpHead;
                while(random != ran_cur && ran_cur->next != nullptr){
                    ran_cur = ran_cur->next;
                    ran_cpCur = ran_cpCur->next;
                }
                cpCur->random = ran_cpCur;
            }
            cur = cur->next;
            cpCur = cpCur->next;
        }
        
        return cpHead;
    }
};


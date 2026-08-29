class Solution {
public:
    // A ideia é manter um ponteiro front que vai ser o primeiro elemento da 
    // "nova" lista, sempre que formos inserir imediatamente atrás (lá ele),
    // devemos atualizar o front.
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* newHead = head; //start by fixing first element as first element from sorted list
        head = head->next;

        newHead->next = nullptr;
        while (head) {
            ListNode* curr = head; // Fix curr, element that is being inserted
            head = head->next;
            
            //Scan for next greater and put behind it 
            ListNode* temp = newHead;
            ListNode* prev = nullptr;
            while(curr && temp && curr->val >= temp->val){
                prev = temp;
                temp = temp->next;
            }
            
            //insert at begin
            if(prev == nullptr){
                curr->next = newHead;
                newHead = curr;
            } //insert at mid or end
            else {
                prev->next = curr;
                curr->next = temp;
            }
        }
        return newHead;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return head;

        unordered_map<Node*, int> nodeToIndex;
        unordered_map<int, Node*> indexToNode;  
        int i = 0;
        
        Node* curr = head;
        Node* newList = new Node(curr->val);
        Node* newHead = newList;
        
        //Bridge between lists
        //First map links og list Nodes to indices
        //Second map links indices to new list Nodes
        nodeToIndex.insert({curr, i}); 
        indexToNode.insert({i, newList}); 
        ++i;
         
        curr = curr->next;
        while (curr) {
            newList->next = new Node(curr->val);
            newList = newList->next;
            
            nodeToIndex.insert({curr, i});
            indexToNode.insert({i, newList});
            
            curr = curr->next;
            ++i;
        }

        curr = head;
        newList = newHead;

        while (curr && newHead) {
            if(curr->random){
                int next_idx = nodeToIndex.at(curr->random);
                Node* next_node = indexToNode.at(next_idx);
                newList->random = next_node;
            }
            curr = curr->next;
            newList = newList->next;
        }

        return newHead;
        
    }
};
int countAndDeleteAllOccurrences(LinkedList &list, int key) {
    Node* head = list.getHead();
    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    while (curr) {
        if (curr->data == key) {
            count++;
            if (prev == nullptr) {
                head = curr->next;
                delete curr;
                curr = head;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    list.setHead(head);
    return count;
}


void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}

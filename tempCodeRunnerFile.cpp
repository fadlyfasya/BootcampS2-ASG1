    for(int i=0; i<M+N; i++){
        if(curr && curr->value < curr1->value ){
            pushTail2(curr->value);
            curr = curr->next;
        }
        else if(curr1 && curr1->value < curr->value){
            pushTail2(curr1->value);
            curr1 = curr1->next;
        }
    }
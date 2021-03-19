Question 1-)

Node* Node::removeAllLessThan(int x) {	
    if (data < x) {
        Node* ret = nullptr;
        if (right != nullptr)
        ret = right->removeAllLessThan(x);
    
        delete left;
        left = right = nullptr;
        delete this;

        return ret;
    }
    else {
        if (left!=nullptr) {
            left = left->removeAllLessThan(x);
            left->parent = this;
            return this;
        }
    }
}

Question 2-)

void BST::rotateToRoot(int x) {
    temp = root->search(x);

    while (temp->parent!=nullptr) {
        // IF is Left child: rotare right
        if(parent != nullptr && parent->left == this)
            temp->rotateRight();
        
        // IF is Right child: rotateLeft
        if(parent != nullptr && parent->right == this)
            temp->rotateLeft();
    }
}


Question 3-)

uint32_t hash(char* str, int len) {
    
    uint32_t* arr = reinterpret_cast<uint32_t*>(str);
    uint32_t hash = 0;
    size /= 4;

    for (int i=0;i<len;i++) {
        hash = (hash << 19) | (hash >> 13);
        hash ^= arr[i];
    }
    return hash;
}

Question 4-)

void HeapNode::percolateDown(HeapNode*) {
    HeapNode* maxChild;
    int tempData;

    if(child->data > child->sibling->data) // if max is left
        maxChild = child;
    else  // if max is right
        maxChild = child->sibling; 
    
    if(this->data < maxChild->data) { // if needs to swap
        tempData = this->data;
        this->data = maxChild->data;
        if(maxChild == this->child){ // if max is left
            child->data = tempData;
            child->percolateDown(); // recursive call on left child
        }
        else { // if max is right
            child->sibling->data = tempData;
            child->sibling->percolateDown(); // recursive call on right child
        }
    }
}

                                        

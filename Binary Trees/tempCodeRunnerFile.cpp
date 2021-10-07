Node *root = new Node(30);
    root->left = new Node(18);
    root->left->left = new Node(10);
    root->right = new Node(43);
    root->right->right = new Node(48);
    root->right->left = new Node(32);
    root->left->right = new Node(25);
    cout << "Postorder traversal: ";
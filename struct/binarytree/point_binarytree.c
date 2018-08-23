#include <stdio.h>
#include <stdlib.h>
#include "point_binarytree.h"

btlink NewBNode() {
    btlink p;
    if ((p = malloc(sizeof(Btnode))) == 0) {
        perror("Exchausted memory.");
    } else {
        return p;
    }
}

BinaryTree BinaryInit() {
    BinaryTree T = malloc(sizeof(BTree));
    T->root = 0;
    return T;
}


int BinaryEmpty(BinaryTree T) {
    return T->root == 0;
}

TreeItem Root(BinaryTree T) {
    if (BinaryEmpty(T)) {
        perror("Tree is empty");
    } else {
        return T->root->element;
    }
}

void MakeTree(TreeItem x, BinaryTree T, BinaryTree L, BinaryTree R) {
    T->root = NewBNode();
    T->root->element = x;
    T->root->left = L->root;
    T->root->right = R->root;
    L->root = R->root = 0;
}

TreeItem BreakTree(BinaryTree T, BinaryTree L, BinaryTree R) {
    TreeItem x;
    if (!T->root) {
        perror("Tree is empty");
    }
    x = T->root->element;
    L->root = T->root->left;
    R->root = T->root->right;
    T->root = 0;
    return x;
}

void PreOrder(void(*visit)(btlink u), btlink t) {
    if (t) {
        (*visit)(t);
        PreOrder(visit, t->left);
        PreOrder(visit, t->right);
    }
}

void InOrder(void(*visit)(btlink u), btlink t) {
    if (t) {
        InOrder(visit, t->left);
        (*visit)(t);
        InOrder(visit, t->right);
    }
}

void PostOrder(void(*visit)(btlink u), btlink t) {
    if (t) {
        PostOrder(visit, t->left);
        PostOrder(visit, t->right);
        (*visit)(t);
    }
}

void TreeItemShow(TreeItem element) {
    printf("%d\n", element);
}

void outnode(btlink t) {
    TreeItemShow(t->element);
}

void PreOut(BinaryTree T) {
    PreOrder(outnode, T->root);
}

void InOut(BinaryTree T) {
    InOrder(outnode, T);
}

void PostOut(BinaryTree T) {
    PreOrder(outnode, T);
}

int Height(btlink t) {
    int hl, hr;
    if (!t) {
        return -1;
    }
    hl = Height(t->left);
    hr = Height(t->right);
    if (hl > hr) {
        return ++hl;
    } else {
        return ++hr;
    }
}


int main (int argc, char const *argv[]) {
    BinaryTree T = BinaryInit();
    MakeTree(12, T, BinaryInit(), BinaryInit());
    printf("%d", Root(T));
    return 0;
}
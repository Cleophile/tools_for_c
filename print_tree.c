//  
// Created By Hikari Software
// 
// Y-Enterprise
// 
// 

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int my_power(int n, int power) {
    if(power==0) {
        return 1;
    }
    if(power==1) {
        return n;
    }
    if(power % 2 == 0) {
        int c = my_power(n, power / 2);
        return c * c;
    }
    int c = my_power(n, power / 2);
    return c * c * n;
}

int tree_height(struct TreeNode* root) {
    if(root==NULL) {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    if(left_height > right_height) {
        return left_height + 1;
    }
    return right_height + 1;
}

char* my_itoa(int a) {
    if (a == 0) {
        char* result = malloc(sizeof(char)*2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    int p = 19;
    int is_negative = 0;
    char* holder = malloc(sizeof(char)*20);
    if(a < 0) {
        is_negative = 1;
        a = -a;
    }
    while(a!=0) {
        holder[p] = a % 10 + '0';
        --p;
        a /= 10;
    }
    if(is_negative) {
        int length = 20 - p;
        char* result = malloc(sizeof(char) * (length + 1));
        result[length] = '\0';
        result[0] = '-';
        for(int i=1;i<length;++i) {
            result[i] = holder[i+p];
        }
        return result;
    }
    int length = 20 - p;
    char* result = malloc(sizeof(char) * length);
    --length;
    result[length] = '\0';
    ++p;
    for(int i=0;i<length;++i) {
        result[i] = holder[i+p];
    }
    return result;
}

void mid_order(char*** result, struct TreeNode* root, int base, int current_layer, int n) {
    if(root==NULL) {
        return;
    }
    int i = current_layer - 1;
    int j = my_power(2, n - current_layer - 1);
    result[i][base] = my_itoa(root->val);
    printf("%d, %d: %s\n", i,base,result[i][base]);
    mid_order(result,root->left,base-j,current_layer + 1,n);
    mid_order(result,root->right,base+j,current_layer + 1,n);

}

char *** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int n = tree_height(root);
    *returnSize = n;
    int element = my_power(2,n) - 1;
    (*returnColumnSizes) = malloc(sizeof(int)*n);
    char*** result = malloc(sizeof(char**)*n);
    for(int i=0;i<n;++i) {
        returnColumnSizes[0][i] = element;
        result[i] = malloc(sizeof(char*)*element);
        for(int j = 0; j < element; ++j) {
            result[i][j] = NULL;
        }
    }
    mid_order(result,root,my_power(2, n-1) - 1,1,n);

    for(int i=0;i < n;++i) {
        for(int j = 0; j < element; ++j) {
            if(result[i][j]==NULL) {
                char* empty = malloc(sizeof(char));
                *empty = '\0';
                result[i][j] = empty;
            }
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    printf("%s\n",my_itoa(123451));
    printf("2^4: %d\n",my_power(2, 4));
    struct TreeNode* a = malloc(sizeof(struct TreeNode));
    a->val = 12;
    struct TreeNode* b = malloc(sizeof(struct TreeNode));
    struct TreeNode* c = malloc(sizeof(struct TreeNode));
    b->val = 6;
    c->val = 29;
    b->left = NULL;
    b->right = NULL;
    c->left = NULL;
    c->right = NULL;
    a->left = b;
    a->right = c;
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    char*** result = printTree(a, &returnSize, &returnColumnSizes);
    for(int i=0;i<returnSize;++i) {
        for(int j=0;j<*returnColumnSizes;++j) {
            printf(" \"%s\" ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

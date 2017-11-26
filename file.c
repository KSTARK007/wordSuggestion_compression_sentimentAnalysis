#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
    char c;
    int freq;
    struct treeNode *left;
    struct treeNode *right;
};

struct listNode {
    struct treeNode *node;
    struct listNode *next;
};

struct header {
    char chars[10000];
    int length;
    int code[10000];
};

struct listNode *buildListNodes(char letters[], int freq[], int n) {
    struct listNode *head = (struct listNode *)malloc(sizeof(struct listNode));
    head->node = (struct treeNode *)malloc(sizeof(struct treeNode));
    head->node->c = letters[0];
    head->node->freq = freq[0];
    head->node->left = head->node->right = NULL;

    struct listNode *tempa = head, *temp;
     int i ;
    for( i = 1; i < n; i++) {
        temp = (struct listNode *)malloc(sizeof(struct listNode));
        temp->node = (struct treeNode *)malloc(sizeof(struct treeNode));
        temp->node->c = letters[i];
        temp->node->freq = freq[i];
        temp->node->left = temp->node->right = NULL;
        tempa->next = temp;
        tempa = temp;
    }
    tempa->next = NULL;
    return head;
}
struct treeNode *buildTree(struct listNode *head) {
    while(head->next != NULL && head != NULL) {
        struct listNode *temp = head, *temp1 = head->next;
        head = temp1->next;
        //printf("Temp: %d Temp1: %d\n", temp->node->freq, temp1->node->freq);
        //if(temp1->node->freq == 30) printf("%d\n", head);
        struct treeNode *internal = (struct treeNode *)malloc(sizeof(struct treeNode));
        internal->freq = temp->node->freq + temp1->node->freq;
        internal->left = temp->node;
        internal->right = temp1->node;
        temp->node = internal;
//      printf("%d\n", internal->freq);
        struct listNode *prev = head, *curr = head;
        while(curr != NULL && curr->next != NULL && temp->node->freq > curr->next->node->freq) {
            curr = curr->next;
            prev = curr;
        }
        if(head == NULL) {
            return internal;
        }
        if(temp->node->freq > curr->node->freq) {
            temp->next = curr->next;
            curr->next = temp;
        }
        else if(prev == head) {
            temp->next = prev;
            head = temp;
        }
        else {
            temp->next = prev->next;
            prev->next = temp;
        }
    }
    return NULL;
}

void buildCodes(struct treeNode *root, struct header *c, int i, int *iter, int isLeft) {

    if(root->left == NULL || root->right == NULL){

        if(isLeft == 1) {
            c->chars[*iter] = root->c;
            c->code[*iter] = i;
            *iter = *iter + 1;
            return;
        }
        else {
            c->chars[*iter] = root->c;
            c->code[*iter] = i;
            *iter = *iter + 1;
            return;
        }
    }
    else{
        buildCodes(root->left, c, i*10, iter, 1);
        buildCodes(root->right, c, i*10+1, iter, 0);
    }
}
void incrementOccurrence(char c, struct header *temp) {
    int i = 0;
    for(i = 0; i < temp->length; i++) {
        if(c == temp->chars[i]){
            break;
        }
    }

    temp->chars[i] = c;
    temp->code[i] += 1;
    if(i == temp->length) temp->length += 1;
}

struct header *buildFrequencyList(char str[]){
    struct header *temp = (struct header *)malloc(sizeof(struct header));
    temp->length = 0;
    memset(temp->code, 0, 50);
     int i ;
    for( i = 0; i < strlen(str); i++) {
        incrementOccurrence(str[i], temp);
    }
    temp->length -= 1;
}

void bSort(struct header *temp) {
    int code,i,j;
    char c;
    for( i = 0; i < temp->length; i++) {
        for(  j = 0; j < temp->length - 1; j++) {
            if(temp->code[j] > temp->code[j+1]) {
                code = temp->code[j];
                temp->code[j] = temp->code[j+1];
                temp->code[j+1] = code;
                c = temp->chars[j];
                temp->chars[j] = temp->chars[j+1];
                temp->chars[j+1] = c;
            }
        }
    }
}

char code[10000];

char *codeForChar(char c, struct header *temp){
    int i ;
    for(i = 0; i < temp->length; i++) {
        if(c == temp->chars[i]){
            sprintf(code, "%d", temp->code[i]);
            memmove(code, code+1, strlen(code));
            return code;
        }
    }
}

void printEncodedData(char str[], struct header *temp) {
    char coded[10000];
    printf("Encoded bitstring: ");
     int i ;
    for( i = 0; i < strlen(str) - 1; i++) {
        printf("%s", codeForChar(str[i], temp));
        //strcat(coded, codeForChar(str[i], temp));
    }
   // printf("%s", coded);
}

void decodeBitString(char str[], struct treeNode *root) {
    struct treeNode *curr = root;
     int i ;
    for( i = 0; i < strlen(str); i++){
        if(curr->left == NULL){
            printf("%c", curr->c);
            curr = root;
        }
        if(str[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
    }
}

int main()
{
    int a;
    struct header *temp = NULL, c;
    struct listNode *head1 = NULL;
    struct treeNode *h = NULL;
    char str[10000];
    fgets(str, 10000, stdin);
    temp = buildFrequencyList(str);
    bSort(temp);
    head1 = buildListNodes(temp->chars, temp->code, temp->length);
    int iter = 0;
    h = buildTree(head1);
    buildCodes(h, &c, 1, &iter, 0);
    c.length = temp->length;
    printEncodedData(str, &c);
}

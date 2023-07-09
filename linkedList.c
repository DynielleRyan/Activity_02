#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list) {
    *list = NULL;
}

List newList() {
    List list;
    initList(&list);
    return list;
}

NodeType createNode(DATA data) {
    NodeType node = (NodeType)malloc(sizeof(NodeType));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

void displayList(List list) {
    NodeType currentNode = list;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

bool insertFront(List *list, DATA item) {
    NodeType newNode = createNode(item);
    if (newNode == NULL) {
        return false;
    }
    newNode->next = *list;
    *list = newNode;
    return true;
}

bool insertRear(List *list, DATA item) {
    NodeType newNode = createNode(item);
    if (newNode == NULL) {
        return false;
    }
    if (*list == NULL) {
        *list = newNode;
    } else {
        NodeType currentNode = *list;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    return true;
}

bool insertAt(List *list, DATA item, int loc) {
    if (loc < 0) {
        return false;
    }
    if (loc == 0) {
        return insertFront(list, item);
    }
    NodeType newNode = createNode(item);
    if (newNode == NULL) {
        return false;
    }
    NodeType currentNode = *list;
    int currentLoc = 0;
    while (currentNode != NULL && currentLoc < loc - 1) {
        currentNode = currentNode->next;
        currentLoc++;
    }
    if (currentNode == NULL) {
        return false;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return true;
}

bool insertSorted(List *list, DATA data) {
    NodeType newNode = createNode(data);
    if (newNode == NULL) {
        return false;
    }
    if (*list == NULL || data < (*list)->data) {
        newNode->next = *list;
        *list = newNode;
    } else {
        NodeType currentNode = *list;
        while (currentNode->next != NULL && data >= currentNode->next->data) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    return true;
}

bool searchItem(List list, DATA key) {
    NodeType currentNode = list;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

int getItem(List list, DATA key) {
    NodeType currentNode = list;
    int index = 0;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            return index;
        }
        currentNode = currentNode->next;
        index++;
    }
    return -1;
}

bool deleteFront(List *list) {
    if (*list == NULL) {
        return false;
    }
    NodeType nodeToRemove = *list;
    *list = (*list)->next;
    free(nodeToRemove);
    return true;
}

bool deleteRear(List *list) {
    if (*list == NULL) {
        return false;
    }
    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return true;
    }
    NodeType currentNode = *list;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }
    NodeType nodeToRemove = currentNode->next;
    currentNode->next = NULL;
    free(nodeToRemove);
    return true;
}

int deleteAt(List *list, int loc) {
    if (loc < 0 || *list == NULL) {
        return -1;
    }
    if (loc == 0) {
        deleteFront(list);
        return 0;
    }
    NodeType currentNode = *list;
    int currentLoc = 0;
    while (currentNode != NULL && currentLoc < loc - 1) {
        currentNode = currentNode->next;
        currentLoc++;
    }
    if (currentNode == NULL || currentNode->next == NULL) {
        return -1;
    }
    NodeType nodeToRemove = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(nodeToRemove);
    return loc;
}

bool deleteItem(List *list, DATA key) {
    if (*list == NULL) {
        return false;
    }
    if ((*list)->data == key) {
        deleteFront(list);
        return true;
    }
    NodeType currentNode = *list;
    while (currentNode->next != NULL && currentNode->next->data != key) {
        currentNode = currentNode->next;
    }
    if (currentNode->next == NULL) {
        return false;
    }
    NodeType nodeToRemove = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(nodeToRemove);
    return true;
}

int deleteAllItem(List *list, DATA key) {
    if (*list == NULL) {
        return 0;
    }
    int count = 0;
    while (*list != NULL && (*list)->data == key) {
        deleteFront(list);
        count++;
    }
    NodeType currentNode = *list;
    while (currentNode != NULL && currentNode->next != NULL) {
        if (currentNode->next->data == key) {
            NodeType nodeToRemove = currentNode->next;
            currentNode->next = currentNode->next->next;
            free(nodeToRemove);
            count++;
        } else {
            currentNode = currentNode->next;
        }
    }
    return count;
}

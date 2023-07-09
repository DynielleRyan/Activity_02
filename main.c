#include <stdio.h>
#include "LinkedList.h"

int main() {
    List myList = newList();

   
    insertFront(&myList, 10);
    insertFront(&myList, 20);
    insertRear(&myList, 30);
    insertAt(&myList, 40, 1);
    insertSorted(&myList, 25);

    printf("List after insertion: ");
    displayList(myList);

    DATA key = 30;
    if (searchItem(myList, key)) {
        printf("%d is found in the list.\n", key);
    } else {
        printf("%d is not found in the list.\n", key);
    }

    int index = getItem(myList, 40);
    if (index != -1) {
        printf("Index of 40: %d\n", index);
    } else {
        printf("40 is not found in the list.\n");
   
    deleteFront(&myList);
    deleteRear(&myList);
    deleteItem(&myList, 30);

    printf("List after deletion: ");
    displayList(myList);

   
    int deletedCount = deleteAllItem(&myList, 25);
    printf("Deleted %d occurrences of 25 from the list.\n", deletedCount);

    printf("Final list: ");
    displayList(myList);

    return 0;
}

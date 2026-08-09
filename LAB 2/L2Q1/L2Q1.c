#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// --- Helper Print Functions ---

void print_array(int arr[], int size) {
    printf("[ ");
    if (size <= 10) {
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    } else {
        printf("%d %d %d ... %d %d %d ", arr[0], arr[1], arr[2], arr[size - 3], arr[size - 2], arr[size - 1]);
    }
    printf("] (Size: %d)\n", size);
}

void print_list(Node* head) {
    printf("[ ");
    Node* curr = head;
    int count = 0;
    while (curr) { count++; curr = curr->next; }

    curr = head;
    if (count <= 10) {
        while (curr) { printf("%d ", curr->data); curr = curr->next; }
    } else {
        for (int i = 0; i < 3 && curr; i++) { printf("%d ", curr->data); curr = curr->next; }
        printf("... ");
        while (curr && curr->next && curr->next->next) curr = curr->next;
        while (curr) { printf("%d ", curr->data); curr = curr->next; }
    }
    printf("] (Size: %d)\n", count);
}

// --- Array Operations ---

int search_unsorted_array(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int search_sorted_array(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void insert_unsorted_array(int arr[], int* size, int val) {
    arr[(*size)++] = val;
}

void insert_sorted_array(int arr[], int* size, int val) {
    int i = *size - 1;
    while (i >= 0 && arr[i] > val) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = val;
    (*size)++;
}

void delete_unsorted_array(int arr[], int* size, int val) {
    int idx = search_unsorted_array(arr, *size, val);
    if (idx != -1) {
        arr[idx] = arr[*size - 1];
        (*size)--;
        printf("Deleted from Unsorted Array.\n");
    } else {
        printf("Not found in Unsorted Array.\n");
    }
}

void delete_sorted_array(int arr[], int* size, int val) {
    int idx = search_sorted_array(arr, *size, val);
    if (idx != -1) {
        for (int i = idx; i < *size - 1; i++) arr[i] = arr[i + 1];
        (*size)--;
        printf("Deleted from Sorted Array.\n");
    } else {
        printf("Not found in Sorted Array.\n");
    }
}

// --- Linked List Operations ---

void insert_singly_unsorted(Node** head, int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}

void insert_singly_sorted(Node** head, int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= val) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL && curr->next->data < val) curr = curr->next;
    new_node->next = curr->next;
    curr->next = new_node;
}

Node* search_list(Node* head, int key) {
    Node* curr = head;
    while (curr) {
        if (curr->data == key) return curr;
        curr = curr->next;
    }
    return NULL;
}

void delete_singly(Node** head, int val) {
    if (*head == NULL) return;
    if ((*head)->data == val) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Deleted from Singly List.\n");
        return;
    }
    Node* curr = *head;
    while (curr->next && curr->next->data != val) curr = curr->next;
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        printf("Deleted from Singly List.\n");
    } else {
        printf("Not found in Singly List.\n");
    }
}

void insert_doubly_unsorted(Node** head, int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head != NULL) (*head)->prev = new_node;
    *head = new_node;
}

void insert_doubly_sorted(Node** head, int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL) { *head = new_node; return; }
    if ((*head)->data >= val) {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    Node* curr = *head;
    while (curr->next && curr->next->data < val) curr = curr->next;
    new_node->next = curr->next;
    new_node->prev = curr;
    if (curr->next) curr->next->prev = new_node;
    curr->next = new_node;
}

void delete_doubly(Node** head, int val) {
    Node* target = search_list(*head, val);
    if (!target) {
        printf("Not found in Doubly List.\n");
        return;
    }
    if (*head == target) *head = target->next;
    if (target->next) target->next->prev = target->prev;
    if (target->prev) target->prev->next = target->next;
    free(target);
    printf("Deleted from Doubly List.\n");
}

// --- Main Program ---

int main() {
    int n, choice, val, k, mode;

    printf("Enter number of elements (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int* unsorted_arr = malloc((n + 1000) * sizeof(int));
    int* sorted_arr = malloc((n + 1000) * sizeof(int));
    int size_unsorted = n, size_sorted = 0;

    Node* singly_unsorted = NULL;
    Node* singly_sorted = NULL;
    Node* doubly_unsorted = NULL;
    Node* doubly_sorted = NULL;

    printf("\n1. Manual Input\n2. Auto Generate\nChoice: ");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("Enter %d integers: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            unsorted_arr[i] = val;
            insert_sorted_array(sorted_arr, &size_sorted, val);
            insert_singly_unsorted(&singly_unsorted, val);
            insert_singly_sorted(&singly_sorted, val);
            insert_doubly_unsorted(&doubly_unsorted, val);
            insert_doubly_sorted(&doubly_sorted, val);
        }
    } else {
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; i++) {
            val = rand() % 10000;
            unsorted_arr[i] = val;
            insert_sorted_array(sorted_arr, &size_sorted, val);
            insert_singly_unsorted(&singly_unsorted, val);
            insert_singly_sorted(&singly_sorted, val);
            insert_doubly_unsorted(&doubly_unsorted, val);
            insert_doubly_sorted(&doubly_sorted, val);
        }
        printf("Generated %d elements.\n", n);
    }

    while (1) {
        printf("\n------------------------------------\n");
        printf("1. Display All\n2. Search Key\n3. Insert Item\n4. Delete Item\n5. Min & Max\n6. Predecessor & Successor\n7. Exit\n");
        printf("Choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) break;

        switch (choice) {
            case 1:
                printf("\n1. Unsorted Array:       "); print_array(unsorted_arr, size_unsorted);
                printf("2. Sorted Array:         "); print_array(sorted_arr, size_sorted);
                printf("3. Singly List Unsorted: "); print_list(singly_unsorted);
                printf("4. Singly List Sorted:   "); print_list(singly_sorted);
                printf("5. Doubly List Unsorted: "); print_list(doubly_unsorted);
                printf("6. Doubly List Sorted:   "); print_list(doubly_sorted);
                break;

            case 2:
                printf("Enter search key k: ");
                scanf("%d", &k);

                int idx1 = search_unsorted_array(unsorted_arr, size_unsorted, k);
                int idx2 = search_sorted_array(sorted_arr, size_sorted, k);
                Node* s_res = search_list(singly_unsorted, k);

                printf("\nUnsorted Array Search : Index %d\n", idx1);
                printf("Sorted Array Search   : Index %d\n", idx2);
                printf("Singly Unsorted Search: %s\n", s_res ? "Found" : "Not Found");
                printf("Singly Sorted Search  : %s\n", search_list(singly_sorted, k) ? "Found" : "Not Found");
                printf("Doubly Unsorted Search: %s\n", search_list(doubly_unsorted, k) ? "Found" : "Not Found");
                printf("Doubly Sorted Search  : %s\n", search_list(doubly_sorted, k) ? "Found" : "Not Found");
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_unsorted_array(unsorted_arr, &size_unsorted, val);
                insert_sorted_array(sorted_arr, &size_sorted, val);
                insert_singly_unsorted(&singly_unsorted, val);
                insert_singly_sorted(&singly_sorted, val);
                insert_doubly_unsorted(&doubly_unsorted, val);
                insert_doubly_sorted(&doubly_sorted, val);
                printf("Inserted %d into all structures.\n", val);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_unsorted_array(unsorted_arr, &size_unsorted, val);
                delete_sorted_array(sorted_arr, &size_sorted, val);
                delete_singly(&singly_unsorted, val);
                delete_singly(&singly_sorted, val);
                delete_doubly(&doubly_unsorted, val);
                delete_doubly(&doubly_sorted, val);
                break;

            case 5:
                if (size_sorted == 0) printf("Dictionary is empty.\n");
                else printf("Min: %d | Max: %d\n", sorted_arr[0], sorted_arr[size_sorted - 1]);
                break;

            case 6:
                printf("Enter element x: ");
                scanf("%d", &val);
                Node* ptr = search_list(doubly_sorted, val);
                if (!ptr) {
                    printf("Element %d not found.\n", val);
                } else {
                    printf("Predecessor: %s\n", ptr->prev ? "Found" : "None (Smallest)");
                    if (ptr->prev) printf(" -> %d\n", ptr->prev->data);
                    printf("Successor: %s\n", ptr->next ? "Found" : "None (Largest)");
                    if (ptr->next) printf(" -> %d\n", ptr->next->data);
                }
                break;
        }
    }

    free(unsorted_arr);
    free(sorted_arr);
    return 0;
}

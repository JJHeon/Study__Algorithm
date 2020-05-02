#ifndef __DOUBLY_LINKED_LIST_H_
#define __DOUBLY_LINKED_LIST_H_
/*
ListDoublyLinked => LD

완벽하게 구현된 상태가 아님.
이 리스트를 잘 활용하기 위해서는 프로그램이 어느쪽으로 탐색하는 것이 더 빠른지 알 수 있는 방법이 필요하다.
따라서 정렬 알고리즘으로 정렬된 상태를 유지해서 Search method의 속도를 빠르게 하거나(1번)
기타 등등으로 처리하거나(2번)

현재는 정렬이 표함되어 있지 않고 사실상 Singly, Circular과 기능은 다를바가 없지만
단지 현재 노드 next, prev를 좀 더 편한 방식으로 알 수 있다는 점이 다르다.

원형이 아님으로 처음과 끝은 NULL로 처리한다.
*/

typedef int LD_Element;
typedef struct LD_Node {
    LD_Element data;
    struct LD_Node* prev;
    struct LD_Node* next;
} LD_Node;

LD_Node* LD__CreateNode(LD_Element data);
LD_Node* LD__Search(LD_Node* object, LD_Element data);

void LD__MemoryFree(LD_Node* object);
void LD__Display(LD_Node* object);
void LD__Insert(LD_Node** phead, LD_Node* pre, LD_Node* new_node);

#endif

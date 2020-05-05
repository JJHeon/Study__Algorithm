#include "Test_Control.h"
#if ___HEAP_EXAMPLE

#include "Heap_Example.h"


void InitHeap(Heap_* obj) {
    memset(obj, 0, sizeof(Heap_));
}


void InsertMinHeap(Heap_* obj, Node_ item) {
    int i = ++obj->heap_point;
    for (; ((i != 1) && (item.key < obj->heap[i / 2].key)); i /= 2) {
        obj->heap[i] = obj->heap[i / 2];
    }
    obj->heap[i] = item;
}
Node_ DeleteMinHeap(Heap_* obj) {
    Node_ item = obj->heap[1];
    Node_ temp = obj->heap[obj->heap_point--];
    int parent = 1, child = 2;
    while (child <= obj->heap_point) {
        if ((child < obj->heap_point) && (obj->heap[child].key > obj->heap[child + 1].key))
            child++;
        if (temp.key <= obj->heap[child].key)
            break;
        obj->heap[parent] = obj->heap[child];
        parent = child;
        child *= 2;
    }
    obj->heap[parent] = temp;
    return item;
}

void PrintHeap(Heap_* obj) {
    int j = 1, space_gap = 0;
    int rate = 2, per = 2;
    int l = 0;
    while (j < obj->heap_point) {
        j += rate;
        rate *= 2;
    }
    space_gap = (j + 1) * 2;
    rate = 2;
    j = 1;

    for (int i = 1; i <= obj->heap_point; i++) {
        for (int k = 0; k < space_gap / per; k++) {
            printf(" ");
        }
        printf("%d", obj->heap[i].key);

        if (i == j) {
            printf("\n");
            j += rate;
            rate *= 2;
            per += Power_R(2, l++);
        }
    }
    printf("\n");
}

bool IsEmptyHeap(Heap_* obj) {
    if (obj->heap_point == 0)
        return true;
    else
        return false;
}


//아이스크림 가게 시뮬레이션

int free_seats = 10;
double profit = 0.0;

int random(int n){
    return (int)(n * rand() / (double)RAND_MAX);
}
bool is_seat_available(int num){
    printf("%d명의 고객 도착\n", num);
    if(free_seats >= num){
        free_seats -= num;
        return true;
    }else{
        printf("자리가 없어서 떠남\n");
        return false;
    }
}
void order(int scoops){
    printf("아이스크림 %d개 주문 받음\n", scoops);
    profit += 0.35 * scoops;
}
void leave(int number){
    printf("%d명이 매장을 떠남\n", number);
    free_seats += number;
}
void process_event(Heap_* heap, Node_ e){
    int i = 0;
    Node_ new_event;

    printf("현재시간 = %d\n", e.key);
    switch(e.type){
        case ARRIVAL:
        if(is_seat_available(e.number)){
            new_event.type = ORDER;
            new_event.key = e.key + 1 + random(4);
            new_event.number = e.number;
            InsertMinHeap(heap, new_event);
        }
        break;
        case ORDER:
            //사람 수만큼 주문을 받는다.
            for (i = 0; i < e.number; i++){
                order(1 + random(3));
            }
            //매장을 떠나는 이벤트를 생성한다.
            new_event.type = LEAVE;
            new_event.key = e.key + 1 + random(10);
            new_event.number = e.number;
            InsertMinHeap(heap, new_event);
            break;

        case LEAVE:
            //고객이 떠나면 빈자리 수를 증가시킨다.
            leave(e.number);
            break;
    }
}

#endif
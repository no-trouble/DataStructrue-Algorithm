//
//  main.cpp
//  Queue
//
//  Created by lishuai on 2018/10/31.
//  Copyright © 2018 lishuai. All rights reserved.
//

#include <iostream>
#include "LinkQueue.hpp"
#include "SeqQueue.hpp"

using namespace std;

void linkQueueTest();
void seqQueueTest();

int main(int argc, const char * argv[]) {
//    linkQueueTest();
    seqQueueTest();
    return 0;
}

void seqQueueTest() {
    SeqQueue *queue = SeqQ_Init();
    SeqQ_Put(queue, 1);
    SeqQ_Put(queue, 2);
    SeqQ_Put(queue, 3);
    SeqQ_Put(queue, 4);
    SeqQ_Print(*queue);
    int e1, e2;
    SeqQ_GetHead(*queue, e1);
    SeqQ_Poll(queue, e2);
    cout << "queue head: " << e1 << endl;
    cout << "poll: " << e2 << endl;
    SeqQ_Print(*queue);

    SeqQ_Put(queue, 5);
    cout << "put: " << 5 << endl;
    SeqQ_Print(*queue);
    
//    SeqQ_Poll(queue, e1);
//
//    SeqQ_Put(queue, 6);
//    cout << "queue length: " << SeqQ_Length(*queue) << endl;
//    cout << "queue front: " << queue->front << "\t" << "queue rear: " << queue->rear << endl;

    
    
}

void linkQueueTest() {
    LinkQueue *queue = Q_Init();
    Q_Put(queue, 1);
    Q_Put(queue, 2);
    Q_Put(queue, 3);
    Q_Put(queue, 4);
    Q_Print(*queue);
    cout << "queue empty: " << Q_Empty(*queue) << endl;
    cout << "queue length: " << Q_Length(*queue) << endl;
    int e1, e2;
    Q_GetHead(*queue, e2);
    Q_Poll(queue, e1);
    cout << "queue poll: " << e1 << endl;
    cout << "queue head: " << e2 << endl;
    Q_Clear(queue);
    Q_Print(*queue);
}

/*
 node1 node2 node3 node4 node5
 front->next = node1
 rear->next = null

 */

//
//  SeqQueue.cpp
//  Queue
//
//  Created by lishuai on 2018/10/31.
//  Copyright © 2018 lishuai. All rights reserved.
//

#include "SeqQueue.hpp"
#include <iostream>
using namespace std;

SeqQueue *SeqQ_Init() {
    SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
    if (!queue) {
        exit(0);
    }
    queue->base = (int *)malloc(sizeof(int) * MAX_QSIZE);
    if (!queue->base) {
        exit(0);
    }
    queue->front = queue->rear = 0;
    return queue;
}

void SeqQ_Destroy(SeqQueue *Q) {
    if (Q->base) {
        free(Q->base);
    }
    Q->base = NULL;
    Q->front = Q->rear = 0;
    free(Q);
}

void SeqQ_Clear(SeqQueue *Q) {
    Q->front = Q->rear = 0;
}

int SeqQ_Empty(SeqQueue Q) {
    return Q.front == Q.rear ? 1 : -1;
}

int SeqQ_Length(SeqQueue Q) {
    return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
}

void SeqQ_Print(SeqQueue Q) {
    int i = Q.front;
    cout << "data is: " << endl;
    while (Q.rear != i) {
        cout << Q.base[i] << "\t";
        /*
         wiki 在 Q_Print() 函数的实现中，while 内的原语句为 p += 1;
         https://zh.wikipedia.org/wiki/%E9%98%9F%E5%88%97#%E5%BE%AA%E7%8E%AF%E9%98%9F%E5%88%97
         */
        i = (i + 1) % MAX_QSIZE;
    }
    cout << endl;
    cout << "queue front: " << Q.front << "\t" << "rear: " << Q.rear << "\t" << "length: " << SeqQ_Length(Q) << endl;
}

int SeqQ_GetHead(SeqQueue Q, int &e) {
    if (Q.front == Q.rear) { /// 队空
        cout << "队列为空" << endl;
        return -1;
    }
    e = Q.base[Q.front];
    return 1;
}

int SeqQ_Put(SeqQueue *Q, int e) {
    if ((Q->rear + 1) % MAX_QSIZE == Q->front) { /// 队满
        cout << "队列已满" << endl;
        return -1;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_QSIZE;
    return 1;
}

int SeqQ_Poll(SeqQueue *Q, int &e) {
    if (Q->front == Q->rear) {
        cout << "队列已空" << endl;
        return -1;
    }
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAX_QSIZE;
    return 1;
}

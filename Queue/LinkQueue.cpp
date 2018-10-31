//
//  LinkQueue.cpp
//  Queue
//
//  Created by lishuai on 2018/10/31.
//  Copyright © 2018 lishuai. All rights reserved.
//

#include "LinkQueue.hpp"
#include <iostream>
using namespace std;

LinkQueue* Q_Init() {
    LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (!Q) {
        exit(0);
    }
    Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));
    if (!Q->front) {
        exit(0);
    }
    Q->front->next = NULL;
    return Q;
}

void Q_Destroy(LinkQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    free(Q);
}

void Q_Clear(LinkQueue *Q) {
    QNodePtr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
}

int Q_Empty(LinkQueue Q) {
    if (Q.front->next == NULL) {
        return 1;
    }
    return -1;
}

int Q_Length(LinkQueue Q) {
    int i = 0;
    QNodePtr p = Q.front;
    while (Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

void Q_Print(LinkQueue Q) {
    int i = 0;
    QNodePtr p = Q.front;
    while (Q.rear != p) {
        i++;
        p = p->next;
        cout << "data is " << p->data << endl;
    }
}

int Q_GetHead(LinkQueue Q, int &e) {
    if (Q.front == Q.rear) {
        return -1;
    }
    e = Q.front->next->data;
    return 1;
}

void Q_Put(LinkQueue *Q, int e) {
    QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
    if (!p) {
        exit(0);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; /// 连接队尾前一个节点和队尾节点
    Q->rear = p; /// 将新节点赋值给队列的尾节点
}
int Q_Poll(LinkQueue *Q, int &e) {
    if (Q->front == Q->rear) {
        return -1;
    }
    QNodePtr p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return 1;
}

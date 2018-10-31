//
//  LinkQueue.hpp
//  Queue
//
//  Created by lishuai on 2018/10/31.
//  Copyright © 2018 lishuai. All rights reserved.
//

#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include <stdio.h>

typedef struct QNode {
    int data;
    QNode *next;
}QNode, *QNodePtr;

typedef struct LinkQueue {
    QNodePtr front, rear;
} LinkQueue;

LinkQueue* Q_Init();

void Q_Destroy(LinkQueue *Q);

void Q_Clear(LinkQueue *Q);

int Q_Empty(LinkQueue Q);

int Q_Length(LinkQueue Q);

void Q_Print(LinkQueue Q);

int Q_GetHead(LinkQueue Q, int &e);

void Q_Put(LinkQueue *Q, int e);

int Q_Poll(LinkQueue *Q, int &e);

#endif /* LinkQueue_hpp */

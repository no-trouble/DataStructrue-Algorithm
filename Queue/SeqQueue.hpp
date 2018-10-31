//
//  SeqQueue.hpp
//  Queue
//
//  Created by lishuai on 2018/10/31.
//  Copyright © 2018 lishuai. All rights reserved.
//

#ifndef SeqQueue_hpp
#define SeqQueue_hpp

#include <stdio.h>

#define MAX_QSIZE 5
typedef struct SeqQueue {
    int *base;
    int front;
    int rear;
}SeqQueue;

SeqQueue *SeqQ_Init();

void SeqQ_Destroy(SeqQueue *Q);

void SeqQ_Clear(SeqQueue *Q);

int SeqQ_Empty(SeqQueue Q);

int SeqQ_Length(SeqQueue Q);

void SeqQ_Print(SeqQueue Q);

int SeqQ_GetHead(SeqQueue Q, int &e);

int SeqQ_Put(SeqQueue *Q, int e);

int SeqQ_Poll(SeqQueue *Q, int &e);

#endif /* SeqQueue_hpp */

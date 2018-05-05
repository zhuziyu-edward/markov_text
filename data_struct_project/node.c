//
//  node.c
//  data_struct_project
//
//  Created by Edward dawson on 05/05/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#include "node.h"

double seed = 997;

double rrand()
{
    double lambda = 3125.0;
    double m = 34359738337.0;
    double r;
    seed = fmod(lambda*seed, m); //要包含头文件#include <math.h>
    r = seed / m;
    return r;
}

void nodeCpy(node *x, node *y)
{
    strcpy(x->prefix1, y->prefix1);
    strcpy(x->prefix2, y->prefix2);
    x->lChild = y->lChild;
    x->rChild = y->rChild;
    x->height = y->height;
    if(y->suffix == NULL)
        x->suffix = NULL;
    else
    {
        x->suffix = (word*) malloc(sizeof(word));
        strcpy(x->suffix->s, y->suffix->s);
        x->suffix->next = NULL;
        word *rearX = x->suffix, *rearY = y->suffix->next;
        while(rearY != NULL)
        {
            rearX->next = (word*) malloc(sizeof(word));
            rearX = rearX->next;
            strcpy(rearX->s, rearY->s);
            rearX->next = NULL;
            rearY = rearY->next;
        }
        
    }
    
}

int  nodeCmp(node *x, node *y)
{
    int v1 = strcmp(x->prefix1, y->prefix1);
    if(v1 > 0)
        return 1;
    else if(v1 < 0)
        return -1;
    else
    {
        int v2 = strcmp(x->prefix2, y->prefix2);
        if(v2 > 0)
            return 1;
        else if(v2 < 0)
            return -1;
        else
            return 0;
    }
}

int getH(node *x)
{
    return x != NULL ? x->height : 0;
}

int getSuffixLen(node *x)
{
    if(x == NULL)
        return 0;
    word *rear = x->suffix;
    int ans = 0;
    while(rear != NULL)
    {
        ans++;
        rear = rear->next;
    }
    return ans;
}

word *getNthSuffix(node *x, int n)
{
    if(x == NULL)
        return NULL;
    word *rear = x->suffix;
    while(--n)
        rear = rear->next;
    return rear;
}

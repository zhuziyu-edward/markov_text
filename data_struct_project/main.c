//
//  main.c
//  data_struct_project
//
//  Created by Edward dawson on 30/04/2018.
//  Copyright © 2018 ziyu zhu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
     //定义所有变量
    FILE *inFile, *outFile;
    char firstWord[MAXWORDLEN], secondWord[MAXWORDLEN];
    node *root = NULL, *tmp = (node*) malloc (sizeof(node)), inNode, *result;
    word *suffix;
    int len, n, maxWord;
    
    //文件初始化， 并且读入前两个单词
    scanf("%d", &maxWord);
    maxWord -= 2;
    inFile = fopen("article.txt", "r");
    outFile = fopen("markov.txt", "w");
    fscanf(inFile, "%s", firstWord);
    fscanf(inFile, "%s", secondWord);
    strcpy(tmp->prefix1, firstWord);
    strcpy(tmp->prefix2, secondWord);

    //初始化 tmp
    tmp->suffix = (word*) malloc(sizeof(word));
    tmp->suffix->next = NULL;
    tmp->height = 0;
    tmp->lChild = NULL, tmp->rChild = NULL;
    
    //读入所有单词， 并且插入
    while(fscanf(inFile, "%s", tmp->suffix->s) != EOF)    {
        root = insert(tmp, root);
        strcpy(tmp->prefix1, tmp->prefix2);
        strcpy(tmp->prefix2, tmp->suffix->s);
    }
    *(tmp->suffix->s) = '\0';
    root = insert(tmp, root);

    //开始搜索， 并且输出后缀
    strcpy(inNode.prefix1, firstWord);
    strcpy(inNode.prefix2, secondWord);
    fprintf(outFile, "%s %s ", firstWord, secondWord);
    while(maxWord--)
    {
        result = find(&inNode, root);
        len = getSuffixLen(result);
        if(len > 1)
            n = (int)(rrand() * len) + 1;
        else
            n = 1;
        suffix = getNthSuffix(result, n);
        if(strlen(suffix->s) == 0)
            break;
        fprintf(outFile, "%s ", suffix->s);
        strcpy(inNode.prefix1, result->prefix2);
        strcpy(inNode.prefix2, suffix->s);
    }
    
    //关闭文件 释放内存
    fclose(inFile);
    fclose(outFile);
    return 0;
}

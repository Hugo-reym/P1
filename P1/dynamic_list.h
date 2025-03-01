/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Hugo Rey Montoliu LOGIN 1: hugo.reym
 * AUTHOR 2: Daniel Alaimo Garcia LOGIN 2: d.alaimo
 * GROUP: 6.1
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdbool.h>
#define LNULL NULL
//typedef int tItemL; (esto lo tengo copiado pero da error así que creo que está mal
typedef struct tNode *tPosL;
struct tNode {
  tItemL data;
  tPosL next;
};
typedef tPosL tList;
void createEmptyList(tList *L);
bool createNode(tPosL p);
bool insertItem(tItemL d, tPosL p, tList *L);
bool CopyList(tList L, tList *M);
bool CopyListR(tList L, tList *M); //This is recursive
void deleteAtPosition(tPosL p, tList *L);
bool isEmptyList(tList L);
tPosL last(tList L);
tPosL first(tList L);
tPosL previous(tPosL p, tList L);
void updateItem(tItemL d, tPosL p, tList *L);
tPosL next(tPosL p, tList L);
tPosL findItem(tConsoleId d,tList L);
tItemL getItem(tPosL p, tList L);
#endif

/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Hugo Rey Montoliu LOGIN 1: hugo.reym
 * AUTHOR 2: Daniel Alaimo Garcia LOGIN 2: d.alaimo
 * GROUP: 6.1
 * DATE: ** / ** / **
 */
#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#include "types.h"
#include <stdbool.h>
#define LNULL (-1)

typedef int tPosL;
typedef struct list tList;
struct list {
 tPosL posl;
 tItemL items[25];
};

void createEmptyList(tList* l);
bool isEmptyList(tList l);
tPosL first(tList l);
tPosL last(tList l);
tPosL next(tPosL pos,tList l);
tPosL previous(tPosL pos,tList l);
bool insertItem (tItemL i, tPosL pos, tList* l);
void deleteAtPosition(tPosL pos, tList* l);
tItemL getItem(tPosL pos,tList l);
void updateItem(tItemL item, tPosL pos,tList* l);
tPosL findItem(tConsoleId id,tList l);
#endif

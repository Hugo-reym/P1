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
// Goal: to create a new empty list. 
// PostCD: The list is initialised and has no elements
bool isEmptyList(tList l);
//Goal:Determines whether the list is empty or not.
//PreC:The list must be previously initializated
tPosL first(tList l);
//Goal:Returns the position of the first element of the list.
//PreC:THe list must be previously initializated and is not empty.
tPosL last(tList l);
//Goal:Returns the position of the last element of the list.
//PreC:THe list must be previously initializated and is not empty.
tPosL next(tPosL pos,tList l);
//Goal:Returns the position following the one we indicate (or LNULL if the specified position has no next element).
//PreC:THe list must be previously initializated and the indicated position is a valid one in the list.
tPosL previous(tPosL pos,tList l);
//Goal:Returns the position preceding the one we indicate (or LNULL if the specified position has no previous element)
//PreC:THe list must be previously initializated and the indicated position is a valid one in the list.
bool insertItem (tItemL i, tPosL pos, tList* l);
//Goal:Inserts an element containing the provided data item in the list. If the specified position is LNULL, then the element is added at the end of the list; otherwise, it will 
//be placed right before the element currently holding that position. It the element could be inserted, the value true is returned, false otherwise.
//PreC:The specified position is a valid position in the list or a LNULL position.
//PostC:The positions of the elements in the list following that of the inserted one may have changed.
void deleteAtPosition(tPosL pos, tList* l);
//Goal:Deletes the element at the given position from the list.
//PreC:THe list must be previously initializated and the indicated position is valid in the list.
//PostC:The positions of the elements in the list following that of the deleted one may have changed. 
tItemL getItem(tPosL pos,tList l);
//Goal:Retrieves the content of the element at the position we indicate.
//PreC:The list must be previously initializated and the position is valid in the list.
void updateItem(tItemL item, tPosL pos,tList* l);
//Goal:Modifies the content of the element at the position we indicate.
//PreC:The list must be previously initializated.
//PostCD: The order of the elements in the list has not been modified.
tPosL findItem(tConsoleId *id,tList l);
//Goal:Returns the position of the first element in the list whose console identifier matches the one indicated (or LNULL if there is no such element).
//PreC:The list must be previously initializated.
#endif

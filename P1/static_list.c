/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Hugo Rey Montoliu  LOGIN 1: hugo.reym
 * AUTHOR 2: Daniel Alaimo Garcia LOGIN 2: d.alaimo
 * GROUP: 6.1
 * DATE: ** / ** / **
 */
#include "static_list.h"

#include <stdlib.h>
#define LNULL (-1)
void createEmptyList(tList *l) {
 l->posl=LNULL;
}
bool isEmptyList(tList l) {
 return l.posl==LNULL;
}
tPosL first(tList l) {
 return 0;
}
tPosL last(tList l) {
 return l.posl;
}
tPosL next(tPosL pos,tList l) {
 if(pos==last(l)) {
  return LNULL;
 } else {
  return pos+1;
 }
}
tPosL previous(tPosL pos,tList l) {
 if(pos==0){return LNULL;}
 else{return pos-1;}
}
bool insertItem (tItemL i, tPosL pos, tList* l) {
 if(24==last(*l)) {//we check if the list has all the spaces used
  return false;
 } else {//we add one extra space to insert the new item
  l->posl++;
  if (pos==LNULL) {
   l->items[last(*l)]=i;
  } else {//we use a loop to change the position of the elements of the list when inserting the new item
   for(int j=last(*l);j>pos;j--) {
    l->items[j+1]=l->items[j];
   }
   l->items[pos]=i;
  }
 return true;
 }
}
void deleteAtPosition(tPosL pos, tList* l) {
 for(int i=pos;i<last(*l);i++) {
  l->items[i]=l->items[i+1];
 }
 l->posl--;
}
tItemL getItem(tPosL pos,tList l) {
 return l.items[pos];
}
void updateItem(tItemL item, tPosL pos,tList* l) {
 l->items[pos]=item;
}
tPosL findItem(tConsoleId id,tList l) {
 for (int i=0;i<last(l);i++) {
  if(l.items[i].consoleId==id) {
   return i;
  }
 }
 return LNULL;
}
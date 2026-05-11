#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "Btree.h"

void showMenu();
void processConsoleInput(Btree *&root);
void handleSearch(Btree *root);
void handleDelete(Btree *&root);
void handleSave(Btree *root);
void handleLoad(Btree *&root);
void handleTests(Btree *&root);

#endif
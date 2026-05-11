#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Btree.h"

void saveToFile(Btree* root, const string& filename);
Btree* loadFromFile(const string& filename);

#endif
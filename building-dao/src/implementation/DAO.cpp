/*
 * DAO.cpp
 *
 *  Created on: 24-12-2018
 *      Author: Bartłomiej Płonka
 */

#include "DAO.h"

DAO::DAO(const char * dbName) {
	dbHandle = qdb_connect(dbName, 0);
	if (dbHandle == nullptr) {
	    fprintf(stderr, "Connect failed: %s\n", "ERROR");
	}
}

DAO::~DAO() {
    if (dbHandle == nullptr)
        return;
	int result = qdb_disconnect(dbHandle);
	if (result < 0) {
		fprintf(stderr, "Failed to disconnect from database");
	}
}


/*
 * DAO.cpp
 *
 *  Created on: 24-12-2018
 *      Author: Bartłomiej Płonka
 */

#include "DAO.h"

DAO::DAO(const char * dbName) {
	dbHandle = qdb_connect(dbName, 0);
	if (dbHandle == NULL) {
	    fprintf(stderr, "Connect failed: %s\n", "ERROR");
	}
}

DAO::~DAO() {
	int result = qdb_disconnect(dbHandle);
	if (result < 0) {
		fprintf(stderr, "Failed to disconnect from database");
	}
}


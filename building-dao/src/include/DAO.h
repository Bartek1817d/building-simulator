/*
 * DAO.h
 *
 *  Created on: 24-12-2018
 *      Author: Bartłomiej Płonka
 */

#ifndef DAO_H_
#define DAO_H_

#include <qdb/qdb.h>

class DAO {

//	int rc;
	qdb_hdl_t *dbHandle;

public:
	DAO(const char * dbName);
	virtual ~DAO();
};

#endif /* DAO_H_ */

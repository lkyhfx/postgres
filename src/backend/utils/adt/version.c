/*-------------------------------------------------------------------------
 *
 * version.c
 *	 Returns the PostgreSQL version string
 *
 * Copyright (c) 1998-2024, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *
 * src/backend/utils/adt/version.c
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include "utils/builtins.h"


#if defined(__x86_64__) || defined(_M_X64)
#define POLARDB_COMPAT_ARCH "x86_64"
#elif defined(__aarch64__) || defined(_M_ARM64)
#define POLARDB_COMPAT_ARCH "aarch64"
#else
#define POLARDB_COMPAT_ARCH "unknown"
#endif

#define POLARDB_COMPAT_VERSION_STRING \
	"PostgreSQL 17.9 (PolarDB 17.9.1.0 build unknown) on " \
	POLARDB_COMPAT_ARCH "-linux-gnu"


Datum
pgsql_version(PG_FUNCTION_ARGS)
{
	PG_RETURN_TEXT_P(cstring_to_text(POLARDB_COMPAT_VERSION_STRING));
}

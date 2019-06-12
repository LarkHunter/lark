/*
CH1、Simpleuse
	1、mysql_init(&m_mysql); // Allocates or initializes a MYSQL object suitable for mysql_real_connect(). 

	2、mysql_real_connect() attempts to establish a connection to a MySQL database engine running on host

	3、mysql_close() Closes a previously opened connection. mysql_close() also deallocates the connection handler pointed to by mysql if the handler was allocated automatically by mysql_init() or mysql_connect(). Do not use the handler after it has been closed.

	4、mysql_real_connect  An initialized MYSQL* handler. NULL if there was insufficient memory to allocate a new object.

	5、 mysql_store_result(m_mysql); //A pointer to a MYSQL_RES result structure with the results. NULL if the statement did not return a result set or an error occurred.
	After invoking mysql_query() or mysql_real_query(), you must call mysql_store_result() or mysql_use_result() for every statement that successfully produces a result set (SELECT, SHOW, DESCRIBE, EXPLAIN, CHECK TABLE, and so forth). You must also call mysql_free_result() after you are done with the result set.
	6、mysql_fetch_row

	MYSQL_ROW row;
	unsigned int num_fields;
	unsigned int i;

	num_fields = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result)))
	{
	unsigned long *lengths;
	lengths = mysql_fetch_lengths(result);
	for(i = 0; i < num_fields; i++)
	{
	printf("[%.*s] ", (int) lengths[i],
	row[i] ? row[i] : "NULL");
	}
	printf("\n");
	}

2、SpecialUse

*/
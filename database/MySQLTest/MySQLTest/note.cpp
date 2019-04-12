/*
	1、mysql_init(&m_mysql); // Allocates or initializes a MYSQL object suitable for mysql_real_connect(). 

	2、mysql_real_connect() attempts to establish a connection to a MySQL database engine running on host

	3、mysql_close() Closes a previously opened connection. mysql_close() also deallocates the connection handler pointed to by mysql if the handler was allocated automatically by mysql_init() or mysql_connect(). Do not use the handler after it has been closed.

	4、mysql_real_connect  An initialized MYSQL* handler. NULL if there was insufficient memory to allocate a new object.
*/
#!/bin/bash
#set -eux

service mariadb start
if [ ! -d /var/lib/mysql/${SQL_DATABASE} ]; then
	touch data.sql;
	echo "USE mysql;" >> data.sql;
	echo "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};" >> data.sql;
	echo "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';" >> data.sql;
	echo "GRANT ALL PRIVILEGES ON ${SQL_DATABASE}.* TO '${SQL_USER}'@'%';" >> data.sql;
	echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';" >> data.sql;
	echo "FLUSH PRIVILEGES;" >> data.sql;
	mysql -u root -p${SQL_ROOT_PASSWORD} < data.sql
fi

mysqladmin -u root -p${SQL_ROOT_PASSWORD} shutdown
mysqld

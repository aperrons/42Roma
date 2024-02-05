#!/bin/bash

mkdir etc/mysql/utils
echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE_NAME ;" > etc/mysql/utils/db.sql
echo "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD' ;" >> etc/mysql/utils/db.sql
echo "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE_NAME.* TO '$MYSQL_USER'@'%' ;" >> etc/mysql/utils/db.sql
echo "FLUSH PRIVILEGES ;" >> etc/mysql/utils/db.sql
service mysql start
mysql -h localhost < etc/mysql/utils/db.sql
#mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD
kill $(cat /var/run/mysqld/mysqld.pid)
mysqld

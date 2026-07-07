#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d /var/lib/mysql/mysql ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    cat > /tmp/init.sql << EOF
USE mysql;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MYSQL_NAME};
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '$(cat /run/secrets/db_password)';
GRANT ALL PRIVILEGES ON ${MYSQL_NAME}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$(cat /run/secrets/db_root_password)';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$(cat /run/secrets/db_root_password)' WITH GRANT OPTION;
DELETE FROM mysql.user WHERE User='';
DELETE FROM mysql.user WHERE User='mysql';
DELETE FROM mysql.db WHERE User='';
FLUSH PRIVILEGES;
EOF

    exec mariadbd --user=mysql --init-file=/tmp/init.sql
fi

exec mariadbd --user=mysql

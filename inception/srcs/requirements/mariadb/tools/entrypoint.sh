#!/bin/bash
set -e

service mariadb start

until mysqladmin ping --silent; do
    sleep 1
    echo "Waiting for MariaDB to start..."
done

cat <<EOF > /var/www/initial.sql
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF

mysql < /var/www/initial.sql

sleep 5
service mariadb stop

exec "$@"
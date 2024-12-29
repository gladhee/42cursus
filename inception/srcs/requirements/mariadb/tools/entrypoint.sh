#!/bin/sh

# Start MariaDB for initialization
echo "[INFO] Starting MariaDB..."
mysqld --user=mysql --skip-networking &
pid=$!


echo "[INFO] Waiting for MariaDB to start..."
while ! mysqladmin ping --silent; do
    sleep 1
done

# init database
echo "[INFO] Setting up the database..."
mysql -u root -p"$MYSQL_ROOT_PASSWORD" <<-EOSQL
    ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
    CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
    CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
    CREATE USER IF NOT EXISTS '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_PASSWORD';
    GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
    GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'localhost';
    FLUSH PRIVILEGES;
EOSQL

# Stop MariaDB and wait for it to exit
echo "[INFO] Stopping MariaDB..."
if ! kill -s TERM "$pid" || ! wait "$pid"; then
    echo >&2 '[ERROR] MariaDB initialization process failed.'
    exit 1
fi

# Start MariaDB
exec "$@"
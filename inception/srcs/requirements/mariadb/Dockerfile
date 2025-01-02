FROM alpine:3.20
LABEL authors="heesungchoi"

# Install mariadb
# The mariadb for alpine is equivalent to mysql
# @see https://wiki.alpinelinux.org/wiki/MariaDB
# @see https://pkgs.alpinelinux.org/package/v3.20/main/x86_64/mariadb
# @see https://pkgs.alpinelinux.org/package/v3.20/main/x86_64/mysql
RUN apk update && apk add --no-cache \
    mariadb \
    mariadb-client

# Create necessary directories and set permissions
RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld

# Initialize the database
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Expose the port
EXPOSE 3306

COPY conf/mariadb-server.cnf /etc/my.cnf.d/

COPY tools/entrypoint.sh /entrypoint-initdb.d/
RUN chmod +x /entrypoint-initdb.d/entrypoint.sh

ENTRYPOINT ["/entrypoint-initdb.d/entrypoint.sh"]

CMD ["mysqld", "--user=mysql"]
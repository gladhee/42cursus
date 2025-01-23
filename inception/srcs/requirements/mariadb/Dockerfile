FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y\ 
&& apt-get install -y mariadb-server tini net-tools

EXPOSE 3306
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/entrypoint.sh /var/www/entrypoint.sh

RUN chmod +x /var/www/entrypoint.sh

RUN mkdir -p /var/run/mysqld
RUN chown -R mysql:mysql /var/run/mysqld
ENTRYPOINT [ "/usr/bin/tini", "--", "/var/www/entrypoint.sh" ]

CMD ["mysqld"]

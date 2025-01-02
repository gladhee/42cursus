FROM alpine:3.20
LABEL authors="heesungchoi"

# Install wordpress
# @see https://wiki.alpinelinux.org/wiki/WordPress
RUN apk update && apk add --no-cache \
    curl php82 php82-phar php82-mbstring php82-iconv php82-tokenizer \
    php82-fpm php82-mysqli \
    php82-ctype \
    php82-cli mariadb-client

COPY conf/www.conf /etc/php82/php-fpm.d/www.conf


COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000
EXPOSE 6379

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

WORKDIR /var/www/html

CMD ["php-fpm82", "-F"]
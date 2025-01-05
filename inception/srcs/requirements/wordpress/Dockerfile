FROM alpine:3.20

# Install WordPress dependencies
RUN apk update && apk add --no-cache \
    curl php82 php82-phar php82-mbstring php82-iconv php82-tokenizer \
    php82-fpm php82-mysqli \
    php82-ctype php82-ftp

COPY conf/www.conf /etc/php82/php-fpm.d/www.conf

# Install wp-cli
WORKDIR /usr/local/bin
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN ln -s wp-cli.phar /usr/local/bin/wp
RUN ln -s /usr/bin/php82 /usr/bin/php

COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

WORKDIR /var/www/html

CMD ["php-fpm82", "-F"]
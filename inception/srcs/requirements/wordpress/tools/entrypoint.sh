#!/bin/sh
set -e

if [ -f "/var/www/html/wp-config.php" ]
then
    echo "WordPress already configured."
else
    wget https://github.com/wp-cli/wp-cli/releases/download/v2.5.0/wp-cli-2.5.0.phar
    chmod +x wp-cli-2.5.0.phar
    mv wp-cli-2.5.0.phar /usr/local/bin/wp
    chmod +x /usr/local/bin/wp
    chown -R www-data:www-data /var/www/html
    wp core download --path=$WORDPRESS_PATH --allow-root
    wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --path=$WORDPRESS_PATH --allow-root --skip-check
    wp core install --path=$WORDPRESS_PATH --url=$DOMAIN_NAME --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
    wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=author --path=$WORDPRESS_PATH --user_pass=$WORDPRESS_USER_PASSWORD --allow-root
fi

/usr/sbin/php-fpm82 -F
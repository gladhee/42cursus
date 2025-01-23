#!/bin/sh

    wget https://github.com/wp-cli/wp-cli/releases/download/v2.5.0/wp-cli-2.5.0.phar
    chmod +x wp-cli-2.5.0.phar
    mv wp-cli-2.5.0.phar /usr/local/bin/wp
    chmod +x /usr/local/bin/wp
    chown -R www-data:www-data /var/www/html

    # Download WordPress
    echo "[INFO] Downloading WordPress..."
    wp core download \
        --path=$WP_PATH \
        --allow-root
    # Create wp-config.php
    echo "[INFO] Creating wp-config.php..."
    wp config create \
        --dbname=$MYSQL_DATABASE \
        --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_PASSWORD \
        --dbhost=mariadb \
        --path=$WP_PATH \
        --allow-root \
        --skip-check
    # Install WordPress
    echo "[INFO] Installing WordPress..."
    wp core install \
        --path=$WP_PATH \
        --url=$DOMAIN_NAME \
        --title=$WP_TITLE \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
        --skip-email \
        --allow-root
    wp user create \
        $WP_USER $WP_USER_EMAIL \
        --role=author \
        --path=$WP_PATH \
        --user_pass=$WP_USER_PASSWORD \
        --allow-root

    # Set permissions
    echo "[INFO] Setting permissions..."
    adduser -D www-data -G www-data
    chown -R www-data:www-data /var/www/html
    
    chmod -R 755 /var/www/html

    # Start php-fpm
    echo "[INFO] Starting php-fpm..."
    exec "$@"

#!/bin/sh

# Download WordPress
echo "[INFO] Downloading WordPress..."
wp core download --path=$WORDPRESS_PATH --allow-root

# Create wp-config.php
echo "[INFO] Creating wp-config.php..."
wp config create \
    --path=$WORDPRESS_PATH \
    --dbname=$WORDPRESS_DB_NAME \
    --dbuser=$WORDPRESS_DB_USER \
    --dbpass=$WORDPRESS_DB_PASSWORD \
    --dbhost=$WORDPRESS_DB_HOST \
    --dbprefix=$WORDPRESS_DB_TABLE_PREFIX \
    --allow-root

# Install WordPress
echo "[INFO] Installing WordPress..."
wp core install \
    --path=$WORDPRESS_PATH \
    --url=$WORDPRESS_URL \
    --title=$WORDPRESS_TITLE \
    --admin_user=$WORDPRESS_ADMIN_USER \
    --admin_password=$WORDPRESS_ADMIN_PASSWORD \
    --admin_email=$WORDPRESS_ADMIN_EMAIL \
    --allow-root

# Create a new WordPress user without admin privileges
echo "[INFO] Creating a new WordPress user..."
wp user create $WORDPRESS_WP_USER $WORDPRESS_WP_EMAIL \
    --role=subscriber \
    --user_pass=$WORDPRESS_WP_PASSWORD \
    --path=$WORDPRESS_PATH \
    --allow-root

# Set permissions
echo "[INFO] Setting permissions..."
adduser -D www-data -G www-data
chown -R www-data:www-data $WORDPRESS_PATH
chmod -R 755 $WORDPRESS_PATH

# Start php-fpm
echo "[INFO] Starting php-fpm..."
exec "$@"
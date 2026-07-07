#!/bin/sh

until mariadb -h "${MYSQL_HOST}" -u"${MYSQL_USER}" -p"$(cat /run/secrets/db_password)" -e "SELECT 1" >/dev/null 2>&1; do
    sleep 1
done

if [ ! -f /var/www/html/wp-config.php ]; then
        cp -r /tmp/wordpress/* /var/www/html/
        wp config create \
        --dbname="${MYSQL_NAME}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="$(cat /run/secrets/db_password)" \
        --dbhost="${MYSQL_HOST}" \
        --path=/var/www/html \
        --allow-root
    chown -R nobody:nobody /var/www/html
fi

if ! wp core is-installed --path=/var/www/html --allow-root >/dev/null 2>&1; then
    wp core install \
        --url="${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="$(cat /run/secrets/wp_admin_password)" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --path=/var/www/html \
        --allow-root
fi

if ! wp user get "${WP_USER}" --field=ID --path=/var/www/html --allow-root >/dev/null 2>&1; then
    wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
        --user_pass="$(cat /run/secrets/wp_user_password)" \
        --role="${WP_USER_ROLE}" \
        --path=/var/www/html \
        --allow-root
fi

exec php-fpm82 -F

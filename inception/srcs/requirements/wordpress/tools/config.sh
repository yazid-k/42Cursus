#!/bin//bash

cd /var/www/wordpress
FILE=wp-config.php
if [ ! -f "$FILE" ]; then
	echo in
	wp config create	--allow-root \
				--dbname=$SQL_DATABASE \
				--dbuser=$SQL_USER \
				--dbpass=$SQL_PASSWORD \
				--dbhost=mariadb:3306 \
				--path='/var/www/wordpress'
	echo test
	wp core install	--allow-root \
			--url=https://${DOMAIN_NAME} \
			--title=${SITE_TITLE} \
			--admin_user=${ADMIN_USER} \
			--admin_password=${ADMIN_PASSWORD} \
			--admin_email=${ADMIN_EMAIL};
	echo teeest
	wp user create	--allow-root ${USER1_LOGIN} ${USER1_MAIL}\
	       	--role=author \
	       	--user_pass=${USER1_PASS};

wp cache flush --allow-root
wp plugin install contact-form-7 --activate --allow-root
wp language core install en_US --activate --allow-root
wp theme delete twentynineteen twentytwenty --allow-root
wp plugin delete hello --allow-root
wp rewrite structure '/%postname%/' --allow-root


fi

mkdir -p /run/php

php-fpm7.4 --nodaemonize --fpm-config /etc/php.7.3/fpm/pool.d/www.conf

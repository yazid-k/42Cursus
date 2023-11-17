FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install wget -y
RUN apt-get install mariadb-client -y
RUN apt-get install php-fpm php-mysqli -y
RUN wget https://fr.wordpress.org/wordpress-6.4.1-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.4.1-fr_FR.tar.gz && rm wordpress-6.4.1-fr_FR.tar.gz
RUN chown -R root:root /var/www/wordpress
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
COPY tools/config.sh ./
COPY conf/www.conf /etc/php.7.3/fpm/pool.d/www.conf
RUN chmod +x config.sh
EXPOSE 9000
ENTRYPOINT ["bash", "config.sh"]

FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install wordpress -y
RUN apt-get install php-fpm -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"



FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt install nginx -y
RUN mkdir -p /etc/nginx/ssl
RUN apt install openssl -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=yazid/UID=ekadiri@student.42.fr"
RUN mkdir -p /var/run/nginx
EXPOSE 443
COPY conf/nginx.conf /etc/nginx/nginx.conf
RUN chmod 755 /var/www
RUN chown -R www-data:www-data /var/www
CMD ["nginx", "-g", "daemon off;"]

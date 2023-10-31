FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y
RUN mkdir -p /var/run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
RUN chmod 777 /var/run/mysqld
CMD ["service", "mariadb", "start"]
RUN mysql -u root -e "CREATE DATABASE wordpress;"

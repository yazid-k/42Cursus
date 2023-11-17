FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y mariadb-server mariadb-client
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mkdir -p /var/run/mysqld
RUN mkdir -p /var/lib/mysql
RUN chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
RUN chmod -R 755 /var/lib/mysql /var/run/mysqld

EXPOSE 3306

COPY ./tools/dbscript.sh ./
RUN chmod +x ./dbscript.sh
ENTRYPOINT ["./dbscript.sh"]
CMD ["mysqld_safe"]

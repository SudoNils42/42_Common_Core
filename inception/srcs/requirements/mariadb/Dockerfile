FROM alpine:3.22

RUN apk add --no-cache mariadb mariadb-client

COPY conf/my.cnf /etc/my.cnf.d/z-inception.cnf

COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

CMD ["/setup.sh"]

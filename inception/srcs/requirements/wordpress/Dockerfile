FROM alpine:3.22

RUN apk add --no-cache php82 php82-fpm php82-mysqli php82-phar php82-mbstring curl unzip mariadb-client
RUN ln -s /usr/bin/php82 /usr/bin/php

COPY conf/www.conf /etc/php82/php-fpm.d/www.conf

RUN curl -fsSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp
RUN chmod +x /usr/local/bin/wp

RUN mkdir -p /var/www/html /tmp/wordpress
RUN curl -o /tmp/wordpress.zip https://wordpress.org/latest.zip
RUN unzip -q /tmp/wordpress.zip -d /tmp/

COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

CMD ["/setup.sh"]

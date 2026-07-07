FROM alpine:3.22

RUN apk add --no-cache nginx openssl

RUN openssl req -x509 -nodes -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -subj "/C=CH/ST=VD/L=Lausanne/O=42/OU=Student/CN=nbonnet.42.fr"

COPY conf/nginx.conf /etc/nginx/http.d/default.conf
COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

CMD ["/setup.sh"]

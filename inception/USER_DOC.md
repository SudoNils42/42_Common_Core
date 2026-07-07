# User Documentation

## Services

This stack provides a WordPress website accessible via HTTPS:

- **nginx** — serves the site on port 443 with TLS encryption
- **wordpress** — runs the WordPress application
- **mariadb** — stores the website data

## Start and Stop

Start:
```bash
make
```

Stop:
```bash
make down
```

Full reset:
```bash
make re
```

Check status:
```bash
make ps
```

## Access

Website: `https://nbonnet.42.fr`

Admin panel: `https://nbonnet.42.fr/wp-admin`

If the domain does not resolve, add to `/etc/hosts`:
```
127.0.0.1 nbonnet.42.fr
```

## Credentials

Passwords are stored in `secrets/`:
- `db_password.txt` — database user password
- `db_root_password.txt` — database root password
- `wp_admin_password.txt` — WordPress admin password
- `wp_user_password.txt` — WordPress user password

Non-sensitive settings are in `srcs/.env`.

To change a password, edit the corresponding file in `secrets/` and run `make re`.

## Check Services

```bash
make ps
```


View logs:
```bash
docker compose -f srcs/docker-compose.yml logs nginx
docker compose -f srcs/docker-compose.yml logs wordpress
docker compose -f srcs/docker-compose.yml logs mariadb
```

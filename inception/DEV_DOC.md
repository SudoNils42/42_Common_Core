# Developer Documentation

## VM Setup (Debian)

```bash
sudo apt update
sudo apt install docker.io docker-compose make
sudo systemctl enable docker
sudo systemctl start docker
sudo usermod -aG docker $USER
newgrp docker
```


## Setup From Scratch

Clone and enter:
```bash
git clone <repo_url> inception
cd inception
```

Create secret files in `secrets/` with one password per file:
- `db_password.txt`
- `db_root_password.txt`
- `wp_admin_password.txt`
- `wp_user_password.txt`

Configure `srcs/.env` with your values (domain, usernames, emails).

Add domain resolution:
```
echo "127.0.0.1 nbonnet.42.fr" >> /etc/hosts
```

## Build and Launch

```bash
make
```

## Commands

| Command | Description |
|---|---|
| `make` | setup + build + start |
| `make ps` | show running containers |
| `make down` | stop containers |
| `make clean` | stop + remove volumes |
| `make fclean` | stop + remove volumes + images + host data |
| `make re` | fclean + rebuild + start |

## Data Persistence

Two named volumes defined in `docker-compose.yml`:

| Volume | Container path | Host path |
|---|---|---|
| `db_data` | `/var/lib/mysql` | `/home/nbonnet/data/db` |
| `www_data` | `/var/www/html` | `/home/nbonnet/data/www` |

- Recreating containers keeps data (volumes persist).
- `make clean` removes volumes (data lost).
- `make fclean` also deletes host data directory.

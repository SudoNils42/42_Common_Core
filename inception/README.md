*This project has been created as part of the 42 curriculum by nbonnet.*

# Inception

## Description

Inception is a system administration project using Docker. The goal is to set up a small
infrastructure composed of three services running in separate containers:

- **nginx** — web server
- **wordpress** — website application
- **mariadb** — database

All images are built from Alpine. No pre-made images are pulled.
All of these run together using Docker Compose.
## Instructions

Prerequisites: Debian VM with Docker, Docker Compose and Make installed.

```bash
git clone <repo_url> inception
cd inception
```

Create secret files in `secrets/` (one password per file):
- `db_password.txt`
- `db_root_password.txt`
- `wp_admin_password.txt`
- `wp_user_password.txt`

Add domain resolution:
```
echo "127.0.0.1 nbonnet.42.fr" >> /etc/hosts
```

Build and run:
```bash
make
```

Access the site at `https://nbonnet.42.fr`.

## Project Description

### Virtual Machines vs Docker

A VM emulates a full operating system with its own kernel. Docker containers share the
host kernel and only isolate processes and filesystem. Containers are lighter, start faster,
and use fewer resources. VMs provide stronger isolation.

### Secrets vs Environment Variables

Environment variables are visible in process listings and logs. Docker secrets are inside the container, readable only by the process. Secrets are
used for passwords, environment variables for non-sensitive configuration.

### Docker Network vs Host Network

Host network shares the host's network stack directly. Docker bridge network creates an
isolated virtual network where containers communicate by service name. Bridge is more
secure and avoids port conflicts.

### Docker Volumes vs Bind Mounts

Bind Mounts:
They directly connect a folder from the host into the container.
Very simple, but less flexible.

Docker Named Volumes:
These are folders managed by Docker.
They are easier to move, backup, and manage. They offer better portability and control.

In this Inception project, we use Docker Named Volumes (with the local driver).
They store the data in this folder on the host:
`/home/nbonnet/data/`

## Resources

- [Docker documentation](https://docs.docker.com/)
- [Docker Compose documentation](https://docs.docker.com/compose/)
- [Nginx documentation](https://nginx.org/en/docs/)
- [WordPress CLI documentation](https://developer.wordpress.org/cli/commands/)
- [MariaDB documentation](https://mariadb.com/kb/en/documentation/)
- [Medium article 1](https://medium.com/@ssterdev/inception-guide-42-project-part-i-7e3af15eb671)
- [Medium article 2](https://medium.com/@imyzf/inception-3979046d90a0)

AI was used to understand key concepts and theory, and to help with syntax and small debugging tasks. All generated suggestions were carefully reviewed, tested, and validated manually.
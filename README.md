# 42 Common Core — 42 Lausanne

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-004482?style=flat&logo=cplusplus&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=flat&logo=docker&logoColor=white)
![Shell](https://img.shields.io/badge/Shell-121011?style=flat&logo=gnubash&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![Nginx](https://img.shields.io/badge/Nginx-009639?style=flat&logo=nginx&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white)

This repository contains the projects I validated during my Common Core at 42 Lausanne, starting October 2024.

Each project focuses on a specific area of software development, from low-level C/C++98 programming to system administration, networking, graphics, and full-stack web development.

---

## Overview of the projects

The Common Core follows a milestone-based progression. Projects unlock as you validate the previous ones.

| Project | Language | Description | Main topics covered |
|---|---|---|---|
| **libft** | C | A personal C library built from scratch, reimplementing ~50 standard functions (`string.h`, `stdlib.h`, etc.) plus a set of bonus linked-list utilities. Used as a dependency in all subsequent projects. | Standard library reimplementation, linked lists, header files |
| **ft_printf** | C | A partial reimplementation of `printf`, supporting the main format specifiers (`%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`). Explores how variadic functions work under the hood. | Variadic functions (`va_list`), format string parsing, output formatting |
| **get_next_line** | C | A function that reads a file descriptor line by line across multiple calls, regardless of the buffer size. Works simultaneously on multiple file descriptors. | File descriptors, static variables, heap memory management, buffered I/O |
| **born2beroot** | Shell / VM | Set up and configure a Debian virtual machine from scratch following strict system administration rules: encrypted partitions (LVM), hardened SSH, firewall (UFW), password policy, and a monitoring script. | Virtualization, Debian/Linux, LVM, SSH, UFW, cron, sudo configuration |
| **push_swap** | C | Sort a stack of integers using two stacks and a limited set of operations, with the fewest moves possible. Requires designing and implementing an efficient sorting algorithm. | Stack data structures, sorting algorithms, algorithm complexity, optimization |
| **so_long** | C | A small 2D top-down game rendered with the MiniLibX graphical library. The player must collect all items and reach the exit while the game tracks movement count. | MiniLibX, 2D rendering, map parsing (.ber files), event-driven programming |
| **minitalk** | C | A client/server communication program where the client sends a string to the server bit by bit using only UNIX signals. The server reconstructs and prints the message in real time. | UNIX signals (`SIGUSR1`/`SIGUSR2`), bitwise operations, inter-process communication |
| **philosophers** | C | Simulation of the classic Dining Philosophers problem. Each philosopher is a thread; forks are mutexes. The program must prevent deadlocks and starvation while managing precise timing. | Multithreading (`pthread`), mutexes, race conditions, deadlock prevention |
| **net_practice** | — | A series of network configuration exercises completed through a web interface. Covers IP addressing, subnet masks, routing tables, and diagnosing broken network topologies. | IP addressing, subnetting (CIDR), routing, TCP/IP model |
| **minishell** | C | *(Team project)* A functional Unix shell supporting command execution, environment variables, pipes, redirections (`<`, `>`, `<<`, `>>`), and all mandatory builtins (`cd`, `echo`, `export`, `unset`, `env`, `exit`). | Process management (`fork`/`exec`/`wait`), pipes, file descriptor redirection, signal handling, lexing & parsing |
| **cub3D** | C | *(Team project)* A 3D maze renderer using the raycasting technique, inspired by Wolfenstein 3D. Renders textured walls in real time based on a map file, with smooth player movement and collision detection. | Raycasting, DDA algorithm, MiniLibX, texture mapping, trigonometry |
| **CPP Modules** | C++ | A series of 10 modules introducing C++ and object-oriented programming, progressively covering the core language features absent from C. | Classes, encapsulation, inheritance, polymorphism, operator overloading, templates, STL, exceptions, RAII |
| **webserv** | C++ | *(Team project)* An HTTP/1.1 compliant web server built from scratch, supporting multiple virtual hosts, GET/POST/DELETE methods, file uploads, CGI execution, and a custom configuration file format inspired by NGINX. | HTTP/1.1 protocol, non-blocking I/O (`poll`), TCP sockets, CGI, config parsing |
| **inception** *(in progress)* | Docker / Shell | Set up a multi-service infrastructure inside a virtual machine using Docker Compose. Each service (NGINX, WordPress, MariaDB) runs in its own container, connected through a custom Docker network with persistent volumes. | Docker, Docker Compose, NGINX (TLS), WordPress, MariaDB, container networking, volumes |
| **ft_transcendence** *(in progress)* | TypeScript / Web | *(Team project)* A full-stack single-page web application featuring a real-time multiplayer Pong game, user authentication with 2FA (TOTP), OAuth (42 API), a chat system, and a social system (friends, blocks, match history). | WebSockets, REST API, OAuth 2.0, 2FA, SPA architecture, real-time game logic |

> Note: projects are stored in individual folders.

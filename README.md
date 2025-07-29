# DotBaseShell & DotBaseServer (Beta)

---

## English (US)

### Overview

This repository contains two components in **beta** stage:

- **DotBaseServer**: The backend server you need to run first.  
- **DotBaseShell**: The interactive shell client to send commands to the server.

### Usage

1. **Start the DotBaseServer** before running any commands. The server listens for incoming connections and processes requests.  
2. After the server is running, use **DotBaseShell** to connect and execute commands.

### Supported Commands

Currently, the only supported command is:

```sql
TABLE_CREATE name;

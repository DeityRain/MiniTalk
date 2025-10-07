# 🛰️ Minitalk

**Minitalk** is a small data exchange program written in **C** for **42 School**.  
It allows a **client** to communicate a string message to a **server** process using **UNIX signals** (`SIGUSR1` and `SIGUSR2`).

---

## 🧠 Project Overview

The goal of **Minitalk** is to implement a simple communication protocol between two processes — the **server** and the **client** — using only UNIX signals as a transport mechanism.

- The **server** waits for signals from the client.
- The **client** encodes each character of the message into bits and sends them via signals.
- The **server** reconstructs the original message bit by bit and prints it.

This project is a great introduction to **process management**, **bitwise operations**, and **signal handling** in C.

---

## ⚙️ Features

✅ Communication using only `SIGUSR1` and `SIGUSR2`  
✅ Asynchronous, signal-based message handling  
✅ Handles multiple messages in sequence  
✅ Includes a simple and clean `Makefile` for compilation  
✅ Follows the **42 Norm** and C standards

---

## 🧩 Compilation

To compile the project, simply run:

```bash
make
```

This will create two executables:
- `server`
- `client`

Other available Makefile commands:

```bash
make clean     # Removes object files
make fclean    # Removes object files and executables
make re        # Rebuilds everything
```

---

## 🚀 Usage

1. **Start the server** in one terminal:
   ```bash
   ./server
   ```
   The server will display its **PID** (process ID).

2. **Run the client** in another terminal with the server PID and your message:
   ```bash
   ./client <server_pid> "Your message here"
   ```

3. The server will receive, decode, and print the message.

---

### 💬 Example

```bash
$ ./server
Server PID: 4242
Waiting for message...

$ ./client 4242 "Hello, 42!"
Received message: Hello, 42!
```

---

## 🧵 Bonus (if implemented)

If you have completed the bonus part of the project, it may include:

- Server acknowledgment signal to client after message received
- Unicode or extended character support
- Signal timing and stability improvements
- Robust handling for simultaneous messages

---

## 🛠️ Requirements

- **Language:** C  
- **Compiler:** `gcc`  
- **Flags:** `-Wall -Wextra -Werror`  
- **System:** Linux or macOS (UNIX-compatible environment)

---

## 📁 Project Structure

```
.
├── Makefile
├── client.c
└── server.c
```

---

## 💡 Learning Outcomes

By completing this project, you’ll gain hands-on experience with:

- UNIX **signals** and process communication  
- **Bitwise operations** for data encoding  
- **Asynchronous programming** concepts  
- Clean and modular **C code organization**

---

## 👨‍💻 Author

**DeityRain**    
🧭 [github.com/DeityRain](https://github.com/DeityRain)

---


# libcurl_patched

## Installation

### Linux

#### Using clang
```bash
sudo apt install clang libssl-dev -y
clang -shared -fPIC -o ssl_wrapper.so ssl_wrapper.c -ldl
````

#### Using gcc

```bash
sudo apt install gcc libssl-dev -y
gcc -shared -fPIC -o ssl_wrapper.so ssl_wrapper.c -ldl
```

### Termux

#### Using clang

```bash
pkg install clang openssl -y
clang -shared -fPIC -o ssl_wrapper.so ssl_wrapper.c -ldl
```

#### Using gcc

```bash
pkg install gcc openssl -y
gcc -shared -fPIC -o ssl_wrapper.so ssl_wrapper.c -ldl
```

## Usage

```bash
LD_PRELOAD=$PWD/ssl_wrapper.so curl https://self-signed.badssl.com
```


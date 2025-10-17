savedcmd_/home/matteo/driver/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/matteo/driver/"$$0) }' > /home/matteo/driver/hello.mod

savedcmd_/home/matteo/driver/test_cdev/test_cdev.mod := printf '%s\n'   test_cdev.o | awk '!x[$$0]++ { print("/home/matteo/driver/test_cdev/"$$0) }' > /home/matteo/driver/test_cdev/test_cdev.mod

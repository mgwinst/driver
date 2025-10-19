savedcmd_/home/matteo/driver/dma/test_dma.mod := printf '%s\n'   test_dma.o | awk '!x[$$0]++ { print("/home/matteo/driver/dma/"$$0) }' > /home/matteo/driver/dma/test_dma.mod

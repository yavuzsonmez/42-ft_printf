# This requires zip (unzip), valgrind, make and gcc to be installed on your remote server
# Also, it is required to authenticate with your server via ssh key auth.

# Please fill out the variables with your values.
# Also, this script relies on you having a makefile.

IPADDR=127.0.0.1 # Server address here
USER=tester # Server user here
TOTEST_FOLDER=./42project # project folder
BUILD="gcc -o executable -std=c11 -ggdb3 main.c libftprintf.a" #this command should build the program we want to test. if makes already does that, change this to an non affecting command like echo 42rocks
VGC="valgrind --leak-check=full          --show-leak-kinds=all          --track-origins=yes          --verbose          --log-file=valgrind-out.txt          ./executable"

zip -r test.zip $TOTEST_FOLDER
rsync -avHe --mkpath ./test.zip -e ssh $USER@$IPADDR:/home/$USER/test.zip
ssh $USER@$IPADDR "unzip test.zip -d project/ && cd project && cd $TOTEST_FOLDER && make fclean && make && $BUILD && $VGC && cat valgrind-out.txt"


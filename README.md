# sqlite3
support sqlite3 encrypt data
base sqlite3 source: sqlite-autoconf-3071000.tar.gz

use command next command to compile the sqlite3:
./configure && make &&  make install 

and compile test use next command:
g++ -o test test.c sqlite3.h -L./ -lsqlite3 -DSQLITE_HAS_CODEC

and run ./test will generate encrypt.db

use vim open the encrypt.db will see encrypt data. 
and use sqlite3 command to operation the db, will get "Error: unsupported file format" error.


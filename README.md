# sqlite3
support sqlite3 encrypt data
base sqlite3 source: sqlite-autoconf-3071000.tar.gz

use command:
./configure && make &&  make install to compile the sqlite3
and use command:
g++ -o test test.c sqlite3.h -L./ -lsqlite3 -DSQLITE_HAS_CODEC
to compile the test program. 

use vim open then sqlite db, will see encrypt data. 
and use sqlite3 command to operation the db, will get "Error: unsupported file format" error.


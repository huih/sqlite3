#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

static int _callback_exec(void * notused,int argc, char ** argv, char ** aszColName)
{

    int i;
    for ( i=0; i<argc; i++ )
    {
        printf( "%s = %s\r\n", aszColName[i], argv[i] == 0 ? "NUL" : argv[i] );
    }
    return 0;
}

int main(int argc, char * argv[])
{
    const char * sSQL;
    char * pErrMsg = 0;
    int ret = 0;
    sqlite3 * db = 0;
    //创建数据库
    ret = sqlite3_open("encrypt.db", &db);
    
    //添加密码
    ret = sqlite3_key( db, "dcg", 3 );

    //在内存数据库中创建表
    sSQL = "create table class(name varchar(20), student);";
    sqlite3_exec( db, sSQL, _callback_exec, 0, &pErrMsg );

    //插入数据
    sSQL = "insert into class values('mem_52911', 'zhaoyun');";
    sqlite3_exec( db, sSQL, _callback_exec, 0, &pErrMsg );

    //取得数据并显示
    sSQL = "select * from class;";
    sqlite3_exec( db, sSQL, _callback_exec, 0, &pErrMsg );

    //关闭数据库
    sqlite3_close(db);
    db = 0;
    return 0;
}

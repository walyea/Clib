#include <stdio.h>
#include <stdlib.h>
#define bool  _Bool
#define false 0
#define true  1
#define unwrap(x) !x.null ? x.data : NULL
#define try(x) x.isError ? return x.ErrorUnion.error : e.ErrorUnion.data
#define orelse(x,value) x.null ? value : x.data
#define catch(x, value) x.isError ? value : x.ErrorUnion.data
typedef char String[];
typedef struct{
    void* data;
    bool null;
}Optional;
typedef void* error;
typedef union{
    error Error;
    void* data;
}ErrorUnion;
typedef struct{
    ErrorUnion errorUnion;
    bool  isError;
}returnError;
returnError new(error e, void* data){
    returnError ret;
    if(e == NULL){
        ret.errorUnion.data = data;
        ret.isError = false;
    }
    else{
        ret.errorUnion.Error = e;
        ret.isError = true;
    }
    return ret;
}

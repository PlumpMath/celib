#ifndef _CE_STRING_H_
#define _CE_STRING_H_

typedef unsigned char uchar;
typedef struct CeString_Class_get CeString_Class_get;

typedef struct CeString {
        uchar *data;
        int len;               /**< string length excluding trailing '\0' */
        CeString_Class_get *get;
} CeString;

struct CeString_Class_get {
        uchar *(*data) (CeString *self);
};


CeString *ce_string_new(void);
void ce_string_delete(CeString *str);




#endif  /* _CE_STRING_H_ */

int fibo (int ,int *);
int concat(int *, int, int *, int, int *);
int filter(int *, int, int, int **);
int reverse(int *, int);
int reverseReturnNewArray(int *, int, int *);
int slice(int *,int,int, int, int **);
int prime(int, int, int **);
int strCmp(char *,char *);
int forEachInt(int *, int, void (*)(int,int,int *));
int forEachChar(char *, int, void (*)(char,int,char *));
int forEachFloat(float *, int, void (*)(float,int,float *));
int forEachString(char **, int, void (*)(char *,int,char **));
int intArrayFilter(int *, int, int **, int (*)(int));
int floatArrayFilter(float *, int, float **, int (*)(float));
int charArrayFilter(char *, int, char **, int (*)(char));
int stringArrayFilter(char **, int, char ***, int (*)(char*));
int * mapInt(int *, int, int (*)(int,int,int *));
float * mapFloat(float *, int, float (*)(float,int,float *));
char * mapChar(char *, int, char (*)(char,int,char *));
char ** mapString(char **, int, char *(*)(char *,int, char **));
int reduceInt (int *, int, int (*)(int,int,int,int *), int);
float reduceFloat (float *, int, float (*)(float,float,int, float *), float);
char reduceChar (char *, int, char (*)(char,char,int, char *), float);
int indexOf(char *, char *);
struct no{
  int info;
  struct no * proximo;
};

typedef struct no NO;

NO* aloca_no(int);

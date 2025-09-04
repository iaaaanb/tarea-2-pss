// test-comprimir.c: Programa de prueba para la tarea 2 de PSS
// Puede modificar este archivo para fines de debugging, pero una vez
// que su tarea funcione, restaure el archivo original porque se tarea
// sera verificada con este archivo sin cambios

// includes tipicos para programas en Linux
#include <stdio.h>   // Para las funciones printf, fread, etc.
#include <stdlib.h>  // Funciones estandares de C como malloc, exit
#include <stdint.h>  // Con los tipos enteros de tamanno conocido como int32_t
#include <string.h>  // Funciones para strings como strcpy, strcmp

#include "test-util.h"
#include "comprimir.h"

#define SIZE (500000000)

void test_unitario_comprimir(void) {
  {
    char str[] = "CCGGAAATCAAAA";
    char *res = "2C2G3ATC4A";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
  {
    char str[] = "ABCD";
    char *res = "ABCD";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
  {
    char str[] = "AAaaaCCgtD";
    char *res = "2A3a2CgtD";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
  {
    char str[] = "";
    char *res = "";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
  {
    char str[] = "AAAAAAAAA";
    char *res = "9A";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
  {
    char str[] = "abbbbbbaabbbbbbbbbaaab";
    char *res = "a6b2a9b3ab";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
  {
    char str[] = "abfffffffff";
    char *res = "ab9f";
    printf("Verificando con s = \"%s\"\n", str);
    comprimir(str);
    if (strcmp(str, res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", res, str);
      exit(1);
    }
  }
}

void test_unitario_comprimido(void) {
  {
    char *str = "CCGGAAATCAAAA";
    char *expectedRes = "2C2G3ATC4A";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
  {
    char *str = "ABCD";
    char *expectedRes = "ABCD";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
  {
    char *str = "AAaaaCCgtD";
    char *expectedRes = "2A3a2CgtD";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
  {
    char *str = "";
    char *expectedRes = "";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
  {
    char *str = "AAAAAAAAA";
    char *expectedRes = "9A";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
  {
    char *str = "abbbbbbaabbbbbbbbbaaab";
    char *expectedRes = "a6b2a9b3ab";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
  {
    char *str = "abfffffffff";
    char *expectedRes = "ab9f";
    printf("Verificando con s = \"%s\"\n", str);
    char *res = comprimido(str);
    if (strcmp(res, expectedRes) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", expectedRes, res);
      exit(1);
    }
    free(res);
  }
}

void test_unitario(void) {
  printf("----- Verificando funcion comprimir ------\n");
  test_unitario_comprimir();
  printf("----- Verificando funcion comprimido ------\n");
  test_unitario_comprimido();
}

typedef struct {
  char **res;
} Param;

char *strings[] = {"", "a", "aA", "aaa", "ab", "abB", "abbbBBa", "ZZzzXXxxWWww", "CCCTTGAAATAAGCCCTC", "cccbbbCCAAAaaaccBBCCC", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "aaaaaaaaabbbbbbbbbccccccccc"};
char *results[] = {"", "a", "aA", "3a", "ab", "abB", "a3b2Ba", "2Z2z2X2x2W2w", "3C2TG3AT2AG3CTC", "3c3b2C3A3a2c2B3C", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "9a9b9c"};

char *enorme(int len, char **pref) {
  char *res = malloc(len + 1);
  int refLen = 0;
  int lastChar = 0;
  {
    char *s = res;
    char *p = s, *top = p + len;
    *top = 0;
    for(;;) {
      for(int j=1; j<9; j++){
        for(char d='A'; d<='Z'; d++) {
          refLen += j == 1 ? 1 : 2;
          lastChar = 0;
          for(int i=0; i<j; i++){
            if(p >= top) {
              if(i == 0) {
                refLen -= j == 1 ? 1 : 2;
              }
              if (i == 1) {
                refLen -= j == 1 ? 0 : 1;
              }
              goto buildRef;
            }
            *p++=d;
            lastChar++;
          }
        }
      }
    }
  }

  buildRef:

  {
    char *s = malloc(refLen + 1);
    *pref = s;
    char *p = s, *top = p + refLen;
    *top-- = 0;
    for(;;) {
      for(int j=1; j<9; j++){
        for(char d='A'; d<='Z'; d++) {
          if(lastChar == 1 && p >= top) {
            *p = d;
            return res;
          }
          if(lastChar > 1 && p >= (top - 1)) {
            *p++= lastChar + '0';
            *p=d;
            return res;
          }
          if(lastChar == 0 && p > top) {
            return res;
          }
          if(j > 1) {
           *p++= j + '0';
          }
          *p++=d;
        }
      }
    }
  }
}

void verify_results(void *ptr) {
  Param *parm = ptr;
  for(int i = 0; i < 13; i++) {
    char *res = parm->res[i];
    char *correct_res = results[i];
    if(strcmp(res, correct_res) != 0) {
      fprintf(stderr, "El resultado debio ser \"%s\", no \"%s\"\n", correct_res, res);
      free(parm->res[i]);
      exit(1);
    }
    free(parm->res[i]);
  }
}

void bench_serie_comprimir(void *ptr) {
  char *str[13], *res[13];
  char **aux = str;
  for(int i = 0; i < 13; i++) {
    *aux = malloc(strlen(strings[i]) + 1);
    strcpy(*aux, strings[i]);
    aux++;
  }
  aux = res;
  for(int i = 0; i < 13; i++) {
    comprimir(str[i]);
    *aux = malloc(strlen(str[i]) + 1);
    strcpy(*aux, str[i]);
    free(str[i]);
    aux++;
  }
  Param parm = { res };
  printf("--------------------------------------------\n");
  printf("Verificando la correctitud de los resultados de comprimir\n");
  verify_results(&parm);
  printf("Ejecucion string enorme\n");
  char *ref;
  char *s= enorme(SIZE, &ref);
  comprimir(s);
  if(strcmp(s, ref) != 0) {
    fprintf(stderr, "Resultado incorrecto en comprimir, s=%s, ref=%s\n", s, ref);
    exit(1);
  }
  free(s);
  free(ref);
}

void bench_serie_comprimido(void *ptr) {
  char *str[13], *res[13];
  char **aux = str;
  for(int i = 0; i < 13; i++) {
    *aux = malloc(strlen(strings[i]) + 1);
    strcpy(*aux, strings[i]);
    aux++;
  }
  aux = res;
  for(int i = 0; i < 13; i++) {
    char *r = comprimido(str[i]);
    *aux = malloc(strlen(r) + 1);
    strcpy(*aux, r);
    free(str[i]);
    free(r);
    aux++;
  }
  Param parm = { res };
  printf("--------------------------------------------\n");
  printf("Verificando la correctitud de los resultados de comprimido\n");
  verify_results(&parm);
  printf("Ejecucion string enorme\n");
  char *ref;
  char *s = enorme(SIZE, &ref);
  char *r = comprimido(s);
  if(strcmp(r, ref) != 0) {
    fprintf(stderr, "Resultado incorrecto en comprimido\n");
    exit(1);
  }
  free(s);
  free(r);
  free(ref);
}



static void bench_comprimir(void *ptr) {
  bench_serie_comprimir(ptr);
}

static void bench_comprimido(void *ptr) {
  bench_serie_comprimido(ptr);
}


void benchmark(int refs[], int nrefs) {
  int trefComprimido = nrefs==0 ? 0 : refs[1];
  int trefComprimir = nrefs==0 ? 0 : refs[0];

  printf("------------------------------------------\n");
  printf("Benchmark de comprimir\n");
  char *resParmComprimir;
  Param ParmComprimir= { &resParmComprimir };
  run_bench(dummyFun, bench_comprimir, dummyFun, &ParmComprimir,
            trefComprimir, 80, 5);

  printf("------------------------------------------\n");
  printf("Benchmark de comprimidos\n");
  char *resParmComprimido;
  Param ParmComprimido= { &resParmComprimido };
  run_bench(dummyFun, bench_comprimido, dummyFun, &ParmComprimido,
            trefComprimido, 80, 5);
}

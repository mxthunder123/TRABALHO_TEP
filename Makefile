CC = gcc
CFLAGS = -lm  -Wall 
DEPS =  Racional.h complexo.h vetor.h vetor_complex.h Complexo_double.h Complexo_int.h   Racional_Complexo.h Conversoes.h vetor_double.h vetor_int.h  vetor_complex_double.h vetor_complex_int.h 
OBJ =   Racional.o complexo.o vetor.o vetor_complex.o Complexo_double.o Complexo_int.o   Racional_Complexo.o Conversoes.o vetor_double.o vetor_int.o  vetor_complex_double.o vetor_complex_int.o main.o 


NAME_PROGRAM = program.exe


%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) 

Projeto: $(OBJ)
	echo "Compilando programa"
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado"



run: vl
	@./${BIN}/${NAME_PROGRAM}
	@ echo "\n\n\n"
	@ cowsay "Deu certo"


valgrind: vl
	@ clear
	@ valgrind ${NAME_PROGRAM} ${VALGRIND_FLAGS}
	@ echo "\n\n"

clean:
	rm -rf *.o main
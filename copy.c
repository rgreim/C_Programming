#include <stdio.h>

int main (int argc, char *argv[]){

	if(argc != 3){}		//da copy src dest -> copy index 0, src index 1, dest index 2

	FILE *in, *out;

	in = fopen(argv[1], "r");

	if(in == NULL){
		perror(argv[1]);
		return 1;
	}

	out = fopen(argv[2], "w");	//erst Fehler abfangen vor out, weil sonst Fehlernummer in errno nicht mehr aktuelle wäre

	if(out == NULL){
		perror(argv[2]);
		return 1;
	}

	int numBytesRead; 
	char buf[1024];

	while(!feof(in)){
		numBytesRead = fread(buf, sizeof(buf[0]), sizeof(buf)/sizeof(buf[0]), in);
		fwrite(buf, 1, numBytesRead, out);
	}

fclose(in);
fclose(out);
}

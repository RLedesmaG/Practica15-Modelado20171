#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char *argv[])
{
	
    // Verifica si hay al menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
    if (argc < 3)
    {
        imprime_instrucciones(argv);
        return 0;
    }
    else{
    	printf("Nombre del archivo\tPalabra mas repetida\tNumero de Repeticiones\n");
    	FILE *output = fopen(argv[argc-1], "w");
    	
    	for(int h=1;h<argc-1;h++){
    		
	    	FILE *file;
			char ch, *str;
			int i=0, j=1;
			str = (char*)malloc(sizeof(char));
			file = fopen(argv[h], "r");
			while((ch=fgetc(file))!=EOF){
				str = (char*)realloc(str, j*sizeof(char));
				str[i] = ch;
				i++;
				j++;
			}
			str[i] = '\0';
			fclose(file);
			//todo el archivo está en el string str
			Lista lista = crea_lista();
			char *token;
			token = strtok(str, " ,.-");
			inserta_elemento(lista, token);
			for(int i=1;i<longitud(lista);i++){
				token = strtok(NULL, " ,.-");
				if(busca_lista(lista, token) >= 0){
					int posicion = busca_lista(lista, token);
					Elemento* it = *lista;
					for(int j=0;j<posicion;j++)
						it = it->siguiente;
					it->valor = (it->valor)++;
				}
				else
					inserta_elemento(lista, token);		
			}
			int maximo = 0;
			char* palabrota;
			Elemento* it = *lista;
			for(int i=0;i<longitud(lista);i++){
				int aux;
				aux = (long)it->valor;
				if(aux > maximo){
					maximo = aux;
					palabrota = it->str;
				}
				it=it->siguiente;	
			}

			printf("%s\t%s\t%d\n",argv[h], palabrota, maximo);
			printf("todo va bien\n");

			fprintf(output, "%s\t\t\t%s\t\t\t%d\n", argv[h], palabrota, maximo);

		}
		fclose(output);

	}

    return 0;
}


/* ------ Aquí va la implementación de tus funciones ------ */



void imprime_instrucciones(char const *argv[]){
	printf("Error: El formato de entrada es incorrecto\n");
	printf("Uso: ");
	printf ("%s", argv[0]);
	printf(" <archivo> [<archivo> [<archivo> ...]] <archivo>\n");
}

void borra_lista(Lista lista){
    Elemento* it = *lista;
    for(int i=0;i<longitud(lista);i++){
        Elemento* aux = it->siguiente;
        free(it->valor);
        free(it);
        it = aux;
    }
}

Lista crea_lista(){
    
    Lista lista = malloc(sizeof(Lista));
	return lista;
	
}

int inserta_elemento(Lista lista, char* str){
    Elemento* nuevo = malloc(sizeof(Elemento));
    int uno = 1;

    nuevo->siguiente = *lista;
    nuevo->valor = &uno;
    nuevo->str = str;
    *lista = nuevo;
    return longitud(lista)+1;   
}

size_t longitud(Lista lista){
    if(*lista == NULL)
        return 0;

    size_t len = 1;
    Elemento* cabeza = *lista;
    Elemento* it = cabeza->siguiente;
    while(it != NULL){
        it = it->siguiente;
        len++;
    }
    return len;
}

int busca_lista(Lista lista, char *word){
	Elemento* it = *lista;
	for(int i=0;i<longitud(lista);i++){
		if(strcmp(word, it->str) == 0)
			return i;
		else
		it = it->siguiente;
	}
	return -1;
}


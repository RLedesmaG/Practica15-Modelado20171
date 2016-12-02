#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char const *argv[])
{
    // Verifica si hay al menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
    if (argc < 3)
    {
        imprime_instrucciones();
        return 0;
    }

    return 0;
}


/* ------ Aquí va la implementación de tus funciones ------ */

int procesa_archivo(char archivo[]){
	FILE *file;
	char ch, *str;
	int i=0, j=1;
	str = (char*)malloc(sizeof(char));
	file = fopen(archivo, "r");
	while((ch=fgetc(file))!=EOF){
		str = (char*)realloc(str, j*sizeof(char));
		str[i] = c;
		i++;
		j++;
	}
	str[i] = '\0';
	fclose(file);
	//todo el archivo está en el string str
	Lista lista = crea_lista();
	char *token;
	token = strtok(str, " ,.-");
	insterta_elemento(lista, token);
	for(int i=1;i<longitud(lista);i++){
		token = strtok(NULL, " ,.-");
		if(busca_lista(lista, token)){
			Elemento* buscador = *lista;
			while(true){
				if(strcmp(word, buscador->str) == 0){
					buscador->valor = valor+1;
					continue;
				}
				else
				buscador = buscador->siguiente;
			}
		}
		else
			inserta_elemento(lista, token);		
	}
	int maximo = 0;
	char* palabrota;
	Elemento* it = *lista;
	for(int i=0;i<longitud(lista);i++){
		if(it->valor > maximo){
			maximo = it->valor;
			palabrota = it->str;
		}
		it=it->siguiente;	
	}
	printf("%s", palabrota);
}

void imprime_instrucciones(){
	printf("Uso: ");
	printf("%s", argv[0]);
	printf("<archivo> [<archivo> [<archivo> ...]] <archivo>");
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
    nuevo->siguiente = *lista;
    nuevo->valor = 1;
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

bool busca_lista(Lista lista, char *word){
	Elemento* it = *lista;
	for(int i=0;i<longitud(lista);i++){
		if(strcmp(word, it->str) == 0)
			return true;
		else
		it = it->siguiente;
	}
	return false;
}


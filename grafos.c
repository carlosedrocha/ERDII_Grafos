#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define NUM_VERTICES 6

//HEADER
void menuMostrar();
void grafoProcurar();
void grafoCriar();
void dijkstra (int vertices, int origem, int destino, float *custos);

//VARIAVEIS
int destino, origem, vertices = 0;
float custo, *custos = NULL;

 
//Funcao principal
int main (){
  
    setlocale (LC_ALL, "Portuguese");

    char opt;
    grafoCriar ();
        
    do{
        opt = -1;     
        //Desenha o menu na tela
        menuMostrar ();
        scanf ("%d", &opt);
            
        switch (opt){
        case 1:
            //cria um novo grafo
            grafoCriar();
            break;
            
        case 2:
            //procura os caminhos
            if (vertices > 0){
            grafoProcurar ();
            }
            break;

        default:
            printf ("Opcao invalida");
        }
            
        fflush (stdin);
            
    }
    while (opt != 0);
    
    system ("cls");
    
    printf
        ("------------------------  FINALIZANDO APLICACACAO  -------------------------\n");
    
    system ("pause");
    
    return 0;

}


 
 
//ImplementaC'C#o do algoritmo de Dijkstra
  void dijkstra (int vertices, int origem, int destino, float *custos) {
  
        int i, v, cont = 0;
        
        int *ant, *temp;
        
        int *kv;    /* vertices para os quais se conhece o caminho minimo */
        
        double min;
        
        double dist[vertices];	/* vetor com os custos dos caminhos */
        
        /* aloca as linhas da matriz */ 
            ant = (int *) calloc (vertices, sizeof (int *));
        
        if (ant == NULL){
            printf ("** Erro: Memoria Insuficiente **");
                
            exit (-1);
            
        }
        
        temp = (int *) calloc (vertices, sizeof (int *));
        
        if (temp == NULL){                
            printf ("** Erro: Memoria Insuficiente **");   
            exit (-1);
        }
        
        kv = (int *) calloc (vertices, sizeof (int *));
        
        if (kv == NULL){            
            printf ("** Erro: Memoria Insuficiente **");
            exit (-1);
        }
        
        for (i = 0; i < vertices; i++){
            
            if (custos[(origem - 1) * vertices + i] != -1){
                
                ant[i] = origem - 1;
                dist[i] = custos[(origem - 1) * vertices + i];
                
            } else{
                ant[i] = -1;
                dist[i] = HUGE_VAL;
            }
                
            kv[i] = 0;
            
        }
        
        kv[origem - 1] = 1;
        
        dist[origem - 1] = 0;
        
        /* Laco principal */ 
        do{
                
            /* Encontrando o vertice que deve entrar em kv */ 
            min = HUGE_VAL;
                
            for (i = 0; i < vertices; i++){
                
                if (!kv[i]){
                        
                    if (dist[i] >= 0 && dist[i] < min){
                            
                        min = dist[i];
                            v = i;      
                    }
                        
                }
            }
                
            //* Calculando as distancias dos novos vizinhos de kv */
                    if (min != HUGE_VAL && v != destino - 1){
                    
                kv[v] = 1;
                    
                    for (i = 0; i < vertices; i++){
                            
                    if (!kv[i]){
                            
                        if (custos[v * vertices + i] != -1 && dist[v] 
                                    +custos[v * vertices + i] < dist[i]){
                                    
                            dist[i] = dist[v] + custos[v * vertices + i];
                                        
                            ant[i] = v;
                                        
                        }
                            
                    }     
                }   
            }   
        }
        while (v != destino - 1 && min != HUGE_VAL);
        
        /* Mostra o Resultado da busca */ 
            printf ("\tDe %d para %d: \t", origem, destino);
        
        if (min == HUGE_VAL){
            
            printf ("Nao Existe\n");
                
            printf ("\tCusto: \t- \n");
            
        }
        
            else {
            i = destino;
                
            i = ant[i - 1];
                
            while (i != -1){
                
                temp[cont] = i + 1;
                    
                cont++;
                    
                i = ant[i];
                    
            }
                
            for (i = cont; i > 0; i--){
                
                printf ("%d -> ", temp[i - 1]);
                
            }
                
            printf ("%d", destino);
                
            printf ("\n\tCusto: %.3f\n", (float) dist[destino - 1]);

        } 

} 
 
 
void grafoCriar (void){
    
    vertices = NUM_VERTICES;
        
    printf("-------------------------------------------- Seja Bem vindo!  -----------------------------------------------\n");
    
    if (!custos){
        
        free (custos);
        
    }
    
    custos = (float *) malloc (sizeof (int) * vertices * vertices);
    
    //Se o compilador falhou em alocar espaC'o na memC3ria
        if (custos == NULL){
            
        printf ("** Erro: Memoria Insuficiente **");
            
        exit (-1);
            
    }
    
    //Preenchendo a matriz com -1
    for (int i = 0; i <= vertices * vertices; i++){
        custos[i] = -1;
        
    } 
    do{
        printf ("Entre com as arestas/caminhos:\n");
            
            do{
                
            printf ("Origem (entre 1 e %d ou 0 para sair): ", vertices);


            //COLOCAR AQUI A RANDOMIZACAO PARA VERTICE ORIGEM    
            scanf ("%d", &origem);
                
            fflush (stdin);
            
        }while (origem < 0 || origem > vertices);
            
        if (origem){
            
            do{
                    
                printf ("Destino (entre 1 e %d, menos %d): ", vertices,origem);

                //COLOCAR AQUI A RANDOMIZACAO PARA VERTICE DESTINO    
                scanf ("%d", &destino);
                        
                fflush (stdin);
                
            }while (destino < 1 || destino > vertices || destino == origem);
            
            do{
                    
                printf ("Custo (positivo) do %d para o %d: ", origem, destino);
                
                //COLOCAR AQUI A RANDOMIZACAO PARA CUSTO    
                scanf ("%f", &custo);
                fflush (stdin);
                
            }while (custo < 0);
            
            custos[(origem - 1) * vertices + destino - 1] = custo;
        }
    }
    while (origem);

}


 
 
//Busca os menores caminhos entre os vertices
  void grafoProcurar (){
    int i, j;
       
    printf ("Custo por rotas a partir do inicio 1: \n");
    
    for (i = 1; i <= 1; i++){
        
        for (j = 2; j <= NUM_VERTICES; j++){
            dijkstra (vertices, i, j, custos);
        }
        printf("\n");    
    }
    
} 
//Desenha o menu na tela
void menuMostrar(void)
{
  
    printf
        ("----------------------- OTIMIZADOR DE ROTA ------------------------\n");
    
    printf
        ("-------------------------------------------------------------------\n");
        
    printf ("\t1- Criar o grafo e suas arestas/caminhos.\n");
    
    printf ("\t2- Ver custo por rotas.\n");
    
    printf ("\t0- Sair\n");
}
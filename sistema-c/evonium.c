#include <stdio.h> 
 
int main(){ 
 
        char user[30]; 
        int quant=0, opcao,escolha_p; // variaveis escolhas 
        float preco1 = 199.90,preco2= 149.90,preco3= 99.90,preco4=  249.90,preco5= 179.90; //precos 
 
    printf("Digite seu Login: ");// nome do usuario 
    fgets(user,30,stdin);//nome 
 
    do{ 
            printf("Bem Vindo %s", user); // apresentando usuario 
 
             printf("Voce tem as seguintes opcoes:"); // apresentar opcoes 
             printf("\n\n"); 
 
            printf("___1 -Fazer encomenda de perfume___\n"); // primeira opcao 
            printf("___2 -Alteracao de preco___\n"); 
            printf("___3 -Conheca nossas parcerias___\n"); 
            printf("___4 -Quem somos nos___\n"); 
            printf("___5 -Finalizar programa___\n");           
            printf("--- Escolha uma opcao ---\n"); 
            scanf("%d", &opcao); 
 
         switch(opcao){ 
                case 1 : 
                    do{//looping dos perfumes 
                        printf("1-Essence Blue = %.2f\n", preco1); 
                        printf("2-Floral Dream = %.2f\n", preco2); 
                        printf("3-Citrus Fresh = %.2f\n", preco3); 
                        printf("4-Night Intense = %.2f\n", preco4); 
                        printf("5-Sweet Rose = %.2f\n", preco5); 
                        printf("6-Finalizar pedido."); 
                        printf("--- Escolha uma opcao ---\n"); 
                        scanf("%d", &escolha_p); 
 
                            switch(escolha_p){ // quantidade 
                                    case 1: 
                                    case 2: 
                                    case 3: 
                                    case 4: 
                                    case 5: 
                                        printf("Escolha a quantidade de perfume para encomenda: "); 
                                        scanf("%d", &quant); 
                                        printf("\nVoce escolheu %d unidade(s), valor = R$\n", quant); 
                                    break; 
                                    case 6: 
                                        printf("Finalizando pedido...\n"); 
                                    break; 
                                default: 
                                    printf("Opcao invalida!\n");   
                            } 
                        }while(escolha_p != 6); 
                        break; 
                    
                        case 2: 
                        printf("v"); 
                        break; 
                        case 3: 
                        printf("v"); 
                        break; 
                        case 4: 
                        printf("v"); 
                        break; 
                    } 
        }while(opcao!=5); 
 
    return 0; 
 
} 
 
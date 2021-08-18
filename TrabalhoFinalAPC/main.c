#include <stdio.h>
#define TAM 100
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *estados;
FILE *cidades;
FILE *pessoas;
FILE *idades;
FILE *sexo;

struct dados{

    char nome[TAM];
    char sexo;
    int dia, mes, ano;
    char city[TAM];
    char estado[TAM];

};

struct dados pessoa;

int cadastrar_estado(){

     char estado[TAM];
     char arquivado[TAM];
     char var;
     char texto[TAM];
     int n, m, i, j;
     int flag;

//repetição da função até que se digite que não quer cadastrar mais
  do{
    //Menu Introdutório da função
     system("cls");
     printf("//CADASTRO DE ESTADO//\n");
     printf("\n1 - Cadastrar Estado(s):\n2 - Listar Estados Cadastrados:\n3 - Voltar ao Menu Principal: \n");
     printf("\nDigite a função que deseja realizar: ");
     scanf("%d", &m);

    //Possibilidades de erro de opção do Menu
     if(m!=1 && m!=2 && m!=3){
         printf("Opção não identificada");
         getch();
     return 1;
     }

    //Ir para o Menu Principal
     if(m==3){
        return 1;
     }

     //Listar estados de acordo com os já cadastrados
     if(m==2){
         system("cls");
         FILE *estados=fopen("estados.txt","a+");
         printf("//LISTA DE ESTADOS//\n");
         //Leitura de arquivo de linha por linha para printar os Estados que foram cadastrados
         while(!feof(estados)){
             fgets(texto, sizeof(texto)-1, estados);
             if(!feof(estados)){
                 printf("%s", texto);
             }
         }
     fclose(estados);
     }

    //Cadastrar estado que ainda não foi cadastrado
     if(m==1){
         system("cls");
         flag=0;
         fflush(stdin);
         //Leitura do nome de Estado e verificação no arquivo se já existe ou não
         printf("Digite o nome do Estado: ");
         fflush(stdin);
         fgets(estado, TAM, stdin);

        //Transformar tudo em minúscula para salvar no Arquivo
         for(j = 0; j < strlen(estado); j++){
             estado[j] = tolower(estado[j]);
         }

         //Verificar de o arquivo de estados existe, para, se não, criá-lo
         estados = fopen("estados.txt","a+");
         if(estados==NULL){
             estados = fopen("estados.txt","a");
             fprintf(/*onde*/estados,/*quem*/"%s",/*nome*/estado);
             fclose(estados);
             printf("\n*Cadastro efetivado*\n");
         }else{
             //Leitura de arquivo dos estados e mostrar mensagem caso já exista
             while(!feof(estados)){
                 fgets(arquivado, TAM, estados);
                 if(strcmp(estado,arquivado) == 0 && !feof(estados)){
                     printf("\nEstado já cadastrado! \n");
                     fflush(stdin);
                     flag=1;
                     break;
                 }
             }
             if(flag==0){
                //Mensagem de Confirmação de cadastro
                 estados = fopen("estados.txt","a");
                 fprintf(/*onde*/estados,/*quem*/"%s",/*nome*/estado);
                 fclose(estados);
                 printf("*Cadastro efetivado*\n");
              }
         }
     }
     fflush(stdin);

    //Leitura de variavel S ou N para dar rotatividade a função
     printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
     scanf("%c", &var);
     if(var=='N' || var=='n'){
         return 1;
     }else if(var!='N' && var!='n' && var!='S' && var!='s'){
         printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
         getch();
         return 1;
     }
  }while(var == 'S' || var=='s');
}

int cadastrar_cidade(){

     int n, m, i, p, j;
     int flag;
     int variavel;
     char var;
     char texto[TAM];
     char state[TAM];
     char registrado[TAM];
     char cidade[TAM];
     char arquivado[TAM];

  do{
     system("cls");
     //Menu Introdutório da função
     printf("//CADASTRO DE CIDADE//\n");
     printf("\n1 - Cadastrar Cidade(s):\n2 - Listar Cidades Cadastradas:\n3 - Voltar ao Menu Principal: \n");
     printf("\nDigite a função que deseja realizar: ");
     scanf("%d", &m);

    //Procedimento caso opções sejam diferentes das apresentadas
     if(m!=1 && m!=2 && m!=3){
         printf("Opção não identificada");
         getch();
     return 1;
     }

    //Retorno ao Menu Principal
     if(m==3){
        return 1;
     }

    //Lista de cidades de acordo com as que foram cadastradas anteriormente
     if(m==2){
     system("cls");
         cidades=fopen("cidades.txt","a+");
         printf("//LISTA DE CIDADES//\n");
         //Leitura de linha por linha para printar as cidades que foram cadastradas.
         while(!feof(cidades)){
             fgets(texto, TAM, cidades);
             if(!feof(cidades)){
                 printf("%s", texto);
             }
         }
     fclose(cidades);
     }

    //Cadastro de cidades
     if(m==1){
         system("cls");
         variavel=0;
         flag=0;

         //Leitura do nome da cidade e transformação para letra minúscula
         printf("Digite o nome do Estado correspondente: ");
         fflush(stdin);
         fgets(state, TAM, stdin);

         for(j = 0; j < strlen(state); j++){
             state[j] = tolower(state[j]);
         }

         //Abertura do Arquivo estados para conferir se o Estado ja foi cadastrado
         estados=fopen("estados.txt","r");
         variavel=1;
         while(!feof(estados)){
             fflush(stdin);
             fgets(registrado, TAM, estados);
             if(strcmp(registrado, state)==0){
                 variavel=1;
                 break;
             }else{
                variavel=0;
             }
         }
         if(variavel==0){
            printf("\nO Estado correspondente ainda não foi cadastrado!\nVolte ao Menu Principal para Cadastrar o Estado (1) clicando em qualquer tecla.");
            getch();
            return 1;
         }

        //Leitura da Cidade e transformação para minúscula
         fflush(stdin);
         printf("Digite o nome da Cidade: ");
         fflush(stdin);
         fgets(cidade, TAM, stdin);

         for(p=0;p<=strlen(cidade)+1;p++){
            if(cidade[p]=='\n'){
                cidade[p]=' ';
            }
         }

         for(j = 0; j < strlen(cidade); j++){
             cidade[j] = tolower(cidade[j]);
         }

         //Abertura de arquivo para salvar a cidade digitada no arquivo
         cidades = fopen("cidades.txt","a+");
         if(cidades==NULL){
             cidades = fopen("cidades.txt","a");
             fprintf(/*onde*/cidades,/*quem*/"%s- %s",/*nome*/cidade, state);
             fclose(cidades);
             printf("\n*Cadastro efetivado*\n");
         }else{
             //Caso a cidade ja tenha sido cadastrada, apresentar a mensagem
             while(!feof(cidades)){
                 fgets(arquivado, TAM, cidades);
                 if(strstr(arquivado,cidade) != 0 && strstr(arquivado, state) != 0 && !feof(cidades)){
                     printf("\nCidade já cadastrada! \n");
                     fflush(stdin);
                     flag=1;
                     break;
                 }
             }
             if(flag==0){
                //Confirmação de que a cidade foi registrada sem erros
                 cidades = fopen("cidades.txt","a");
                 fprintf(/*onde*/cidades,/*quem*/"%s- %s",/*nome*/cidade, state);
                 fclose(cidades);
                 printf("*Cadastro efetivado*\n");
              }
         }
     }
     fflush(stdin);

     //Leitura de variavel para dar rotatividade a função
     printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
     scanf("%c", &var);
     if(var=='N' || var=='n'){
         return 1;
     }else if(var!='N' && var!='n' && var!='S' && var!='s'){
         printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
         getch();
         return 1;
     }
}while(var == 'S' || var=='s');

}

int cadastrar_pessoas(){

    char var;
    char city[TAM];
    char estado[TAM];
    char registrado[TAM];
    char arquivado[TAM];
    char letra;
    int conte_masculino=0;
    int conte_feminino=0;
    int m, variavel, flag;
    int mes[12] = {1,2,3,4,5,6,7,8,9,10,11,12}, j, p;
    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int diah, mesh, anoh;
    int bissexto=365;
    int age_um=0;
    int age_dois=0;
    int age=0;

   do{
     system("cls");
     //Menu Introdutório para o cadastramento de pessoas
     printf("//CADASTRO DE PESSOAS//\n");
     printf("\n1 - Cadastrar Pessoa(s):\n2 - Voltar ao Menu Principal:\n");
     printf("\nDigite a função que deseja realizar: ");
     scanf("%d", &m);

    //Caso a leitura seja diferente do Menu
    if(m!=1 && m!=2){
         printf("Opção não identificada.\nClique em qualquer tecla e voltará ao Menu Principal.");
         getch();
         return 1;
     }

     //Caso queira voltar pro Menu Principal
     if(m==2){
        return 1;
     }

     if(m==1){
        system("cls");
        //Leitura do estado e trasnformação para minuscula
        printf("Digite a sua Unidade Federativa: ");
        fflush(stdin);
        fgets(pessoa.estado, TAM, stdin);

        for(j = 0; j < strlen(pessoa.estado); j++){
            pessoa.estado[j] = tolower(pessoa.estado[j]);
        }

        //Confirmar se estado ja foi cadastrado anteriormente
        estados=fopen("estados.txt","r");
        variavel=1;
        while(!feof(estados)){
            fflush(stdin);
            fgets(registrado, TAM, estados);
            if(strcmp(registrado, pessoa.estado)==0){
                variavel=1;
                break;
            }else{
                variavel=0;
            }
        }

        if(variavel==0){
            printf("\nO Estado correspondente ainda não foi cadastrado!\nVolte ao Menu Principal para Cadastrar o Estado (1) clicando em qualquer tecla.");
            getch();
            return 1;
        }

        //Ler a cidade e trasnformar para minuscula
        printf("Digite o nome da sua Cidade: ");
        fflush(stdin);
        fgets(pessoa.city, TAM, stdin);


        for(j = 0; j < strlen(pessoa.city); j++){
            pessoa.city[j] = tolower(pessoa.city[j]);
        }

        for(p=0;p<=strlen(pessoa.city);p++){
            if(pessoa.city[p]=='\n'){
                pessoa.city[p]=' ';
            }
         }

        //Confirmar se a cidade ja foi cadastrado anteriormente
        cidades=fopen("cidades.txt", "r");
        flag=0;
        while(!feof(cidades)){
            fflush(stdin);
            fgets(arquivado, TAM, cidades);
            if(strstr(arquivado,pessoa.city) != 0 && strstr(arquivado, pessoa.estado) != 0){
                fflush(stdin);
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\nO Cidade correspondente ainda não foi cadastrada!\nVolte ao Menu Principal para Cadastrar a Cidade (2) clicando em qualquer tecla.\n");
            getch();
            return 1;
        }

        //Ler nome e trasnformar em minuscula
        printf("Digite o seu nome: ");
        fflush(stdin);
        fgets(pessoa.nome, TAM, stdin);

        for(j = 0; j < strlen(pessoa.nome); j++){
            pessoa.nome[j] = tolower(pessoa.nome[j]);
        }

        //Leitura do sexo e transformar em minuscula
        printf("Digite o sexo (M/F): ");
        fflush(stdin);
        scanf("%c", &pessoa.sexo);
        pessoa.sexo = tolower(pessoa.sexo);

        //Caso a opcao digitada seja diferente de m ou f
        if(pessoa.sexo!='m' && pessoa.sexo!='f'){
            printf("\nOpção não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }

        //Leitura da data de nascimento e confirmação se a data é válida ou não de acordo com o calendário padrão
        printf("Digite a data de nascimento (formato: XX/YY/ZZZZ): ");
        fflush(stdin);
        scanf("%d/%d/%d", &pessoa.dia, &pessoa.mes, &pessoa.ano);

        if (pessoa.ano % 4 == 0 && (pessoa.ano % 400 == 0 || pessoa.ano % 100 != 0)){
            dias[1]=29;
            bissexto=366;
        }

        if(pessoa.mes > mes[11] || pessoa.mes < mes[0]){
            printf("\nData não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }

        if(pessoa.dia > dias[pessoa.mes - 1] || pessoa.dia < 1){
            printf("\nData não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }

        if(pessoa.ano>2019){
            printf("\nData não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }

        //Calculo da idade através da data posta de hoje e de nascimento
        age_um=pessoa.dia + pessoa.mes*dias[pessoa.mes-1] + pessoa.ano*bissexto;
        printf("Digite a data de hoje (formato: XX/YY/ZZZZ): ");
        fflush(stdin);
        scanf("%d/%d/%d",&diah, &mesh, &anoh);

        //Confirmação se a data existe
        if (anoh % 4 == 0 && (anoh % 400 == 0 || anoh % 100 != 0)){
            dias[1]=29;
        }

        if(mesh > mes[11] || mesh < mes[0]){
            printf("\nData não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }

        if(diah > dias[mesh - 1] || diah < 1){
            printf("\nData não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }

        if(anoh<pessoa.ano){
            printf("\nData não identificada. Infelizmente, o cadastro ainda não foi concluído.\nClique em qualquer tecla e voltará ao Menu Principal.");
            getch();
            return 1;
        }
        age_dois=diah + mesh*dias[mesh-1] + anoh*bissexto;
        age=(age_dois-age_um)/365;

        //Abertura do arquivo para salvar todos os dados colocados pela pessoa, depois das confirmações de erro
        pessoas=fopen("pessoas.txt","a");
        fprintf(pessoas, "%s%s\n%s%c\n%.2d/%.2d/%.4d\n", pessoa.estado, pessoa.city, pessoa.nome, pessoa.sexo, pessoa.dia, pessoa.mes, pessoa.ano);
        fclose(pessoas);

        //Abertura do arquivo para por as idades para o relatório geral
        idades=fopen("idades.txt","a");
        fprintf(pessoas, "%d\n", age);
        fclose(idades);

        //Abertura do arquivo para por os sexos para o relatório geral
        sexo=fopen("sexo.txt","a");
        fprintf(sexo, "%c\n", pessoa.sexo);
        fclose(sexo);
     }

     //Função de rotatividade do Menu Introdutoório para o Principal
     fflush(stdin);
     printf("\nO cadastro foi concluído com sucesso!");
     printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
     scanf("%c", &var);
     if(var=='N' || var=='n'){
         return 1;
     }else if(var!='N' && var!='n' && var!='S' && var!='s'){
         printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
         getch();
         return 1;
     }
  }while(var == 'S' || var=='s');
}

int listar_estado(){

    char var;
    char texto[TAM];
    char registrado[TAM];
    char state[TAM];
    char linha[TAM];
    int valido=1, i=1, j;
    int m, variavel;

    do{
    //Menu Introdutório para listar pessoas de acordo com Estado
     system("cls");
     printf("//LISTAR PESSOAS POR ESTADO//\n");
     printf("\n1 - Listar pessoa(s) por Estado:\n2 - Listar Estados Cadastrados:\n3 - Voltar ao Menu Principal: \n");
     printf("\nDigite a função que deseja realizar: ");
     scanf("%d", &m);

     //Caso a leitura seja diferente das opçoes apresentadas no Menu
     if(m!=1 && m!=2 && m!=3){
         printf("Opção não identificada");
         getch();
     return 1;
     }

     //Caso queira voltar ao Menu Principal
     if(m==3){
        return 1;
     }

    //Caso queira fazer a listagem de estados ja cadastrados
     if(m==2){
         system("cls");
         //Abertura do arquivo para printar linha por linha os estados então registrados
         FILE *estados=fopen("estados.txt","a+");
         printf("//LISTA DE ESTADOS//\n");
         while(!feof(estados)){
             fgets(texto, TAM, estados);
             if(!feof(estados)){
                 printf("%s", texto);
             }
         }
     fclose(estados);
     }

     if(m==1){
        system("cls");
        printf("//LISTAR PESSOAS POR ESTADOS//\n");
        //Leitura do Estado que deseja se listar e trasnformação para minuscula
		printf ("\nEstado: ");
		fflush (stdin);
		fgets (state, TAM, stdin);
		printf("\n");

        for(j = 0; j < strlen(state); j++){
             state[j] = tolower(state[j]);
        }

        //Abertura do arquivo para ver se o Estado digitado foi cadastrado
        estados=fopen("estados.txt","r");
        variavel=1;
        while(!feof(estados)){
            fflush(stdin);
            fgets(registrado, TAM, estados);
            if(strcmp(registrado, state)==0){
                variavel=1;
                break;
            }else{
                variavel=0;
            }
         }
         if(variavel==0){
            printf("\nO Estado correspondente ainda não foi cadastrado!\nVolte ao Menu Principal para Cadastrar o Estado (1) clicando em qualquer tecla.");
            getch();
            return 1;
         }

        //Abertura do arquivo para comparar linha por linha se existe algum nome de pessoas que registrou com tal estado
		FILE *pessoas = fopen("pessoas.txt", "r");

	    while(!feof(pessoas)){
	        fgets(linha,TAM,pessoas);
	        if(i==1){
	            if(strcmp(linha,state)==0){
	                valido=0;
	            }
	        }
	        if(i==3 && valido==0){
	            printf("%s", linha);
	            valido=1;
	        }
	        i++;
	        if(i==6){
	            i=1;
	        }
	    }
	    fclose(pessoas);
        }
        fflush(stdin);

        //Função de rotatividade do programa
        printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
        scanf("%c", &var);
        if(var=='N' || var=='n'){
            return 1;
        }else if(var!='N' && var!='n' && var!='S' && var!='s'){
            printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
            getch();
            return 1;
        }
  }while(var == 'S' || var=='s');
}

int listar_cidade(){

    int m, variavel, flag=0;
    int valido=1, i=1, j, p;
    char var;
    char texto[TAM];
    char registrado[TAM], arquivado[TAM];
    char city[TAM], state[TAM];
    char linha[TAM];

    do{
     system("cls");
     //Menu Introdutório para a listagem de pessoas por cidade
     printf("//LISTAR PESSOAS POR CIDADE//\n");
     printf("\n1 - Listar pessoa(s) por Cidade:\n2 - Listar Cidades Cadastradas:\n3 - Voltar ao Menu Principal: \n");
     printf("\nDigite a função que deseja realizar: ");
     scanf("%d", &m);

     //Caso a opçao digitada seja diferente das apresentadas no Menu
     if(m!=1 && m!=2 && m!=3){
         printf("Opção não identificada");
         getch();
     return 1;
     }

     //Caso queira voltar ao Menu Principal
     if(m==3){
        return 1;
     }

     //Caso queira listar todas as cidades
     if(m==2){
     system("cls");
        //Abertura do arquivo para printar, linha por linha, as cidades que foram cadastradas
         cidades=fopen("cidades.txt","a+");
         printf("//LISTA DE CIDADES//\n");
         while(!feof(cidades)){
             fgets(texto, TAM, cidades);
             if(!feof(cidades)){
                 printf("%s", texto);
             }
         }
     fclose(cidades);
     }

     //Caso queira listar por cidades e trasnformação para minusculas
     if(m==1){
        system("cls");
        printf("//LISTAR PESSOAS POR CIDADES//\n");

        printf ("\nEstado: ");
		fflush (stdin);
		fgets (state, TAM, stdin);

        for(j = 0; j < strlen(state); j++){
             state[j] = tolower(state[j]);
        }

        //Abertura do arquivo para confirmar se o Estado posto existe e ja foi cadastrado
        estados=fopen("estados.txt","r");
        variavel=1;
        while(!feof(estados)){
            fflush(stdin);
            fgets(registrado, TAM, estados);
            if(strcmp(registrado, state)==0){
                variavel=1;
                break;
            }else{
                variavel=0;
            }
         }
         if(variavel==0){
            printf("\nO Estado correspondente ainda não foi cadastrado!\nVolte ao Menu Principal para Cadastrar o Estado (1) clicando em qualquer tecla.");
            getch();
            return 1;
         }

         //Leitura da cidade e trasnformação para minuscula
        printf("Cidade: ");
        fflush (stdin);
		fgets (city, TAM, stdin);
		printf("\n");

        for(j=0;j<strlen(city);j++){
            city[j]=tolower(city[j]);
        }

        for(p=0;p<=strlen(city);p++){
            if(city[p]=='\n'){
                city[p]=' ';
            }
         }

        //Abertura do arquivo cidades e confirmação se a cidade ja foi cadastrada anteriormente
        cidades=fopen("cidades.txt", "r");
        flag=0;
        while(!feof(cidades)){
            fflush(stdin);
            fgets(arquivado, TAM, cidades);
            if(strstr(arquivado,city) != 0 && strstr(arquivado,state) != 0){
                fflush(stdin);
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\nO Cidade correspondente ainda não foi cadastrada!\nVolte ao Menu Principal para Cadastrar a Cidade (2) clicando em qualquer tecla.\n");
            getch();
            return 1;
        }

        //Printar o nome da pessoa correspondente a cidade digitada
        FILE *pessoas = fopen("pessoas.txt", "r");

	    while(!feof(pessoas)){
	        fgets(linha,TAM,pessoas);
	        if(i==2){

	            if(strstr(linha,city)!=NULL){
	                valido=0;
	            }
	        }
	        if(i==3 && valido==0){
	            printf("%s", linha);
	            valido=1;
	        }
	        i++;
	        if(i==6){
	            i=1;
	        }
	    }
	    fclose(pessoas);
        }

        fflush(stdin);

        //Função de rotação para os Menus
        printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
        scanf("%c", &var);
        if(var=='N' || var=='n'){
            return 1;
        }else if(var!='N' && var!='n' && var!='S' && var!='s'){
            printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
            getch();
            return 1;
        }
  }while(var == 'S' || var=='s');
}

int consultar_nome(){

    char nome[TAM];
    char leitor[TAM];
    char linha[TAM][TAM];
    char var;
    int j, i=0, p=0;
    char *cmp;

    do{
     system("cls");
     //Menu Introdutório para a consulta de nomes que ja foram cadastrados e trasnformação para minúscula
     printf("//CONSULTAR NOMES CADASTRADOS//\n");
     printf("\nDigite o nome que deseja proucurar: ");
     fflush(stdin);
     fgets(nome, TAM, stdin);

     for(p=0;p<=strlen(nome)+1;p++){
            if(nome[p]=='\n'){
                nome[p]='\0';
            }
      }

     for(j = 0; j < strlen(nome); j++){
         nome[j] = tolower(nome[j]);
     }

     //Abertura do arquivo para ler, de um em um, as informações obtidas com a leitura do nome no arquivo
     pessoas= fopen("pessoas.txt","r");
     while(!feof(pessoas)){
         fgets(linha[i],TAM,pessoas);
         fgets(linha[i+1],TAM,pessoas);
         fgets(linha[i+2],TAM,pessoas);
         fgets(linha[i+3],TAM,pessoas);
         fgets(linha[i+4],TAM,pessoas);
         cmp = strstr(linha[i+2],nome);
        if(cmp!=NULL){
            //Printar todas as informações lidas anteriormente
            printf("\n------Pessoa encontrada------\n");
            printf("Nome: %s",linha[i+2]);
            printf("Sexo: %s",linha[i+3]);
            printf("Estado: %s",linha[i]);
            printf("Cidade: %s",linha[i+1]);
            printf("Data de nascimento: %s\n",linha[i+4]);
        }
        i=i+5;
    }
    fclose(pessoas);

    //Função de rotatividade entre os Menus do programa
    printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
    scanf("%c", &var);
    if(var=='N' || var=='n'){
        return 1;
    }else if(var!='N' && var!='n' && var!='S' && var!='s'){
        printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
        getch();
        return 1;
    }
  }while(var == 'S' || var=='s');
}

int relatorio(){

    float conte_tudo=0;
    float crianca=0;
    float criancinha=0;
    float adulto=0;
    float velho=0;
    float idoso=0;
    float jovem=0;
    char genero;
    char barraene;
    char var;
    int conte_masculino=0;
    int conte_feminino=0;
    int varia=0;
    int m, ano;

    do{
     system("cls");
     //Menu Introdutório para o relato demográfico
     printf("//RELATÓRIO DEMOGRÁFICO//\n");
     printf("\n1 - Percentual de Pessoas por Faixa Etária:\n2 - Percentual de Pessoas por Sexo:\n3 - Voltar ao Menu Principal: \n");
     printf("\nDigite a função que deseja realizar: ");
     scanf("%d", &m);

     //Caso a opçao digitada nao seja encontrada no Menu
     if(m!=1 && m!=2 && m!=3){
         printf("Opção não identificada");
         getch();
         return 1;
     }

     //Caso queira retornar ao Menu Principal
     if(m==3){
        return 1;
     }

     //Caso queira saber os dados sobre as pessoas cadastradas, sobre o gênero delas.
     if(m==2){
        system("cls");
        sexo=fopen("sexo.txt","r");

        while(!feof(sexo)){
            fscanf(sexo, "%c%c", &genero, &barraene);
            conte_tudo++;
        }

        fseek(sexo, 0, SEEK_SET);

        //Leitura do arquivo, linha por linha, contando 'm' e 'f' para contabilizar no relatório
        while(!feof(sexo)){
            fscanf(sexo, "%c%c", &genero, &barraene);
            varia++;
            if(varia!=conte_tudo){
                if(genero=='m'){
                    conte_masculino++;
                }
                if(genero=='f'){
                    conte_feminino++;
                }
            }
        }
        fclose(sexo);
        //Print da contagem final de todos os 'm' e 'f' lidos no arquivo
        fflush(stdin);
        conte_tudo=conte_tudo-1;
        printf("Percentual de pessoas do Sexo Masculino: %.2f%%\n", (conte_masculino/conte_tudo)*100);
        printf("Percentuam de pessoas do Sexo Feminino: %.2f%%\n", (conte_feminino/conte_tudo)*100);
     }

     char qualquer;
     float contador=0;
     int variavel=0;
     int cont=0;

     //Caso queira o relatório final das idades
     if(m==1){
        system("cls");
        idades=fopen("idades.txt","r");

        //Ler todas as idades no arquivo, linha por linha
        while(!feof(idades)){
            fscanf(idades, "%d%c", &ano, &qualquer);
            contador++;
        }

        fseek(idades, 0, SEEK_SET);

        //Contabilizar a quantidade lida no arquivo para gerar o relatório final de acordo com as idades
         while(!feof(idades)){
            fscanf(idades, "%d%c", &ano, &qualquer);
            variavel=ano;
            cont++;

         if(cont!=contador){
            if(variavel>=0 && variavel<=5){
                criancinha++;
            }
            if(variavel>=6 && variavel<=10){
               crianca++;
            }
            if(variavel>=11 && variavel<=20){
               jovem++;
            }
            if(variavel>=21 && variavel<=40){
               adulto++;
            }
            if(variavel>=41 && variavel<=60){
               idoso++;
            }
            if(variavel>60){
               velho++;
            }
        }
        }
        fclose(idades);
        //Listagem do resultado final de acordo com as especificações de idade
        printf("Percentual de 0 a 5 anos: %.2f%%", (criancinha/(contador-1))*100);
        printf("\nPercentual de 6 a 10 anos: %.2f%%", (crianca/(contador-1))*100);
        printf("\nPercentual de 11 a 20 anos: %.2f%%", (jovem/(contador-1))*100);
        printf("\nPercentual de 21 a 40 anos: %.2f%%", (adulto/(contador-1))*100);
        printf("\nPercentual de 41 a 60 anos: %.2f%%", (idoso/(contador-1))*100);
        printf("\nPercentual maior que 60 anos: %.2f%%\n", (velho/(contador-1))*100);
     }

     fflush(stdin);

     //Função de rotatividade para o Menu Principal e Introdutório
     printf("\nDeseja retornar ao Menu De Cadastro de Estados? (S/N)\n");
     scanf("%c", &var);
     if(var=='N' || var=='n'){
         return 1;
     }else if(var!='N' && var!='n' && var!='S' && var!='s'){
         printf("\nOpção inválida\nClique em qualquer tecla para voltar ao Menu Principal");
         getch();
         return 1;
     }
  }while(var == 'S' || var=='s');
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int opcao, x;

//Função para dar rotatividade ao Menu Principal, na volta das funções específicas
  do{
    system("cls");
    //Menu Introdutório com as funcoes especificas
    printf("Menu de opções: \n1) Cadastrar Estado\n2) Cadastrar Cidade\n3) Cadastrar Pessoa\n4) Listar pessoas por Estado\n5) Listar pessoas por Cidade\n6) Consultar Pessoa por Nome\n7) Gerar relatório demográfico\n8) Finalizar Programa\n");
    printf("\nDigite a função que deseja realizar: ");
    scanf("%d", &opcao);

    //Leitura de acordo com as opçao digitada
    switch(opcao){
    case 1:
        x=cadastrar_estado();
        break;
    case 2:
        system("cls");
        x=cadastrar_cidade();
        break;
    case 3:
        system("cls");
         x=cadastrar_pessoas();
        break;
    case 4:
        system("cls");
        x=listar_estado();
        break;
    case 5:
        system("cls");
        x=listar_cidade();
        break;
    case 6:
        system("cls");
        x=consultar_nome();
        break;
    case 7:
        system("cls");
        x=relatorio();
        break;
    case 8:
        system("cls");
        printf("Programa finalizado com sucesso!\nObrigado! Volte sempre...\nDigite qualquer tecla para encerrar:\n");
        return 0;
    }

    //Caso a opcao digitada nao seja nenhuma encontrada no Menu Principal
    if(opcao>8 || opcao<1){
        system("cls");
        printf("OPSSSS...\nFunção não disponível no momento\n");
        break;
    }

  }while(x==1);
return 0;
}

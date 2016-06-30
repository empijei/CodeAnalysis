//This is one of the first piece of code i have ever written
//and i used it as an example of something hard to analyse

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int win=0,turno=0,giocatori=0,p,k=9;
    int tab[3][3]={0,0,0,
                   0,0,0,
                   0,0,0};

/*README: Per giocare i giocatori devono inserire alternatamente
un numero da 1 a 9, che corrisponderà alla casella in cui
vuole inserire il suo segnalino*/

printf("in quanti si desidera giocare?");
scanf("%d",&giocatori);
giocatori=giocatori -1;
if(!giocatori)
            turno=1;
//mainloop
    do
    {
        k--; //conto il turno
        stampa(tab); //visualizzo la griglia

        //Inizia il turno
        if(giocatori) //controllo se sono due giocatori umani o uno solo
        {
            printf("Giocatore %d, fai la tua mossa:\n",turno+1);
            do
            {
                scanf("%d",&p);
                getchar(); //se l'utente inserisce caratteri invalidi li elimino dal buffer
                p=p-1;
            }while(p<0||p>8||tab[p/3][p%3]);
        }
        else
        {
            printf("Fai la tua mossa:\n");
            do
            {
                if(!turno)
                {
                    p=scegli(tab);
                }
                else
                {
                    scanf("%d",&p);
                    getchar(); //se l'utente inserisce caratteri invalidi li elimino dal buffer
                    p=p-1;
                }
            }while(p<0||p>8||tab[p/3][p%3]);
        }
        if(turno)
            tab[p/3][p%3]=2;
        else
            tab[p/3][p%3]=7;
        //Finisce il turno

        win=check(tab); //controllo la vittoria
        turno=!turno; //cambio il turno
    }while(!win && k);
    stampa(tab);
    if(win==0)
        printf("Pareggio.");
    else
        printf("Vince il giocatore %d",win);
    return 0;
}
int scegli(int vet[3][3])
{
    //controllo righe e colonne
    int i,j,tmp;
    {

    for(i=0;i<3;i++)
    {
        tmp=0;
        for(j=0;j<3;j++)
            tmp=tmp+vet[i][j];
        if (tmp==14||tmp==4)
        {
            for(tmp=0;tmp<3;tmp++)
            if(!vet[i][tmp])
             return i*3+tmp;
        }
    }
    for(i=0;i<3;i++)
    {
        tmp=0;
        for(j=0;j<3;j++)
            tmp=tmp+vet[j][i];
        if (tmp==14||tmp==4)
        {
            for(tmp=0;tmp<3;tmp++)
            if(!vet[tmp][i])
             return i+tmp*3;
        }
    }
    }
    //controllo diagonali
    {
    tmp=0;
    for(i=0;i<3;i++)
    {
        tmp=tmp+vet[i][i];
        if (tmp==14||tmp==4)
        {
            for(tmp=0;tmp<3;tmp++)
                if(!vet[tmp][tmp])
                return tmp+tmp*3;
        }
    }
    //non funza
    tmp=0;
    for(i=0;i<3;i++)
    {
        tmp=tmp+vet[i][2-i];
        if (tmp==14||tmp==4)
        {
            for(tmp=0;tmp<3;tmp++)
                if(!vet[tmp][2-tmp])
                    return tmp*3+(2-tmp);
        }
    }
    }
/*leggere se sta per vincere o se sta per perdere, e no usa caso*/
        return caso(vet);
}
int caso(int vet[3][3])
{
    int i;
        for(i=8;i>=0;i--)
            if (vet[i/3][i%3]==0) return i;
}
int check(int vet[3][3]) //Funzione controllo vittoria
{
    int i,j,d1=0,d2=0,r[3]={0,0,0},c[3]={0,0,0};
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
                r[j]=r[j]+vet[j][i];
                c[i]=c[i]+vet[j][i];
                if(i==j)
                    d1=d1+vet[j][i];
                if(i==2-j)
                    d2=d2+vet[j][i];
        }
    if(d1==21||d2==21||r[0]==21||r[1]==21||r[2]==21||c[0]==21||c[1]==21||c[2]==21) return 1;
    if(d1==6 ||d2==6 ||r[0]==6 ||r[1]==6 ||r[2]==6 ||c[0]==6 ||c[1]==6 ||c[2]==6 ) return 2;

    return 0;
}
int stampa(int vet[3][3]) //Funzione stampa matrice
{
    system("clear"); //su windows è system("cls");
    int i,j;
    printf("\n  -----------\n");
    for(i=0;i<3;i++)
    {
        printf(" |");
        for(j=0;j<3;j++)
        {
            if (vet[i][j]==0) printf("   |");
            if (vet[i][j]==2) printf(" X |");
            if (vet[i][j]==7) printf(" O |");
        }

        printf("\n  -----------\n");
    }
}


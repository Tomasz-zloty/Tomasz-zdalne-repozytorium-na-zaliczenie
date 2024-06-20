#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int liczba;
    int strzal;
    int liczba_prob = 0;
    int wiek;
    int kasa;
    srand(time(NULL));
    liczba=rand()%100+1;
do

 {(printf)("Gra jest 18+, wpisz swoj wiek:");
    scanf("%d", &wiek);
    if (wiek>=18)
    printf("Jestes pelnoletni mozesz zagrac w nasza gre. A o to jej tresc: Pomyslalem sobie liczbe 1...100.\n Zgadnij jaka to liczba.\n Masz 6 prob.\n Jesli uda ci sie trafic w max 3 probach wygrywasz 50zl, jesli 4-6 prob 30zl.\n ");

    if (wiek<18)
   {
       printf("Jestes niepelnoletni, nie mozesz zagrac w nasza gre");
       break;
   }
 }while (wiek<18);


do
{

if (wiek<18)
{
    break;
}
    (liczba_prob++);
    printf("\nZgadnij jaka to liczba, (To twoja %li proba):",liczba_prob);
    scanf("%d", &strzal);
    if ((liczba==strzal) && (liczba_prob<=3))
    {
        printf("Brawo wygrales 50zl");
        break;
    }
       if (liczba_prob==6)
                 {
                     printf("Przekroczono liczbê prob. GAME OVER");
                        break;
                 }
    else if ((liczba==strzal) && (liczba_prob>3))
    {
        printf("Brawo wygrales 30zl");
        break;
    }
    else if (strzal<liczba)
    {
        printf("Za malo");
    }
    else if (strzal>liczba)
    {
        printf("Za duzo");}



    } while(strzal=liczba);


    return 0;
}

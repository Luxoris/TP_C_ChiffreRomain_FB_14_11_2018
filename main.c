/*PROGRAMME conversionChiffreRomain*/
//BUT Programme qui r�alise des conversions entre les chiffres romains et les chiffres d�cimaux
//ENTREE L'Entier correspondant au choix du menu, et l'entier correspondant au nombre decimal ou la chaine correspondant au nombre romain.
//SORTIE L'Entier convertit ou la chaine convertit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_CHAINE 256
#define TAILLE_TABLEAU 7

//EMPREINTES DES PROCEDURE ET FONCTIONS
void pcdDecimalVersRomain();
void pcd_ajoutCar(char sString[TAILLE_CHAINE],char cChar);
void pcdRomainVersDecimal();

//PROGRAMME PRINCIPAL
//*****************************************************************************************************//
//
// DESCRIPTION: Contient la boucle de saisie et le menu qui permet � l'utilisateur d'appeler les proc�dures de conversion Romain vers Decimal
//      et D�cimal vers Romain. Permet aussi de quitter.
//
// ENTREE   Un entier correspondant au choix du menu.
//
// SORTIE
//
// NOTE (Le programme se r�p�te tant que l'utilisateur ne saisie pas 0 pour quitter le programme.)
//
//*****************************************************************************************************//
int main()
{
    int nChoix=0;
    do{
        printf("\nProgramme Romain\n 1: Convertion decimal vers Romain \n 2: Convertion Romain vers decimal \n 0: Pour Quitter \n"); //de 1 � 399
        scanf("%d",&nChoix);
        fflush(stdin);
        switch (nChoix){
        case 1: pcdDecimalVersRomain(); break;
        case 2: pcdRomainVersDecimal(); break;
        }
    }while(nChoix!=0);
    return 0;
}


//IMPLENTATION DES FONCTIONS

//PROCEDURE ajoutCaractere
//*****************************************************************************************************//
//
// DESCRIPTION  Procedure qui ajoute un caract�re � la fin d'une chaine de caractere.
//
// ENTREE La chaine � modifier et le caract�re � ajouter.
//
// SORTIE La chaine modifier.
//
// NOTE
//
//*****************************************************************************************************//
void pcd_ajoutCar(char sString[TAILLE_CHAINE],char cChar){
    int i=0;
    while (sString[i]!='\0'){
        i++;
    }
    sString[i]=cChar;
    sString[i+1]='\0';
}

//Impl�mentation des fonctions


//PROCEDURE DecimalVersRomain
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui demande � un utilisateur le nombre d�cimal � convertir en nombre romain, et r�alise la conversion.
//
// ENTREE   Un entier
//
// SORTIE   Une chaine de caract�re correspondant � l'�criture en chiffre romain de l'entier en entr�e
//
// NOTE (Attend un entier en param�tre entre 1 et 3999).
//
//*****************************************************************************************************//
void pcdDecimalVersRomain(){
    //DECLARAION DES VARAIBLES
    char cStrRomain[TAILLE_CHAINE],cTabCorrespondances[TAILLE_TABLEAU] = {'I','V','X','L','C','D','M'};
    int nDecimalTraitement=0,nDecimal=0,nCompteur = (TAILLE_TABLEAU-1),nMemCompteur=0,nTabVal[TAILLE_TABLEAU]= {1,5,10,50,100,500,1000};

    //ENTREE
    printf("Entrez le nombre decimal a convertir en chiffre Romain : \n");
    scanf("%d",&nDecimal);

    //TRAITEMENT
    nDecimalTraitement = nDecimal;
        //INITITALISATION de la chaine
    cStrRomain[0]='\0';
    do{
        if((nDecimalTraitement /(nTabVal[nCompteur]))>0){
            pcd_ajoutCar(cStrRomain,cTabCorrespondances[nCompteur]);
            nDecimalTraitement -= nTabVal[nCompteur];
        }else
            {
                if((nCompteur%2)==0){
                    nMemCompteur=nCompteur-2;
                }else{
                    nMemCompteur=nCompteur-1;
                }
                if((nDecimalTraitement)>=((nTabVal[nCompteur])-(nTabVal[nMemCompteur]))){
                    pcd_ajoutCar(cStrRomain,cTabCorrespondances[(nMemCompteur)]);
                    nDecimalTraitement += nTabVal[(nMemCompteur)];
                    pcd_ajoutCar(cStrRomain,cTabCorrespondances[(nCompteur)]);
                    nDecimalTraitement -= nTabVal[nCompteur];
                }else{
                    nCompteur--;
                }
            }

    }while (nDecimalTraitement > 0);

    //AFFICHAGE
    printf("Le nombre romain correspondant a %d est %s.",nDecimal,cStrRomain);

}


//PROCEDURE RomainVersDecimal
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui demande � un utilisateur le nombre romain � convertir en nombre d�cimal, et r�alise la conversion.
//
// ENTREE   Une chaine de caract�re correspondant au chiffre romain.
//
// SORTIE   Un nombre qui correspond
//
// NOTE (Le programme renvoie la valeur de 0 si la chaine entr�e ne contient aucun carract�re).
//
//*****************************************************************************************************//
void pcdRomainVersDecimal(){

    char cStrRomain[TAILLE_CHAINE],cTabCorrespondances[TAILLE_TABLEAU] = {'I','V','X','L','C','D','M'};
    int nDecimal=0,nCompteur = 0, nIndex = (TAILLE_TABLEAU-1),nIndexPrecedent=0,nTabVal[TAILLE_TABLEAU]= {1,5,10,50,100,500,1000};

    //initialisation des variables
    nIndexPrecedent = nIndex; //initialisation de l'index pr�cedent avec une valeur �gale � l'index importante pour le 1er caract�re de la chaine

    //ENTREE
    printf("Quel est le nombre romain a traduire en decimal ? \n");
    scanf("%s",cStrRomain);


    //TRAITEMENT

    //tantque pour �viter que le programme ne crash en cas d'entr�e vide
    while(((nCompteur) < (strlen(cStrRomain))) && (nIndex >=0)){      // Index>0 pour sortir de la procedure si la chaine contient un caracter invalide
        if(cTabCorrespondances[nIndex] == cStrRomain[nCompteur]){
           if(nIndexPrecedent<nIndex){
                nDecimal = nDecimal + nTabVal[nIndex] - (2* nTabVal[nIndexPrecedent]);
            }else{
                nDecimal = nDecimal + nTabVal[nIndex];
            }
            nIndexPrecedent = nIndex;    //sauvegarde de la valeur de l'index dans nIndexPrecedent
            nCompteur++; // la lettre suivante est test�
            nIndex = (TAILLE_TABLEAU-1);  //l'index repart du d�but
        }else{
            nIndex--;
        }
    }

    //AFFICHAGE

    printf("Le nombre %s vaut : %d en nombre decimal.",cStrRomain,nDecimal);
}

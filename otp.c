#include<stdio.h>
#include<string.h>
#include<ctype.h>

main(int argc, char *argv[])
{
    //Jegliche Eingaben werden in Großbuchstaben convertiert 
    //und Leerzeilen werden entfernt.
    int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];
    char str[100],key[100],cipher[100];
    printf("Bitte geben Sie den zu verschlüsselnden Text ein\n");
    gets(str);
    for(i=0,j=0;i<strlen(str);i++) {
        if(str[i]!=' ') {
             str[j]=toupper(str[i]);   //toupper ist eine C interne Funktion
             j++;                      //die hier anhand einer For-Schleife
        }                              //die Eingaben in Großbuchstaben umschreibt
    }
    str[j]='\0';
    //Erhalt des Klartextes (nummerisch)
    for(i=0;i<strlen(str);i++) {
       numstr[i]=str[i]-'A';    
    }   
    printf("Bitte einen Zufälligen Text eingeben(Länge beliebig)\n");
    gets(key);
    for(i=0,j=0;i<strlen(key);i++) {
        if(key[i]!=' ') {
            key[j]=toupper(key[i]);   
            j++;
        }
    }
    key[j]='\0';
    //Erhalt des OTP bzw. Key
    for(i=0;i<strlen(key);i++) {
        numkey[i]=key[i]-'A';    
    }  

    for(i=0;i<strlen(str);i++) {
        numcipher[i]=numstr[i]+numkey[i];
    }
   
    for(i=0;i<strlen(str);i++) {
        if(numcipher[i]>25) {
           numcipher[i]=numcipher[i]-26;
        }
    }
    printf("Der One Time Pad Ciphertext ist\n");
    for(i=0;i<strlen(str);i++) {
        printf("%c",(numcipher[i]+'A')); 
    }
    printf("\n");

}

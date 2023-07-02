#include<stdio.h>
#include<string.h>

//Creating Admin's Account
void Admin()
{
    struct AdminAccount
    {
        char username[50];
        char password[50];
    };
    struct AdminAccount ad;

    char username[50];
    char password[50];

    printf("-----You are Admin-----\n");

    printf("\nEnter your username: ");
    fflush(stdin);
    gets(ad.username);
    printf("Enter password: ");
    fflush(stdin);
    gets(ad.password);

    FILE *adm;
    adm=fopen("myadmin.txt","a");
    fwrite(&ad,sizeof(ad),1,adm);
    printf("\nAccount Created Successfully...!\n");
    fclose(adm);
}
int main()
{
    Admin();
    return 0;
}

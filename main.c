#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure for storing user informations
struct login{
    char first_name[30];
    char last_name[30];
    char username[30];
    char password[20];
    char mail_id[30];
}w[99];

//Function prototypes
void login (void);
void registration (void);

//Main Function
int main(){

//Temporory variables for validations and storing informations while execution
int option, n;

system("clear"); //Executing system command 'clear' to clear the screen.
printf("\n\n\n\n\n\t\t\t\t[+] WELCOME [+]");
printf("\n\t\t\t\t=====================");
printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
if(getchar()==13){
    system("clear");
}
XY: // Goto for retrying the selection
printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&option);

//Switch for checking the user input and to call functions accordingly
switch(option)
  {
    case 1: system("clear");
        login();
        break;
    case 2: system("clear");
        registration();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if(getchar()==13)
        system("clear");
        goto XY;
  }
  return 0;
}

//Function for checking login credentials
void login (void){
    
    FILE *log;
    char c,e,name[30],pass[30];
    int z=0, checku, checkp;
    log = fopen("login.txt", "rb");
    printf("\n\n\t\t\t===================================");
    printf("\n\n\t\t\t[+] Welcome to the Login zone!");
    printf("\n\n\t\t\t===================================");
    for(int i=0; i<1000; i++){
        printf("\n\n\t\t\t[+] Enter Username: ");
        scanf("%s", name);
        printf("\n\t\t\t[+]  Enter Password: ");
        scanf("%s", pass);
        
        //checking wheather the username and password are valid or not.
        while(!feof(log)){
            fread(&w[i], sizeof(w[i]), 1, log);
            checku=strcmp(name, w[i].username); //Comparing user inputted username with the username in the structure
            checkp=strcmp(pass, w[i].password); //Comparing user inputted password with the password in the structure
                if(checku==0 && checkp==0){ //If statement is executed if the username and password are valid
                    system("clear");
                    printf("\n\n\t======================================================================================");
                    printf("\n\n\tYou have logged in successfully!!\t Welcome on board, Have a nice day ahead");
                    ;printf("\n\n\t[+] User details");
                    printf("\n\n\t[+] First Name: %s\t [+] Last Name: %s", w[i].first_name, w[i].last_name);
                    printf("\n\n\t[+] User Email: %s", w[i].mail_id);
                    printf("\n\n\t======================================================================================\n");
                    break;
                }
                else if(checku==0 && checkp!=0){ // Else if is executed if the password is wrong.
                    printf("\n\n\n\t\t\t[+] Wrong Password! Not %s??", name);
                    printf("\n\n\n\t\t\t[+] Press 'Y' to re-login: ");
                    scanf("%s", &e);
                    if(e=='Y' || e=='y'){
                        system("clear");
                        login();
                    }
                }
                else if(checku!=0){ // Else is executed if the user entered username is not available in the structure
                    printf("\n\n\t\t[+] You are not a Registered User! Press 'Y' to register yourself: ");
                    scanf("%s", &e);
                    if(e=='Y' || e=='y'){
                        system("clear");
                        registration(); //Calling registration function for resitering again.
                    }
                }
                
        }
        break;

    }
    getchar();
}

//registration function for regitering new user
void registration(void){

    FILE *log;
    char c,checker[30];
    int z=0;
    int n;
    log=fopen("login.txt", "ab+"); //opening the file containing user details
    printf("\n\n\t\t\t======================================");
    printf("\n\n\t\t\t[+] Welcome to the registration zone!");
    printf("\n\n\t\t\t======================================");
    for(int i=0; i<100;i++){
        printf("\n\n\t\t\t[+] Enter Username: ");
        scanf("%s", checker);
            //Checking wheather the username already exists or not.
            while(!feof(log)){
                fread(&w[i], sizeof(w[i]), 1, log);
                if(strcmp(checker, w[i].username)==0){
                    printf("\n\n\t\tUsername already exists!");
                    registration();
                }
                else{
                    strcpy(w[i].username,checker);
                    break;
                }
            }
        //Collecting other details of the user
        printf("\n\n\t\t\t [+] Enter First name: ");
        scanf("%s", &w[i].first_name);
        printf("\n\n\t\t\t [+] Enter last name: ");
        scanf("%s", &w[i].last_name);
        printf("\n\n\t\t\t [+] Enter Mail ID: ");
        scanf("%s", &w[i].mail_id);
        printf("\n\n\t\t\t [+] Enter a password for you account: ");
        scanf("%s", &w[i].password);
        //Printing all details to file
        fwrite(&w[i],sizeof(w[i]), 1, log);
        fclose(log);
        printf("\n\n\t[+] Press enter if you agree with Username and Password");
        if((c=getchar())=='\n'){
            system("clear");
            printf("\n\n\t\t[+] You are successfully registered");
            printf("\n\n\t\tTry login your account??\n\n\t\t  ");
            //Asking the user wheather to try sign-in or not.
            printf("[+] PRESS 1 FOR YES\n\n\t\t  [+] PRESS 2 FOR NO\n\n\t\t\t\t: ");
            scanf("%d", &n);
            //switch for cheking the user input and redirect accordingly
            switch(n){
                case 1: system("clear");
                    login();
                    break;
                case 2: system("clear");
                    printf("\n\n\n\t\t\t\t\t[+] Thank you for registering!");
                    break;
            }
        }
        break;

    }
    getchar();

}
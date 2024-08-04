#include <stdio.h>
#include <string.h>
#include <time.h> // header file to use time function

//eSpeak is a speech synthesizer used for speech outputs

void wishme()
{
    time_t now = time(0);
    struct tm *timeinfo = localtime(&now);

    //Wishing the user according to local time
    if (timeinfo->tm_hour < 12)
    {
        printf("Good Morning sir\n");
        system("espeak \"Good Morning sir\"");
    }
    else if (timeinfo->tm_hour >= 12 && timeinfo->tm_hour <= 16)
    {
        printf("Good Afternoon sir\n");
        system("espeak \"Good Afternoon sir\"");
    }
    else if (timeinfo->tm_hour > 16 && timeinfo->tm_hour < 24)
    {
        printf("Good Evening sir\n");
        system("espeak \"Good Evening sir\"");
    }
}


void datetime()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    printf("The date and time is:\n%s\n", dt);
}


//We are saving the inputs that our programme couldn't uderstand for future use
void storeInvalidInput(const char *input)         
{
    FILE *file = fopen("invalid_inputs.txt", "a");

    if (file != NULL)
    {
        fprintf(file, "%s\n", input);
        fclose(file);
    }
    else
    {
        printf("Error opening the file for writing.\n");
    }
}



int main()
{
    system("cls");

    printf("\t\t\t<===========================================  W E L C O M E  =============================================>\n");
    printf("\t\t\t<=======================================  I'M A VIRTUAL ASSISTANT  =======================================>\n");
    printf("\t\t\t<==========================================  MY NAME IS ENIGMA  ==========================================>\n");
    printf("\t\t\t<=========================================  I'M HERE TO HELP YOU  ========================================>\n\n");

    char password[20];
    char ch[100];

    do
    {
        printf("=======================\n");
        printf("| ENTER YOUR PASSWORD |\n");
        printf("=======================\n\n");
        system("espeak \"Enter your password\"");
        printf(">>");

        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        if (strcmp(password, "open") == 0)     //checking for correct password
        {
            printf("\n<==================================================================================================>\n\n");
            wishme();
            do
            {
                printf("\n<==================================================================================================>\n\n");
                printf("\nHow can I help you ....\n\n");
                system("espeak \"How can I help you \"");

                printf("Your query ===> ");
                fgets(ch, sizeof(ch), stdin);
                ch[strcspn(ch, "\n")] = '\0';
                printf("\nHere is the result for your query ===> ");

                //Greetings and introduction
                if (strcmp(ch, "hi") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0)
                {
                    printf("Hello Sir.....\n");
                    system("espeak \"Hello sir\"");
                }
               
                else if (strcmp(ch, "who are you") == 0 || strcmp(ch, "tell me about yourself")== 0 || strcmp(ch, "about") == 0)
                {
                    printf("I'm a virtual assistant created by my master soul mortals !!!\n");
                    system("espeak \"I am a virtual assistant created by my master soul mortals\"");
                }
                else if (strcmp(ch, "how are you") == 0 || strcmp(ch, "whatsup") == 0 || strcmp(ch, "how is your day") == 0)
                {
                    printf("I'm good sir, tell me how can I help you..\n");
                    system("espeak \"I'm good sir, tell me how can I help you\"");
                }
                else if (strstr(ch, " time") != NULL || strstr(ch, " date") != NULL)
                {
                    datetime();
                }


                //exiting the programme on command 
                 else if (strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0)
                {
                    printf("Good Bye sir, have a nice day!!!!\n");
                    system("espeak \"Good Bye sir, have a nice day\"");
                    return 0;                       
                }
                

                //taking and resolving the queries 
                else if (strstr(ch, "youtube") != NULL)
                {
                    printf("Opening YouTube.....\n");
                    system("espeak \"Opening YouTube\"");

                    // Wait for the user to press enter and read the full query
                    printf("Enter your query: ");
                    fgets(ch, sizeof(ch), stdin);
                    ch[strcspn(ch, "\n")] = '\0';

                    // Generate the command to open YouTube with the query appended to the URL
                    char command[200];
                    sprintf(command, "start https://www.youtube.com/results?search_query=%s", ch);
                    system(command);
                }

                else if (strstr(ch, "wikipedia") != NULL)
                {
                    printf("Opening Wikipedia.....\n");
                    system("espeak \"Opening Wikipedia\"");

                    // Wait for the user to press enter and read the full query
                    printf("Enter your query: ");
                    fgets(ch, sizeof(ch), stdin);
                    ch[strcspn(ch, "\n")] = '\0';

                    // Generate the command to open Wikipedia with the query appended to the URL
                    char command[200];
                    sprintf(command, "start https://www.wikipedia.org/wiki/%s", ch);
                    system(command);
                }

                else if (strstr(ch, "google") != NULL)
                {
                    printf("Opening google.....\n");
                    system("espeak \"Opening google\"");

                    // Wait for the user to press enter and read the full query
                    printf("Enter your query: ");
                    fgets(ch, sizeof(ch), stdin);
                    ch[strcspn(ch, "\n")] = '\0';

                    // Generate the command to open Wikipedia with the query appended to the URL
                    char command[200];
                    sprintf(command, "start https://www.google.com/search?q=%s", ch);
                    system(command);
                }

                else if (strstr(ch, "instagram") != NULL)
                {
                    printf("Opening Instagram.....\n");
                    system("espeak \"Opening Instagram\"");

                    // Wait for the user to press enter and read the full query
                    printf("Enter your query: ");
                    fgets(ch, sizeof(ch), stdin);
                    ch[strcspn(ch, "\n")] = '\0';

                    // Generate the command to open the Instagram profile
                    char command[200];
                    sprintf(command, "start https://www.instagram.com/%s", ch);
                    system(command);
                }

                else if (strstr(ch, "facebook") != NULL)
                {
                    printf("Opening Facebook.....\n");
                    system("espeak \"Opening Facebook\"");

                    // Wait for the user to press enter and read the full query
                    printf("Enter your query: ");
                    fgets(ch, sizeof(ch), stdin);
                    ch[strcspn(ch, "\n")] = '\0';

                    // Generate the command to open the Facebook profile
                    char command[200];
                    sprintf(command, "start https://www.facebook.com/%s", ch);
                    system(command);
                }

                else if (strstr(ch, "chatgpt") != NULL)
                {
                    printf("Opening ChatGPT.....\n");
                    system("espeak \"Opening ChatGPT\"");
                    system("start https://chat.openai.com");
                }

                else if (strstr(ch, "stackoverflow") != NULL)
                {
                    printf("Opening Stack Overflow.....\n");
                    system("espeak \"Opening Stack Overflow\"");
                    system("start https://www.stackoverflow.com");
                }

                else if (strcmp(ch, "open notepad") == 0)
                {
                    printf("Opening Notepad.....\n");
                    system("espeak \"Opening Notepad\"");
                    system("start notepad.exe");
                }


                else                               //this is for inputs or queries our programme can't handle 
                {
                    printf("Sorry, could not understand your query. Please try again!!!\n");
                    system("espeak \"Sorry, could not understand your query. Please try again\"");
                    storeInvalidInput(ch);
                }

            } while (1);
        }


        else                                      //in case the entered password is incorrect
        {
            system("cls");

            printf("\t\t\t<============================= W E L C O M E=============================>\n");
            printf("\t\t\t<============================= I'M VIRTUAL ASSISTANT =============================>\n");
            printf("\t\t\t<============================= MY NAME IS ENIGMA =============================>\n");
            printf("\t\t\t<============================= I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =============================>\n\n");

            printf("=======================\n");
            printf("X Incorrect Password X\n");
            printf("=======================\n\n");
            system("espeak \"Incorrect Password, Please enter correct password\"");
        }
    } while (1);


    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxInputs 12
#define maxLength 128


int main(int argc, char **argv){
    char command[32];
    char filename[32];
    char description[256];
    int num_examples, num_resources, i;
    char example_description[maxInputs][maxLength];
    char example_code[maxInputs][maxLength];
    char resource_name[maxInputs][maxLength];
    char resource_url[maxInputs][maxLength];




    printf("\nWelcome to TLDRer\n\n");
    if(argc > 1){
        strncpy(command, argv[1], 32);
        printf("Using command <%s>\n", command);
        if(argc > 2){
            strncpy(filename, argv[2], 32);
            printf("Using file name <%s>\n", filename);
        }
    }else{
        printf("Command name: ");
        fgets(command, 32, stdin);
        command[strlen(command) - 1] = '\0';
    }
    if(argc < 3){
        printf("Destination file: ");
        fgets(filename, 32, stdin);
        filename[strlen(filename) - 1] = '\0';
    }

    printf("\nDescription: ");
    fgets(description, 256, stdin);
    description[strlen(description) - 1] = '\0';

    printf("\nHow many examples would you like to give? ");
    scanf("%d", &num_examples);


    for(i = 0; i < num_examples; i++){
        printf("Example %d description: ", i + 1);
        getchar();
        fgets(example_description[i], maxLength, stdin);
        example_description[i][strlen(example_description[i]) - 1] = '\0';
        printf("Example %d code: ", i + 1);
        fgets(example_code[i], maxLength, stdin);
        example_code[i][strlen(example_code[i]) - 1] = '\0';
    }

    printf("\nHow many resources would you like to give? ");
    scanf("%d", &num_resources);
    for(i = 0; i < num_resources; i++){
        printf("Resource %d name: ", i + 1);
        getchar();
        fgets(resource_name[i], maxLength, stdin);
        resource_name[i][strlen(resource_name[i]) - 1] = '\0';
        printf("Resouce %d url: ", i + 1);
        fgets(resource_url[i], maxLength, stdin);
        resource_url[i][strlen(resource_url[i]) - 1] = '\0';
    }

    FILE *fp;
    if((fp = fopen(filename, "ab+")) != NULL){
      fprintf(fp, "TLDR - %s\n=======", command);
      for (int i = 0; i < (int)strlen(command); ++i) { // underline whole title
        fprintf(fp, "=");
      }
      fprintf(fp, "\n\nOverview\n--------\n\n%s\n\nExamples\n--------\n\n", description);
        for(i = 0; i < num_examples; i++){
            fprintf(fp, "- %s\n\n    $%s\n\n", example_description[i], example_code[i]);
        }
        fprintf(fp, "Resources\n---------\n\n");
        for(i = 0; i < num_resources; i++){
            fprintf(fp, "- [%s](%s)\n", resource_name[i], resource_url[i]);
        }

    }
    printf("\n\n");
    fclose(fp);

    return 0;
}

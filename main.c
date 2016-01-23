#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char command[32];
    char filename[32];
    char description[256];
    int num_examples, num_resources, i;
    char example_description[12][128];
    char example_code[12][128];
    char resource_name[12][128];
    char resource_url[12][128];
    if(argc > 1){
        strncpy(command, argv[1], 32);
        command[strlen(command)] = '\0';
        printf("Using command <%s>\n", command);
        if(argc > 2){
            strncpy(filename, argv[2], 32);
            filename[strlen(filename)] = '\0';
            printf("Using file name <%s>\n", filename);
        }
    }else{
        printf("Command: ");
        fgets(command, 32, stdin);
        command[strlen(command)] = '\0';
    }
    if(argc < 3){
        printf("Destination file: ");
        fgets(filename, 32, stdin);
        filename[strlen(filename)] = '\0';
    }

    printf("\nDescription: ");
    fgets(description, 256, stdin);
    description[strlen(description) - 1] = '\0';

    printf("\nHow many examples would you like to give? ");
    scanf("%d", &num_examples);
    for(i = 0; i < num_examples; i++){
        printf("Example %d description: ", i);
        getchar();
        fgets(example_description[i], 128, stdin);
        example_description[i][strlen(example_description[i]) - 1] = '\0';
        printf("Example %d code: ", i);
        fgets(example_code[i], 128, stdin);
        example_code[i][strlen(example_code[i]) - 1] = '\0';
    }

    printf("\nHow many resources would you like to give? ");
    scanf("%d", &num_resources);
    for(i = 0; i < num_resources; i++){
        printf("Resource %d name: ", i);
        getchar();
        fgets(resource_name[i], 128, stdin);
        resource_name[i][strlen(resource_name[i]) - 1] = '\0';
        printf("Resouce %d url: ", i);
        fgets(resource_url[i], 128, stdin);
        resource_url[i][strlen(resource_url[i]) - 1] = '\0';
    }
    
    FILE *fp;
    if(fp = fopen(filename, "ab+")){
        fprintf(fp, "TLDR - %s\n=====\n\nOverview\n--------\n\n%s\n\nExamples\n--------\n\n", command, description);
        for(i = 0; i < num_examples; i++){
            fprintf(fp, "- %s\n\n    %s\n\n", example_description[i], example_code[i]);
        }
        fprintf(fp, "Resources\n---------\n\n");
        for(i = 0; i < num_resources; i++){
            fprintf(fp, "- [%s](%s)", resource_name[i], resource_url[i]);
        }
                    
    }

    return 0;
}

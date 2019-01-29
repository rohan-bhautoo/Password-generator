#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define BUF_SIZE ( 500 )  //setting a temporary storage of capacity 500

char *get_file4( FILE *file4, int line_no )
{
    file4 = fopen("4", "r"); //Opens file 4 and reads it only
    char buf[ BUF_SIZE ]; // temporary storage
    size_t curr_alloc = BUF_SIZE, curr_ofs = 0;
    /*size_t is an unsigned type and cannot be < 0. It can also hold any
    array index. curr_alloc is the size of memory block in bytes. current_ofs is
    the ofstream object*/
    char *line1 = malloc( BUF_SIZE );
    /*malloc() is dynamic memory allocation. It allocates the requested memory(BUF_SIZE)
    and returns a pointer(line) to it.*/
    int in_line = line_no == 1; //line starts at 1
    size_t bytes_read;

    //Checking for errors
    if ( line_no < 1 )
        return NULL;

    //Handle out-of-memory by returning NULL
    if ( !line1 )
        return NULL;

    /*fread() function reads data from file into the pointed array(buf)
    where 1 is the size in bytes of each element to be read.*/
    while ( line_no && ( bytes_read = fread( buf, 1, BUF_SIZE, file4 ) ) > 0 )
    {
        int i;

        for ( i = 0 ; i < bytes_read ; i++ )
        {
            if ( in_line )
            {
                if ( curr_ofs >= curr_alloc )
                {
                    //left shift the binary to the left by 1, replaces trailing zeros by 0
                    curr_alloc <<= 1;
                    line1 = realloc( line1, curr_alloc );
                    /*realloc() function attempts to resize the memory block pointer that
                    was previously allocated with a call to malloc(). curr_alloc is the new size for memory block in bytes.*/

                    //out of memory!
                    if ( !line1 )
                        return NULL;
                }
                line1[ curr_ofs++ ] = buf[i];
            }
            //Scan the file looking for newlines.
            if ( buf[i] == '\n' )
            {
                line_no--;

                if ( line_no == 1 )
                    in_line = 1;

                if ( line_no == 0 )
                    break;
            }
        }
    }

    //Didn't read the line
    if ( line_no != 0 )
    {
        free( line1 );
        return NULL;
    }

    /*Resize allocated buffer to what is needed by the string and the terminating NULL character.
    It keeps terminating newline as part of the string*/
    line1 = realloc( line1, curr_ofs + 1 );

    //out of memory
    if ( !line1 )
        return NULL;

    //add terminating null
    line1[ curr_ofs ] = '\0';

    /* Return the line.  Caller is responsible for freeing it. */
    return line1;

    //closes file 4
    fclose(file4);
}

char *get_file5( FILE *file5, int line_no )
{
    file5 = fopen("5", "r"); //Opens file 5 and reads it only
    char buf[ BUF_SIZE ]; // temporary storage
    size_t curr_alloc = BUF_SIZE, curr_ofs = 0;
    /*size_t is an unsigned type and cannot be < 0. It can also hold any
    array index. curr_alloc is the size of memory block in bytes. current_ofs is
    the ofstream object*/
    char *line2 = malloc( BUF_SIZE );
    /*malloc() is dynamic memory allocation. It allocates the requested memory(BUF_SIZE)
    and returns a pointer(line) to it.*/
    int in_line = line_no == 1; //line starts at 1
    size_t bytes_read;

    //Checking for errors
    if ( line_no < 1 )
        return NULL;

    //Handle out-of-memory by returning NULL
    if ( !line2 )
        return NULL;

    /*fread() function reads data from file into the pointed array(buf)
    where 1 is the size in bytes of each element to be read.*/
    while ( line_no && ( bytes_read = fread( buf, 1, BUF_SIZE, file5 ) ) > 0 )
    {
        int i;

        for ( i = 0 ; i < bytes_read ; i++ )
        {
            if ( in_line )
            {
                if ( curr_ofs >= curr_alloc )
                {
                    //left shift the binary to the left by 1, replaces trailing zeros by 0
                    curr_alloc <<= 1;
                    line2 = realloc( line2, curr_alloc );
                    /*realloc() function attempts to resize the memory block pointer that
                    was previously allocated with a call to malloc(). curr_alloc is the new size for memory block in bytes.*/

                    //out of memory!
                    if ( !line2 )
                        return NULL;
                }
                line2[ curr_ofs++ ] = buf[i];
            }
            //Scan the file looking for newlines.
            if ( buf[i] == '\n' )
            {
                line_no--;

                if ( line_no == 1 )
                    in_line = 1;

                if ( line_no == 0 )
                    break;
            }
        }
    }

    //Didn't read the line
    if ( line_no != 0 )
    {
        free( line2 );
        return NULL;
    }

    /*Resize allocated buffer to what is needed by the string and the terminating NULL character.
    It keeps terminating newline as part of the string*/
    line2 = realloc( line2, curr_ofs + 1 );

    //out of memory
    if ( !line2 )
        return NULL;

    //add terminating null
    line2[ curr_ofs ] = '\0';

    // Return the line.
    return line2;

    //closes file 5
    fclose(file5);
}

char *get_file6( FILE *file6, int line_no )
{
    file6 = fopen("6", "r"); //Opens file 6 and reads it only
    char buf[ BUF_SIZE ]; // temporary storage
    size_t curr_alloc = BUF_SIZE, curr_ofs = 0;
    /*size_t is an unsigned type and cannot be < 0. It can also hold any
    array index. curr_alloc is the size of memory block in bytes. current_ofs is
    the ofstream object*/
    char *line3 = malloc( BUF_SIZE );
    /*malloc() is dynamic memory allocation. It allocates the requested memory(BUF_SIZE)
    and returns a pointer(line) to it.*/
    int in_line = line_no == 1; //line starts at 1
    size_t bytes_read;

    //Checking for errors
    if ( line_no < 1 )
        return NULL;

    //Handle out-of-memory by returning NULL
    if ( !line3 )
        return NULL;

    /*fread() function reads data from file into the pointed array(buf)
    where 1 is the size in bytes of each element to be read.*/
    while ( line_no && ( bytes_read = fread( buf, 1, BUF_SIZE, file6) ) > 0 )
    {
        int i;

        for ( i = 0 ; i < bytes_read ; i++ )
        {
            if ( in_line )
            {
                //left shift the binary to the left by 1, replaces trailing zeros by 0
                if ( curr_ofs >= curr_alloc )
                {
                    curr_alloc <<= 1;
                    line3 = realloc( line3, curr_alloc );
                    /*realloc() function attempts to resize the memory block pointer that
                    was previously allocated with a call to malloc(). curr_alloc is the new size for memory block in bytes.*/

                    //out of memory!
                    if ( !line3 )
                        return NULL;
                }
                line3[ curr_ofs++ ] = buf[i];
            }

            //Scan the file looking for newlines.
            if ( buf[i] == '\n' )
            {
                line_no--;

                if ( line_no == 1 )
                    in_line = 1;

                if ( line_no == 0 )
                    break;
            }
        }
    }

    //Didn't read the line
    if ( line_no != 0 )
    {
        free( line3 );
        return NULL;
    }

     /*Resize allocated buffer to what is needed by the string and the terminating NULL character.
    It keeps terminating newline as part of the string*/
    line3 = realloc( line3, curr_ofs + 1 );

    //out of memory
    if ( !line3 )
        return NULL;

    //add terminating null
    line3[ curr_ofs ] = '\0';

    // Return the line
    return line3;

    //closes file 6
    fclose(file6);
}

char *get_file7( FILE *file7, int line_no )
{
    file7 = fopen("7", "r"); //Opens file 7 and reads it only
    char buf[ BUF_SIZE ]; // temporary storage
    size_t curr_alloc = BUF_SIZE, curr_ofs = 0;
    /*size_t is an unsigned type and cannot be < 0. It can also hold any
    array index. curr_alloc is the size of memory block in bytes. current_ofs is
    the ofstream object*/
    char *line4 = malloc( BUF_SIZE );
    /*malloc() is dynamic memory allocation. It allocates the requested memory(BUF_SIZE)
    and returns a pointer(line) to it.*/
    int in_line = line_no == 1; //line starts at 1
    size_t bytes_read;

    //Checking for errors
    if ( line_no < 1 )
        return NULL;

    //Handle out-of-memory by returning NULL
    if ( !line4 )
        return NULL;

    /*fread() function reads data from file into the pointed array(buf)
    where 1 is the size in bytes of each element to be read.*/
    while ( line_no && ( bytes_read = fread( buf, 1, BUF_SIZE, file7 ) ) > 0 )
    {
        int i;

        for ( i = 0 ; i < bytes_read ; i++ )
        {
            if ( in_line )
            {
                //left shift the binary to the left by 1, replaces trailing zeros by 0
                if ( curr_ofs >= curr_alloc )
                {
                    curr_alloc <<= 1;
                    line4 = realloc( line4, curr_alloc );
                    /*realloc() function attempts to resize the memory block pointer that
                    was previously allocated with a call to malloc(). curr_alloc is the new size for memory block in bytes.*/

                    //out of memory!
                    if ( !line4 )
                        return NULL;
                }
                line4[ curr_ofs++ ] = buf[i];
            }

            //Scan the file looking for newlines
            if ( buf[i] == '\n' )
            {
                line_no--;

                if ( line_no == 1 )
                    in_line = 1;

                if ( line_no == 0 )
                    break;
            }
        }
    }

    //Didn't read the line
    if ( line_no != 0 )
    {
        free( line4 );
        return NULL;
    }

    /*Resize allocated buffer to what is needed by the string and the terminating NULL character.
    It keeps terminating newline as part of the string*/
    line4 = realloc( line4, curr_ofs + 1 );

    //out of memory
    if ( !line4 )
        return NULL;

    //add terminating null
    line4[ curr_ofs ] = '\0';

    // Return the line
    return line4;

    //closes file 7
    fclose(file7);
}

//Testing program to return value in main.
int main()
{
    /*uses time from pc's clock by <time.h>
    It changes command of program constantly to make result unpredictable*/
    srand(time(NULL));

    //int variables
    int count;
    int i;
    int n = 1;
    int length;

    //char variable
    char password[100];
    /*memset copies the unassigned char in password
    to the first number of character in password. Resets the array each time the
    program run*/
    memset(password, 0, sizeof(password));

    printf("---------------------------------------------------------------\n");
    printf("\t\t\t    WELCOME\n");
    printf("---------------------------------------------------------------\n");

    //Prints the number of words
    printf("Enter number of words(from 2 to 5): ");
    //scanf reads and stores the value input by user
    scanf("%d", &count);
    printf("Generating password................\n");
    sleep(2);

    /*the if loop checks if the number entered by user at beginning is 0
    then it will print an error and restart the loop*/
    if(count == 0)
    {
        printf("\nInvalid Parameters! Please try again.\n\n");
        printf("Input from number 2 to number 5\n");
        printf("---------------------------------------------------------------");
        //Prints the number of words
        printf("\nEnter number of words(from 2 to 5): ");
        //scanf reads and stores the value input by user
        scanf("%d", &count);
        printf("Generating password..............\n");
        sleep(2);
    }

    /*Provides a continuous loop that help to generate the random line
    and is more efficient than using a while loop as it can increment the value
    for the number of count entered. The loop terminates when it reaches the number
    of counts entered by user*/
    for(i=0; i<count; i++)
    {
        /* randomize each line to print
        different values each time the program is run*/
        int random1 = rand() % 500;
        int random2 = rand() % 500;
        int random3 = rand() % 500;
        int random4 = rand() % 500;

        //char variables to take random input
        char *line1 = get_file4(stdin, random1);
        char *line2 = get_file5(stdin, random2);
        char *line3 = get_file6(stdin, random3);
        char *line4 = get_file7(stdin, random4);

        /*while loop to check if number is less than 2 or greater than 5.
        If less than 2 or greater than 5, it returns error and restart the loop*/
        while(count == 0 || count < 2 || count > 5)
        {
            //checks if the input by user is numeric, else it will return an error
            if(!isdigit(count)) {
            printf("\nInvalid Parameters! Please try again.\n\n");
            printf("Input from number 2 to number 5\n");
            printf("---------------------------------------------------------------");
            //Prints the number of words
            printf("\nEnter number of words(from 2 to 5): ");
            //clears the output of buffer
            fflush(stdin);
            //scanf reads and stores the value input by user
            scanf("%d", &count);
            printf("Generating password..............\n");
            sleep(2);
            continue; //restart the loop
            }
        }
        //random file to print random password
        int randfile = rand() % 4;

        /*the switch chooses between the files and generate
        a random line*/
        switch(randfile)
        {
            case 0:
                sleep(2);
                printf("%d %s", n, line1); //print number and random line
                strcat(password, line1); //append the printed line 1 to password
                n++; // increment line
                break;

            case 1:
                sleep(2);
                printf("%d %s", n, line2); //print number and random line
                strcat(password, line2); //append the printed line 2 to password
                n++; // increment line
                break;

            case 2:
                sleep(2);
                printf("%d %s", n, line3); //print number and random line
                strcat(password, line3); //append the printed line 3 to password
                n++; // increment line
                break;

            case 3:
                sleep(2);
                printf("%d %s", n, line4); //print number and random line
                strcat(password, line4); //append the printed line 4 to password
                n++; // increment line
                break;
        }
    } //end of for loop

    /*'\0' is the end of string
    the for loop prints a dash(-) at the end of each string*/
    for(i=0; password[i]!='\0'; i++)
    {
        if(password[i] == '\n')
        {
            password[i] = '-';
        }
    }
    /*strlen() computes the length of password up to, but not including
    the terminating null character*/
    length = strlen(password); //get length of string
    password[length - 1] = '\0'; //set next to last char to null to remove extra -
    sleep(1);
    printf("Your e-t-r password is: %s", password);

    printf("\n---------------------------------------------------------------\n");
    printf("\t\t        Easy-to-remember\n");
    printf("\t\t       Password-generator\n");
    printf("\t\t               By\n");
    printf("\t\t         BHAUTOO ROHAN\n");
    printf("---------------------------------------------------------------\n");

    return 0;
} //End of main

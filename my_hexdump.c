/* Including libraries needed to run the code. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

/* Including relevant definitions. */
#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16
 
 
void my_hexdump (char* programme_name, char * filename);
 
/* Clear the display.  */
void clear_line (char *line, int size);
 
/* Put characters into hex format. */
char * hex   (char *position, int c);
 
/* Put characters into ASCII format. */
char * ascii (char *position, int c);
 
 /* Setting up the main function of the program */
int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("\n\t%s syntax:\n\n", argv[0]);
        printf("\t\t%s filename\n\n", argv[0]);
        exit(0);
    }
 
    my_hexdump( argv[0], argv[1]);
}
 
 
void my_hexdump(char* programme_name, char * filename)
{
    int c=' ';             /* Character to be read from the file */
    char * hex_offset;     /* Specifying position of the next character in hex.*/
    char * ascii_offset;   /* Specifying postion of the next character in ASCII.*/
    FILE *Pointer;             /* Pointer to the file.   */
    char line[81];  
 
    /* Opening file to be hexdumped*/
    Pointer = fopen(filename,"r");
        /* Opening file to be hexdumped*/
    if ( ferror(Pointer) )
    {
        printf("\n\t%s: Unable to open %s\n\n", programme_name, filename);
        exit(0);
    }
 
    printf("\n\tHex dump of %s\n\n", filename);
 
    while (c != EOF )
    {
        clear_line(line, sizeof line);
        hex_offset   = line+HEX_OFFSET;
        ascii_offset = line+ASCII_OFFSET;
 
        while ( ascii_offset < line+ASCII_OFFSET+NUM_CHARS
                &&(c = fgetc(Pointer)) != EOF  )
        {
            /* Build the hex part of
             * the line.      */
            hex_offset = hex(hex_offset, c);
 
            /* Build the Ascii part of
             * the line.      */
            ascii_offset = ascii(ascii_offset, c);
 
        }
        printf("%s\n", line);
    }
 
    fclose(Pointer);
}
 
void clear_line(char *line, int size)
{
    int count;
 
    for  (count=0; count < size; line[count]=' ', count++);
}
 
char * ascii(char *position, int c)
{
    /* If the character is NOT printable
     * replace it with a '.'  */
    if (!isprint(c)) c='.';
 
    sprintf(position, "%c", c);    /* Put the character to the line
                                    * so it can be displayed later */
 
    /* Return the position of the next
     * ASCII character.   */
    return(++position);
}
 
char * hex(char *position, int c)
{
    int offset=3;
 
    sprintf(position, "%02X ", (unsigned char) c);
 
    *(position+offset)=' ';   /* Remove the '/0' created by 'sprint'  */
 
    return (position+offset);
}

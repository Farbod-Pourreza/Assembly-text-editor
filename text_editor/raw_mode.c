
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct termios original_att;
void system_clear(){
    system("cls");
}
void set_terminal_raw_mode() {
    struct termios raw;
    tcgetattr(0 , &original_att);
    raw = original_att;
    cfmakeraw(&raw);
    tcsetattr(0 , TCSANOW , &raw);
}
void reset_terminal(){
    tcsetattr(0 , TCSANOW , &original_att);
}

void move_cursor_up(){
    putchar('\x1b');
    putchar('[');
    putchar('A');
}
void move_cursor_down(){
    putchar('\x1b');
    putchar('[');
    putchar('B');
}
void move_cursor_right(){
    putchar('\x1b');
    putchar('[');
    putchar('C');
}
void move_cursor_left(){
    putchar('\x1b');
    putchar('[');
    putchar('D');
}
void remove_chracter(){
    putchar('\b');
    putchar(' ');

}

// void file_up(char *input_buffer , int buffer_len){
//     char *ptr = input_buffer;
//     ptr = ptr + buffer_len;
//     while(ptr != input_buffer)
//     {
//         if (ptr == '\n')
//         {
//             return ptr;
//         }
//     }

// }
// void get_buffer_dimensions(char *input_buffer, int *rows, int *columns) {
//     *rows = 0;
//     *columns = 0;
//     int current_row_length = 0;

//     for (const char *ptr = input_buffer; *ptr != '\0'; ptr++) {
//         if (*ptr == '\n') {
//             (*rows)++;
//             if (current_row_length > *columns) {
//                 *columns = current_row_length;
//             }
//             current_row_length = 0;
//         } else {
//             current_row_length++;
//         }
//     }
//     printf("here");
//     if (current_row_length > 0) {
//         (*rows)++;
//         if (current_row_length > *columns) {
//             *columns = current_row_length;
//         }
//     }
// }
void *c_main(){
    set_terminal_raw_mode();
    int ch;
    while(1){
        ch=getchar();
        putchar(ch);
        if(ch == '\x1b'){
            char arrow1 = getchar();
            char arrow2 = getchar();
            if(arrow1 == '['){
                if(arrow2 == 'A')
                {
                    move_cursor_up();
                }
                else if(arrow2 == 'B')
                    move_cursor_down();
                else if(arrow2 == 'C')
                    move_cursor_right();
                else if(arrow2 == 'D')
                    move_cursor_left();    
            }
            else
                break;
        }
        if(ch == 26){
            break;
        }
        
    }
    reset_terminal();
}
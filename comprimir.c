#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comprimir.h"

void comprimir(char *str) {
    if (str == NULL || *str == '\0') {
        return;
    }
    
    char *read_ptr = str;
    char *write_ptr = str;
    
    while (*read_ptr != '\0') {
        char current_char = *read_ptr;
        int count = 1;
        
        // Count consecutive occurrences
        while (*(read_ptr + 1) == current_char) {
            count++;
            read_ptr++;
        }
        
        if (count == 1) {
            // Single character, just copy it
            *write_ptr = current_char;
            write_ptr++;
        } else {
            // Multiple characters, write count + character
            *write_ptr = '0' + count;
            write_ptr++;
            *write_ptr = current_char;
            write_ptr++;
        }
        
        read_ptr++;
    }
    
    *write_ptr = '\0';  // Null terminate
}

char *comprimido(char *str) {
    if (str == NULL || *str == '\0') {
        char *result = malloc(1);
        if (result != NULL) {
            *result = '\0';
        }
        return result;
    }
    
    
    // Calculate the size needed for compressed string
    char *ptr = str;
    int compressed_size = 0;
    
    while (*ptr != '\0') {
        char current_char = *ptr;
        int count = 1;
        
        // Count consecutive occurrences
        while (*(ptr + 1) == current_char) {
            count++;
            ptr++;
        }
        
        if (count == 1) {
            compressed_size += 1;  // Just the character
        } else {
            compressed_size += 2;  // Count digit + character
        }
        
        ptr++;
    }
    
    // Allocate exact memory needed
    char *result = malloc(compressed_size + 1);
    if (result == NULL) {
        return NULL;
    }
    
    // Build the compressed string
    ptr = str;
    char *write_ptr = result;
    
    while (*ptr != '\0') {
        char current_char = *ptr;
        int count = 1;
        
        // Count consecutive occurrences
        while (*(ptr + 1) == current_char) {
            count++;
            ptr++;
        }
        
        if (count == 1) {
            // Single character, just copy it
            *write_ptr = current_char;
            write_ptr++;
        } else {
            // Multiple characters, write count + character
            *write_ptr = '0' + count;
            write_ptr++;
            *write_ptr = current_char;
            write_ptr++;
        }
        
        ptr++;
    }
    
    *write_ptr = '\0';  // Null terminate
    return result;
}